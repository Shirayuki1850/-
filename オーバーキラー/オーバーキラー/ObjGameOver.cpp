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
	//エンターキーを押すと指定された場所へ遷移	
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	//Rキーを押すとリスポーン
	if (Input::GetVKey('R') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain(map_num));
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

	//ゲームオーバー時のUIを表示させる
	Font::StrDraw(L"GAME　OVER : PUSH ENTERKEY ", 200, 220, 30, c);

	
	Font::StrDraw(L"Retry: PUSH R KEY ", 250, 260, 30, c);
	

}
