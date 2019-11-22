#pragma once
#include "GameL\SceneObjManager.h"
using namespace GameL;

class CObjTitle :public CObj
{
public:
	CObjTitle() {};
	~CObjTitle() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
};