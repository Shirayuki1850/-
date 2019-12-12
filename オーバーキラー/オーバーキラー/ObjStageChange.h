#pragma once
#include "GameL\SceneObjManager.h"
using namespace GameL;

class CObjStageChange :public CObj
{
public:
	CObjStageChange() {};
	~CObjStageChange() {};

	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
};