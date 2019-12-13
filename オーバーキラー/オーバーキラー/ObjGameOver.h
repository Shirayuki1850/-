#pragma once
#include "GameL\SceneObjManager.h"
using namespace GameL;

class CObjGameOver :public CObj
{
public :
	CObjGameOver(int x);
	~CObjGameOver() {};

	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
	int map_num;
};