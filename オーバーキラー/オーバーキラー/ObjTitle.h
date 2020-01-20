#pragma once
#include "GameL\SceneObjManager.h"
using namespace GameL;

class CObjTitle :public CObj
{
public:
	CObjTitle() {};	//コントラクタ
	~CObjTitle() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	bool m_key_flag;
};