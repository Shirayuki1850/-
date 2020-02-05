#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class CObjBulletLeft :public CObj
{
public:
	CObjBulletLeft(float x, float y);	//コントラクタ
	~CObjBulletLeft() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー0

private:
	float b_x;	//弾丸のX方向の位置用変数
	float b_y;	//弾丸のY方向の位置用変数
	float b_vx;	//弾丸のX方向の速度用変数

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

};
