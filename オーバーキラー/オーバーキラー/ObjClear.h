#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjClear :public CObj
{
public:
	CObjClear() {};
	~CObjClear() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
};