//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjHero.h"
#include "GameL\HitBoxManager.h"
#include "CobjBullet.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	m_px = 70.0f;//位置
	m_py = 64.0f;
	m_vx = 0.0f;//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;//右向き0.0f左1.0ｆ

	m_ani_time  = 0;
	m_ani_frame = 1;//静止フレームを初期にする。

	m_speed_power = 0.5f;//通常速度
    m_ani_max_time = 10;//アニメーション間隔幅

	

	//blockとの衝突状態確認用
	 m_hit_up     =  false;
	 m_hit_down   =  false;
	 m_hit_left   =  false;
	 m_hit_right  =  false;

	 m_block_type = 0;//踏んでいるBlockの種類を確認用

	 //当たり判定用のHitBoxを作成
	 Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
	 m_f = true;
}
//アクション
void CObjHero::Action()
{
	//落下によるゲームオーバー＆リスタート
	if (m_py > 1000.0f)
	{
		//場外に出たらリスタート。
		Scene::SetScene(new CSceneMain());
	}

	//↑キー入力でジャンプ
	if (Input::GetVKey(VK_UP) == true )
	{
		if (m_hit_down == true)
		{

			m_vy = -13;

		}



	}

	//SPACEキー入力で速度アップ
	if (Input::GetVKey('A') == true)
	{
       //ダッシュ時の速度
		m_speed_power = 0.8f;
		m_ani_max_time = 5;
	}
	else
	{
		//通常速度
		m_speed_power = 0.5f;
		m_ani_max_time = 10;

	}
	//主人公弾丸発射
	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{
			//弾丸オブジェクト作成
			CObjBullet*obj_b = new CObjBullet(m_px+50.0f, m_py+20.0f);	//弾丸オブジェクト作成
			Objs::InsertObj(obj_b, OBJ_BULLET, 1);	//作った弾丸オブジェクトマネージャーに登録
			m_f = false;
		}
	}
	else
	{
		m_f = true;
	}
	//キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 0;//キー入力がない場合は静止フレームにする
		m_ani_time =  0;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 2)
	{
		m_ani_frame = 0;
	}

	//摩擦
	m_vx += -(m_vx * 0.098);

	//自由落下運動
	m_vy += 9.8 / (16.0f);

	//高速移動によるBlock判定
	bool b;
	float pxx, pyy, r;
	CObjBlock*pbb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (pbb->GetScroll() > 0)
		pbb->SetScroll(0);

	//移動方向にレイを飛ばす
	float vx;
	if (m_vx > 0)
		vx = 500;
	else
		vx = -500;
//レイ判定
	b = pbb->HeroBlckCrossPoint(m_px - pbb->GetScroll() + 32, m_py + 32, m_vx * 100, m_vy * 100, &pxx, &pyy, &r);

	if (b == true)
	{
		px = pxx + pbb->GetScroll();
		py = pyy;

		float aa = (m_px)         -px;//  A(交点→主人公の位置)ベクトル      
		float bb = (m_px + m_vx) - px;//　B（交点→主人公の移動先位置）ベクトル

		//主人公の幅分のオフセット
		if (vx > 0)
			px += -64;
		else
			px += +2;

		//AとBが逆を向いている（主人公が移動先が壁を超える）
		if (aa*bb < 0)
		{
			//移動ベクトルを（交点→主人公の位置）ベクトルにする
			m_vx = px - m_px;

		}


	}
	else
	{

		px=0.0f  ;
		py = 0.0f;
	}


	//ブロックとの当たり判定実行
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);
	//自身のHitBoxをもってくる
	CHitBox*hit = Hits::GetHitBox(this);
	//敵と当たっているか確認
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
		//敵と接触したら削除
		if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			return;
		}
	{
		//主人公が敵とどの角度で当たっているかを確認
		HIT_DATA** hit_data;
		hit_data = hit->SearchObjNameHit(OBJ_ENEMY);
		for (int i = 0; i < hit->GetCount(); i++)
		{
			//敵の左右に当たったら
			float r = hit_data[i]->r;
				if ((r < 45 && r >= 0) || r > 315)
				{
					m_vx = -5.0f;//左に移動させる
				}
			if (r > 135 && r < 225)
			{
				m_vx = +5.0f;//右に移動させる
			}
			if (r >= 225 && r < 315)
			{
				//敵の移動方向を主人公の位置に加算
				m_px += ((CObjEnemy*)hit_data[i]->o)->GetVx();

				CObjBlock* b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
				//後方スクロールライン
				if (m_px < 80)
				{
					m_px > 300;
					b->SetScroll(b->GetScroll() + 5.0);
				}
				//前方スクロールライン
				if (m_px > 300)
				{
					m_px = 300;
					b->SetScroll(b->GetScroll() - 5.0);

				}

				//頭に乗せる処理
				if (m_vy < -1.0f)
				{
					//ジャンプしている場合は下記の影響を出さないようにする
				}
				else
				{
					//主人公が敵の頭に乗っているので、Yvecは0にして落下させない
					//また、地面に当たっている判定にする
					m_vy = 0.0f;
					m_hit_down = true;
				}



			}
		}
	}
	//位置の最新
	m_px += m_vx;
	m_py += m_vy;

	//HitBoxの位置の変更
	hit->SetPos(m_px, m_py);
}
//ドロー
void CObjHero::Draw()
{

	

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	int anidata[2] = {0,2};

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	//128,128
	//切り取り位置の設定(切り取り逆)
	if (Input::GetVKey(VK_LEFT) == false && Input::GetVKey(VK_RIGHT) == false)
	{
		src.m_top = 0.0f;
		src.m_left = 368.0f;
		src.m_right = 251.0f;
		src.m_bottom = 127.0f;

		//表示位置の設定
		dst.m_top = 0.0f + m_py;
		dst.m_left = (64.0f    *  m_posture) + m_px;
		dst.m_right = (64 - 64.0f *  m_posture) + m_px;
		dst.m_bottom = 64.0f + m_py;
	}
	else
	{
		src.m_top = 128.0f;
		src.m_left = 0.0f+(anidata[m_ani_frame]*128.0f);
		src.m_right = src.m_left+128.0f;
		src.m_bottom = 256.0f;

		//表示位置の設定
		dst.m_top = 0.0f + m_py;
		dst.m_left = (64.0f-64.0f    *  m_posture) + m_px;
		dst.m_right = (64  *  m_posture) + m_px;
		dst.m_bottom = 64.0f + m_py;
	}
	

	

	//描画
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//交点
	float  cc[4] = { 1.0f,0.0f,0.0f,1.0f };
	src.m_top = 0.0f;
	src.m_left = 320.0f;
	src.m_right = 320.0f + 64.0f;
	src.m_bottom = 64.0f;
	dst.m_top = py;
	dst.m_left = px;
	dst.m_right = dst.m_left + 10.0f;
	dst.m_bottom = dst.m_top + 10.0f;
	Draw::Draw(0, &src, &dst, cc, 0.0f);

}