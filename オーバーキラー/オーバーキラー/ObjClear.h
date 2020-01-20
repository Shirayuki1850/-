#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjClear :public CObj
{
public:
	CObjClear() {};		//コントラクタ
	~CObjClear() {};	
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	bool m_key_flag;
};