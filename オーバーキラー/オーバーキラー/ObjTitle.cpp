#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"
#include "GameL/DrawTexture.h"

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

	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 626.0f;
	src.m_bottom = 417.0f;
	//ï\é¶à íuÇÃê›íË
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	//ï`âÊ
	Draw::Draw(0, &src, &dst, c, 0.0f);


	Font::StrDraw(L"Over Killer", 230, 250, 32, c);

	Font::StrDraw(L"GameStart  :Å@PushEnterKey", 200, 400, 32, c);


}