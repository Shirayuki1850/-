#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjStageChange.h"
#include "GameL/Audio.h"

using namespace GameL;

//イニシャライズ
void CObjStageChange::Init()
{

}

//アクション
void CObjStageChange::Action()
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
	if (Input::GetVKey('Q') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjStageChange::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//次の難易度へ
	Font::StrDraw(L"Next Difficulty Challenge : PUSH Q ENTERKEY ", 200, 250, 25, c);

	//タイトルへ
	Font::StrDraw(L"Retry: PUSH ENTER KEY ", 200, 450, 40, c);


}
