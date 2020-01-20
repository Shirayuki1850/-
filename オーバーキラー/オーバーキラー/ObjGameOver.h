#pragma once
#include "GameL\SceneObjManager.h"
using namespace GameL;

class CObjGameOver :public CObj
{
public :
	CObjGameOver(int x);	//コントラクタ
	~CObjGameOver() {};

	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	bool m_key_flag;
	int map_num;
};