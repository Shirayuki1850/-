//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjBulletItem.h"
#include "GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBulletItem::CObjBulletItem(float x, float y)
{
	m_ex = x;
	m_ey = y;
}

//�C�j�V�����C�Y
void CObjBulletItem::Init()
{

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 32, 32, ELEMENT_ITEM, OBJ_BULLET_ITEM, 0);

}
void CObjBulletItem::Action()
{
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CHitBox*hit = Hits::GetHitBox(this);

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	hit->SetPos(m_ex + pb->GetScroll(), m_ey);
}

void CObjBulletItem::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	src.m_top = 2.0f;
	src.m_left = 2.0f;
	src.m_right = 30.0f;
	src.m_bottom = 30.0f;

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_ey;
	dst.m_left = 0.0f + m_ex + block->GetScroll();
	dst.m_right = 32.0f + m_ex + block->GetScroll();
	dst.m_bottom = 32.0f + m_ey;

	Draw::Draw(14, &src, &dst, c, 0.0f);

}