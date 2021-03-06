//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjHealItem.h"
#include "GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjHealItem::CObjHealItem(float x, float y)
{
	m_ex = x;
	m_ey = y;
}

//イニシャライズ
void CObjHealItem::Init()
{
	//回復するHPの量
	hp = 3; 
	//当たり判定用のHitBoxを作成
	//								   x   y 
	Hits::SetHitBox(this, m_ex, m_ey, 64, 85, ELEMENT_ITEM, OBJ_HEAL_ITEM, 0);
	
}
void CObjHealItem::Action()
{
	//hitboxの作成
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CHitBox*hit = Hits::GetHitBox(this);

	//プレイヤーが当たった時、trueにする
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		//プレイヤーに当たってtrueになったらfalseにし、消す
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	hit->SetPos(m_ex + pb->GetScroll(), m_ey);
}

void CObjHealItem::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 85.0f;

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	dst.m_top	 = 0.0f+m_ey;
	dst.m_left	 = 0.0f+m_ex+block->GetScroll();
	dst.m_right  = 64.0f+m_ex+block->GetScroll();
	dst.m_bottom = 85.0f+m_ey;

	Draw::Draw(4, &src, &dst, c, 0.0f);

}