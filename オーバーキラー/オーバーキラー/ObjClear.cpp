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
	//Ｃキー押したらゲームメイン２に移行
	if (Input::GetVKey('2') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain(2));
			m_key_flag = false;
		}
	}

	if (Input::GetVKey('T') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle);
			m_key_flag = false;
		}
	}
	/*
	if (Input::GetVKey('T') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain(2));
			m_key_flag = false;
		}
	}*/
	else
	{
		m_key_flag = true;
	}
}

void CObjClear::Draw()			//ドロー
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GAME CLEAR", 250, 230, 60, c);

	Font::StrDraw(L"PUSH T KEY BACK TO TITLE", 200, 350, 30, c);

	Font::StrDraw(L"PUSH 2 KEY  NEXT STAGE2", 220, 420, 30, c);
}