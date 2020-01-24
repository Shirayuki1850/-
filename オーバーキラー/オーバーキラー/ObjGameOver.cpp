#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"
#include "GameL/Audio.h"

using namespace GameL;

CObjGameOver::CObjGameOver(int x)
{
	map_num = x;
}

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
	if (Input::GetVKey('R') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain(1));
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
	Font::StrDraw(L"GAME　OVER : PUSH ENTERKEY ", 200, 220, 30, c);

	//リスポーン
	Font::StrDraw(L"Retry: PUSH R KEY ", 250, 260, 30, c);
	

}
