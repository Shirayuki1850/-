#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"
#include "GameL/Audio.h"

using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{

}

//アクション
void CObjGameOver::Action()
{
	//EnterKey push:tereport	エンター押したら
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//リスポーン
	Font::StrDraw(L"GAME　OVER : PUSH ENTERKEY RESPOAWN", 200, 250, 25, c);

	

}
