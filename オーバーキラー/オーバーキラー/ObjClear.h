#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjClear :public CObj
{
public:
	CObjClear() {};		//�R���g���N�^
	~CObjClear() {};	
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	bool m_key_flag;
};