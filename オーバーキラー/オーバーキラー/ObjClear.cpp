#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjClear.h"

using namespace GameL;

void CObjClear::Init()			//�C�j�V�����C�Y
{
	m_key_flag = false;
}

void CObjClear::Action()			//�A�N�V����
{
	//�b�L�[��������Q�[�����C���Q�Ɉڍs
	if (Input::GetVKey('C') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain(2));
			m_key_flag = false;
		}
	}
	//P�L�[����������X�e�[�W�P�Ɉڍs
	if (Input::GetVKey('P') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain(1));
			m_key_flag = false;
		}
	}
	//T�L�[��������^�C�g���Ɉڍs
	if (Input::GetVKey('T') == true)
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
//�Q�[���N���A�ŏo������UI�\��
void CObjClear::Draw()			
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GAME CLEAR", 250, 230, 60, c);

	Font::StrDraw(L"PUSH T KEY BACK TO TITLE", 200, 350, 30, c);

	Font::StrDraw(L"PUSH P KEY   STAGE1", 220, 390, 30, c);

	Font::StrDraw(L"PUSH C KEY   STAGE2", 220, 420, 30, c);
}