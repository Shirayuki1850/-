#pragma once
#include "GameL\SceneObjManager.h"
using namespace GameL;

class CObjTitle :public CObj
{
public:
	CObjTitle() {};	//�R���g���N�^
	~CObjTitle() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	bool m_key_flag;
};