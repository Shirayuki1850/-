#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjHealItem :public CObj
{
public:
	CObjHealItem(float x,float y);
	~CObjHealItem() {};
	void Init();
	void Action();
	void Draw();
	float m_ex;
	float m_ey;
private:

	int hp;

	float m_px;
	float m_py;
	
};
