//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjHealItem.h"
#include "GameL\HitBoxManager.h"
#include "CobjBullet.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHeal::Init()
{
	m_px = 70.0f;//�ʒu
	m_py = 64.0f;
	   
	hp = 10;	//HP

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ITEM, OBJ_HEAL_ITEM, 1);

}
void CObjHeal::Action()
{

}

void CObjHeal::Draw()
{

}