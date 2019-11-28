//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjHealItem.h"
#include "GameL\HitBoxManager.h"
#include "CobjBullet.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHeal::Init()
{
	m_px = 70.0f;//位置
	m_py = 64.0f;
	   
	hp = 10;	//HP

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ITEM, OBJ_HEAL_ITEM, 1);

}
void CObjHeal::Action()
{

}

void CObjHeal::Draw()
{

}