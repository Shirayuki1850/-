#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjClear.h"

using namespace GameL;


void CObjClear::Init()			//イニシャライズ
{
	//flagをオフにする
	m_key_flag = false;
}

void CObjClear::Action()			//アクション
{
	//Ｃキーで移行
	if (Input::GetVKey('C') == true)
	{
		//flagが真の時、マップ２に移行
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain(2));
			//trueを止める
			m_key_flag = false;
		}
	}
	//Pキーで移行
	if (Input::GetVKey('P') == true)
	{
		//flagが真の時、マップ１に移行
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain(1));
			//trueを止める
			m_key_flag = false;
		}
	}
	//Tキーで移行
	if (Input::GetVKey('T') == true)
	{
		//flagが真の時、タイトルに移行
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			//trueを止める
			m_key_flag = false;
		}
	}
	else
	{
		//flagをオンにする
		m_key_flag = true;
	}
}
//ゲームクリアで出現するUI表示
void CObjClear::Draw()			
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//					  x	   y  size
	Font::StrDraw(L"GAME CLEAR", 250, 230, 60, c);

	Font::StrDraw(L"PUSH T KEY BACK TO TITLE", 200, 350, 30, c);

	Font::StrDraw(L"PUSH P KEY   STAGE1", 220, 390, 30, c);

	Font::StrDraw(L"PUSH C KEY   STAGE2", 220, 420, 30, c);
}