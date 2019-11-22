#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "ObjTitle.h"

using namespace GameL;

void CObjTitle::Init()
{
	m_key_flag = false;
}

void CObjTitle::Action()
{
	
	/*//BackMusic Start
	float Volume = Audio::VolumeMaster(-0.8f);		//MasterVolume 0.8down
	Audio::Start(0);		//Music Start*/
	if (Input::GetVKey(VK_RETURN) == true)
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

void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"Over Killer", 230, 250, 32, c);

	Font::StrDraw(L"GameStart	:	PushEnterKey", 200, 400, 32, c);
}