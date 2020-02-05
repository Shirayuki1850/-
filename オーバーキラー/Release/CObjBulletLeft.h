#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�e��
class CObjBulletLeft :public CObj
{
public:
	CObjBulletLeft(float x, float y);	//�R���g���N�^
	~CObjBulletLeft() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[0

private:
	float b_x;	//�e�ۂ�X�����̈ʒu�p�ϐ�
	float b_y;	//�e�ۂ�Y�����̈ʒu�p�ϐ�
	float b_vx;	//�e�ۂ�X�����̑��x�p�ϐ�

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

};
