#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjHeal :public CObj
{
public:
	CObjHeal(float x, float y);
	~CObjHeal() {};
	void Init();
	void Action();
	void Draw();

private:

	int hp;

	float m_px;
	float m_py;
	
};
