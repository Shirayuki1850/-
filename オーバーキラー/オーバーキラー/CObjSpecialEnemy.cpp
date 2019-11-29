//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "CObjSpecialEnemy.h"

//使用するネームスペース
using namespace GameL;

//コントラクタ
CObjSpecialEnemy::CObjSpecialEnemy(float x, float y)
{
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjSpecialEnemy::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_hp = 5;	//HP

	m_posture = 1.0f;//右向き0.0f左1.0ｆ

	m_ani_time = 0;
	m_ani_frame = 1;//静止フレームを初期にする。

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション間隔幅

	m_move = true;//true=右　false=左

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	hit_flag = false;
	
	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ENEMY, OBJ_SPECIAL_ENEMY, 1);
}

//アクション
void CObjSpecialEnemy::Action()
{	

	//落下
	if (m_py > 1000.0f)
	{
		;
	}
	
	//通常速度
	m_speed_power = 0.5f;
	m_ani_max_time = 4;

	//ブロック衝突で向き変更
	if (m_hit_left == true)
	{
		m_move = true;
	}
	if (m_hit_right == true)
	{

		m_move = false;
	}

	//方向
	if (m_move == false)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (m_move == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}


	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{

		m_ani_frame = 0;

	}

	//摩擦
	m_vx += -(m_vx * 0.098);

	//自由落下運動
	m_vy += 9.8 / (16.0f);
	//ブロックタイプ検知用の変数がないためのダミー
	int d;
	//ブロックとの当たり判定実行
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);


	//位置の最新
	m_px += m_vx;
	m_py += m_vy;

	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero*h = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//HitBoxの位置の変更
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);



	/*//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);*/

	//弾丸と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//弾丸と接触していたらHPを減らす
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		if (hit_flag == false)
		{
			h->SetDamege(1);
			hit_flag = true;
			Audio::Start(5);
		}
	}
	else
	{
		if (hit_flag == true)
		{
			hit_flag = false;
		}
	}
	//HPが０になったら破壊
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//ドロー
void CObjSpecialEnemy::Draw()
{
	//描画情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置


	int AniData[4] =
	{
		1,0,2,0,
	};

	/*//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置*/

	//切り取り位置の設定
	src.m_top = 64.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 128;
	src.m_right = 128.0f + AniData[m_ani_frame] * 128;
	src.m_bottom = src.m_top + 192.0f;

	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f    *   m_posture) + m_px + block->GetScroll();
	dst.m_right = (64 - 64.0f *  m_posture) + m_px + block->GetScroll();
	dst.m_bottom = 96.0f + m_py;

	//描画
	Draw::Draw(2, &src, &dst, c, 0.0f);
}
