//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "CObjSpecialEnemy.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���g���N�^
CObjSpecialEnemy::CObjSpecialEnemy(float x, float y)
{
	m_px = x;    //X�����̈ʒu
	m_py = y;    //Y�����̈ʒu
}

//�C�j�V�����C�Y
void CObjSpecialEnemy::Init()
{
	m_vx = 0.0f;    //�ړ��x�N�g��X
	m_vy = 0.0f;    //�ړ��x�N�g��Y
	m_hp = 3;	//HP

	m_posture = 1.0f;//�E����0.0f��1.0��

	m_ani_time = 0;
	m_ani_frame = 1;//�Î~�t���[���������ɂ���B

	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 4;//�A�j���[�V�����Ԋu��

	m_move = true;//true=�E�@false=��

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	hit_flag = false;
	
	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 128, 64, ELEMENT_ENEMY, OBJ_SPECIAL_ENEMY, 1);
}

//�A�N�V����
void CObjSpecialEnemy::Action()
{	

	//����
	if (m_py > 1000.0f)
	{
		;
	}
	
	//�ʏ푬�x
	m_speed_power = 0.5f;     //����]���r�̑��x
	m_ani_max_time = 4;       //�A�j���[�V��������Ԋu�ő�l

	//�u���b�N�Փ˂Ō����ύX
	if (m_hit_left == true)
	{
		m_move = true;
	}
	if (m_hit_right == true)
	{

		m_move = false;
	}

	//����
	if (m_move == false)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (m_move == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}


	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{

		m_ani_frame = 0;

	}

	//���C
	m_vx += -(m_vx * 0.098);

	//���R�����^��
	m_vy += 9.8 / (16.0f);
	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
	int d;
	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);


	//�ʒu�̍ŐV
	m_px += m_vx;
	m_py += m_vy;

	//�u���b�N���������Ă���
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero*h = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//HitBox�̈ʒu�̕ύX
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);



	/*//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);*/



	//�e�ۂƐڐG���Ă�����HP�����炷
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		if (hit_flag == false)
		{
			hit_flag = true;
			if (h->GetX() - pb->GetScroll() > m_px + 128)
				h->DamegeFlag(true);
			if (h->GetX() - pb->GetScroll() + 64 < m_px)
				h->DamegeFlag(false);
			if (h->GetDamegeflag() < 3)
			{
				h->SetDamege(1);
				h->SetDamegeCount();
			}
			//Music Start
			Audio::Start(6);
		}
	}
	else
	{
		if (hit_flag == true)
		{
				hit_flag = false;
		}
	}
	//HP���O�ɂȂ�����j��
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		CObjBulletItem*ObjB = new CObjBulletItem(m_px, m_py);
		Objs::InsertObj(ObjB, OBJ_BULLET_ITEM, 14);
		int BN;
	}

}

//�h���[
void CObjSpecialEnemy::Draw()
{

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu




	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = src.m_top+64.0f;

	//�u���b�N���������Ă���
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	
	dst.m_top = 0.0f + m_py;
	dst.m_left = (128.0f    *   m_posture) + m_px + block->GetScroll();
	dst.m_right = (128 - 128.0f *  m_posture) + m_px + block->GetScroll();
	dst.m_bottom = 64.0f + m_py;

	//�`��
	Draw::Draw(11, &src, &dst, c, 0.0f);
}
