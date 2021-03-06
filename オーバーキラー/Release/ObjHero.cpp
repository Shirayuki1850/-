//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include"GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include"GameL/Audio.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "GameL\HitBoxManager.h"
#include"GameL/UserData.h"
#include"Windows.h"


//使用するネームスペース
using namespace GameL;

CObjHero::CObjHero(int x)
{
	map_num = x;
}

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

	m_hp = 20;	//HP
	BN = 200;	//弾丸の数

	//blockとの衝突状態確認用
	 m_hit_up     =  false;//上の当たり判定
	 m_hit_down   =  false;//下の当たり判定
	 m_hit_left   =  false;//左の当たり判定
	 m_hit_right  =  false;//右の当たり判定

	 m_block_type = 0;//踏んでいるBlockの種類を確認用

	 hit_time = 0;
	 hit_flag = false;
	 //当たり判定用のHitBoxを作成
	 Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
	 m_f = true;
	 m_f2 = true;
	 f = 0;
	 move_flag = true;
	 se_flag = true;
	 se_flag2 = true;
	 damege_count = 0;
	 damege_flag = false;
	 count = 0;

}
//アクション
void CObjHero::Action()
{

	//ブロックとの当たり判定実行
	
	//自身のHitBoxをもってくる
	CHitBox*hit = Hits::GetHitBox(this);
	if (damege_count >= 3)
	{
		count++;
		if (damege_flag == false)
		{
			m_vx = -2.0f;
		}
		if (damege_flag == true)
		{
			m_vx = 2.0f;
		}

		if (count > 30)
		{
			count = 0;
			damege_count = 0;
		}
		//摩擦
		m_vx += -(m_vx * 0.098);
		//自由落下運動
		m_vy += 9.8 / (16.0f);
	}
	//ブロックと主人公のHitBox
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);
	
	if (damege_count < 3)
	{

		if (m_hp >= 99)          //主人公の体力が上限が最大99
		{                      
			m_hp = 20;//主人公のHPが初期値20
		}
		//落下によるゲームオーバー＆リスタート
		if (m_py > 1000.0f)
		{
			//場外に出たらリスタート。
			Scene::SetScene(new CSceneGameOver(map_num));
		}

		//↑キー入力でジャンプ
		if (Input::GetVKey(VK_UP) == true)
		{
			if (m_hit_down == true)
			{

				m_vy = -15;//ジャンプの高さ

			}



		}

		//Bキー入力で速度アップ
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
		//主人公単発弾発射
		if (Input::GetVKey('S') == true)
		{
			if (m_f == true)
			{
					//if (BN > 0)
					//{	//Music loading
						Audio::LoadAudio(4, L"BGMSE/銃.wav", SOUND_TYPE::EFFECT);
						//Music Start
						Audio::Start(4);
						//弾丸オブジェクト作成
						if (move_flag == false)
						{
							CObjBullet*obj_b = new CObjBullet(m_px-32.0f, m_py + 8.0f, move_flag);	//弾丸オブジェクト作成
							Objs::InsertObj(obj_b, OBJ_BULLET, 1);	//作った弾丸オブジェクトマネージャーに登録
						}
						if (move_flag == true)
						{
							CObjBullet*obj_b = new CObjBullet(m_px+64.0f, m_py + 8.0f, move_flag);	//弾丸オブジェクト作成
							Objs::InsertObj(obj_b, OBJ_BULLET, 1);	//作った弾丸オブジェクトマネージャーに登録
						}
						
						m_f = false;
						//BN--;//無限弾
					//}
			}
		}
		else
		{
			m_f = true;
		}
		if (Input::GetVKey('X') == true)//連射弾
		{
			//
				if (BN > 0)
				{	
					//弾丸オブジェクト作成
					if (move_flag == false&&m_f2==true)
					{
						CObjBullet*obj_b = new CObjBullet(m_px - 32.0f, m_py + 8.0f, move_flag);	//弾丸オブジェクト作成
						Objs::InsertObj(obj_b, OBJ_BULLET, 1);	//作った弾丸オブジェクトマネージャーに登録
						m_f2 = false;
						BN--;//連射したときBNから残弾数を減らす
						//弾丸発射時に指定のSEを読み込む
						Audio::LoadAudio(4, L"BGMSE/銃.wav", SOUND_TYPE::EFFECT);
						//弾丸発射時にSEを鳴らす
						Audio::Start(4);
					}
					if (move_flag == true&&m_f2==true)
					{
						CObjBullet*obj_b = new CObjBullet(m_px + 64.0f, m_py + 8.0f, move_flag);	//弾丸オブジェクト作成
						Objs::InsertObj(obj_b, OBJ_BULLET, 1);	//作った弾丸オブジェクトマネージャーに登録
						m_f2 = false;
						BN--;
						//弾丸発射時に指定のSEを読み込む
						Audio::LoadAudio(4, L"BGMSE/銃.wav", SOUND_TYPE::EFFECT);
						//弾丸発射時にSEを鳴らす
						Audio::Start(4);
					}
					
					
					if (m_f2 == false)
					{
						if (f <= 5)
							f++;
						if (f >= 5)
						{
							m_f2 = true;
							f = 0;
						}
					}
					
				}
			
			
		}
		else
		{
			f = 10;
		}

		//キーの入力方向
		if (Input::GetVKey(VK_RIGHT) == true)
		{
			m_vx += m_speed_power;
			m_posture = 1.0f;
			m_ani_time += 1;
			move_flag = true;
		}
		else if (Input::GetVKey(VK_LEFT) == true)
		{
			m_vx -= m_speed_power;
			m_posture = 0.0f;
			m_ani_time += 1;
			move_flag = false;
		}
		else
		{
			m_ani_frame = 0;//キー入力がない場合は静止フレームにする
			m_ani_time = 0;

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

			float aa = (m_px)-px;//  A(交点→主人公の位置)ベクトル      
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

			px = 0.0f;
			py = 0.0f;
		}



		//当たり判定を行うオブジェクト情報群
		int data_base[4] =
		{
			OBJ_ENEMY,
			OBJ_SPECIAL_ENEMY,
			OBJ_MEDIUM_BOSS,
			OBJ_BOSS_ENEMY,
		};

		//オブジェクト情報群と当たり判定を行い、当たっていればHPを減らす
		
			//HPが０になったら破壊
			if (m_hp <= 0)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);

				Scene::SetScene(new CSceneGameOver(map_num));
			}
		
			//HPが０になったら破壊
			if (m_hp > 0)
			{
				if (hit->CheckObjNameHit(OBJ_HEAL_ITEM) != nullptr)
				{
					m_hp += 3;//HealItemが回復させる量
				}
				if (hit->CheckObjNameHit(OBJ_BULLET_ITEM) != nullptr)
				{
					BN += 5;//BulletItemがドロップする弾薬数
				}
			}
		
	}
	if (m_hit_left == true)
	{
		m_vx = -1.0f;
	}
	if (m_hit_right == true)
	{
		m_vx = 1.0f;
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
	src.m_top = 0.0f;                  //描画元切り取り位置
	src.m_left = 320.0f;               //描画元切り取り位置
	src.m_right = 320.0f + 64.0f;      //描画元切り取り位置
	src.m_bottom = 64.0f;              //描画元切り取り位置
	dst.m_top = py;                    //描画先表示位置
	dst.m_left = px;                   //描画先表示位置
	dst.m_right = dst.m_left + 10.0f;  //描画先表示位置
	dst.m_bottom = dst.m_top + 10.0f;  //描画先表示位置
	Draw::Draw(0, &src, &dst, cc, 0.0f);

	wchar_t str[10];
	float c2[4] = { 1.0f,0.0f,0.0f,1.0f };

	if (m_hp <= 0)
	{
		m_hp = 0;
	}
	//主人公の状態を表示
	swprintf_s(str, L"HP:%d", m_hp);//HP表示
	Font::StrDraw(str, 20, 20, 40, c2);
	swprintf_s(str, L"残弾数:%d", BN);//残弾数表示
	Font::StrDraw(str, 20, 60, 40, c2);
}