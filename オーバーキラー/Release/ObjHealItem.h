#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjHealItem :public CObj
{
public:
	CObjHealItem(float x,float y);	//コントラクタ
	~CObjHealItem() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	float m_ex;
	float m_ey;
private:

	int hp;	//HP

	float m_px;
	float m_py;
	
};
