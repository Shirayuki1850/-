#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjClear.h"

using namespace GameL;

void CObjClear::Init()			//イニシャライズ
{
	m_key_flag = false;
}

void CObjClear::Action()			//アクション
{
	//EnterKey push:tereport
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneStageChange());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

void CObjClear::Draw()			//ドロー
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GAME CLEAR", 200, 220, 40, c);

	//Font::StrDraw(L"END", 340, 300, 32, c);

	Font::StrDraw(L"NEXT CHALLENGE : ENTER_KEY", 200, 260, 30, c);
}