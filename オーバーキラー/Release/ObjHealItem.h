#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjHealItem :public CObj
{
public:
	CObjHealItem(float x,float y);	//�R���g���N�^
	~CObjHealItem() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
	float m_ex;
	float m_ey;
private:

	int hp;	//HP

	float m_px;
	float m_py;
	
};
