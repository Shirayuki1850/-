//�g�p����w�b�_�[�t�@�C��
#include "GameHead.h"
#include "CobjBullet.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/Audio.h"
#include"GameL/WinInputs.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���g���N�^
CObjBullet::CObjBullet(float x, float y,bool f)
{
	b_x = x;
	b_y = y;
	move_flag = f;
}
//�C�j�V�����C�Y
void CObjBullet::Init()
{
	if (move_flag == true)
	{
		b_vx = 6.0f;
	}
	if (move_flag == false)
	{
		b_vx = -6.0f;
	}
	f = 0;
	m_hit_up = false;
	m_hit_down=false;
	m_hit_left=false;
	m_hit_right=false;
	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, b_x, b_y, 32, 32, ELEMENT_PLAYER, OBJ_BULLET, 1);
}

//�A�N�V����
void CObjBullet::Action()
{
	
	b_x += b_vx;

	//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(b_x, b_y);	//HitBox�̈ʒu��e�ۂ̈ʒu�ɍX�V

	//�̈�O�ɏo����e�ۂ�j�󂷂�
	if (b_x > 600.0f || b_x < 5.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//�u���b�N���������Ă���

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	block->BulletHit(&b_x, &b_y, true, &m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right);

	if (m_hit_down == true || m_hit_left == true || m_hit_right == true || m_hit_up == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//�����蔻��I�u�W�F�N�g���Q
	int data_base[5] =
	{
		OBJ_ENEMY,
		OBJ_SPECIAL_ENEMY,
		OBJ_MEDIUM_BOSS,
		OBJ_BOSS_ENEMY,
		OBJ_BLOCK,
	};
	
	//�I�u�W�F�N�g���Q�Ɠ����蔻����s���A�������Ă���΍폜
	for (int i = 0; i < 5; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

}

//�h���[
void CObjBullet::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top =- 2.0f;
	src.m_left =- 2.0f;
	src.m_right = -30.0f;
	src.m_bottom = -30.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f+b_y;
	dst.m_left = 0.0f+b_x;
	dst.m_right = 32.0f+b_x;
	dst.m_bottom = 32.0f + b_y;

	//�`��
	if (move_flag == false)
	{
		Draw::Draw(8, &src, &dst, c, 180.0f);
	}
	if (move_flag == true)
	{
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	

}
