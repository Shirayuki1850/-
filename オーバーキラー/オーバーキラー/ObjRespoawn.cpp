//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjTitle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjRespoawn::Init()
{

}

//アクション
void CObjRespoawn::Actoin()
{
	//エンターキーを押してシーン：ゲームメインに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneMain(1));
	}
}
//ドロー
void CObjRespoawn::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"リスポーン", 0, 0, 32, c);

	Font::StrDraw(L"リスポーン：PushEnterKey", 200, 400, 32, c);
}