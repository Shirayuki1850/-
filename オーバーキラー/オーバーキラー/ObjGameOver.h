#pragma once
#include "GameL\SceneObjManager.h"
using namespace GameL;

class CObjGameOver :public CObj
{
public :
	CObjGameOver(int x);	//�R���g���N�^
	~CObjGameOver() {};

	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	bool m_key_flag;
	int map_num;
};