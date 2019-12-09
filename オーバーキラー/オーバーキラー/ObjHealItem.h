#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjHealItem :public CObj
{
public:
	CObjHealItem(float x,float y);
	~CObjHealItem() {};
	void Init();
	void Action();
	void Draw();
	float m_ex;
	float m_ey;
private:

	int hp;

	float m_px;
	float m_py;
	
};
