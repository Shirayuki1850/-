
#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：敵
class CObjEnemy :public CObj
{
public:
	CObjEnemy(float x,float y) ;
	~CObjEnemy() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	float GetVx() { return m_vx; }

private:
	float m_px;//位置X
	float m_py;//位置Y
	float m_vx;//移動ベクトル
	float m_vy;
	float m_posture;//姿勢
	int RndNum;	//乱数

	int m_ani_time;//アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム

	float m_speed_power;//スピードパワー
	float m_ani_max_time;//アニメーション動作間隔最大値

	//blockとの衝突状態確認用
	bool m_hit_up;     //上
	bool m_hit_down;   //下
	bool m_hit_left;   //左
	bool m_hit_right;  //右

	//移動の向き制御用
	bool m_move;

	//HP
	int m_hp;

	bool hit_flag;
	int enemy;
};