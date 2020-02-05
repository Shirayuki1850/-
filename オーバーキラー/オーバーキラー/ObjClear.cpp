#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjClear.h"

using namespace GameL;


void CObjClear::Init()			//�C�j�V�����C�Y
{
	//flag���I�t�ɂ���
	m_key_flag = false;
}

void CObjClear::Action()			//�A�N�V����
{
	//�b�L�[�ňڍs
	if (Input::GetVKey('C') == true)
	{
		//flag���^�̎��A�}�b�v�Q�Ɉڍs
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain(2));
			//true���~�߂�
			m_key_flag = false;
		}
	}
	//P�L�[�ňڍs
	if (Input::GetVKey('P') == true)
	{
		//flag���^�̎��A�}�b�v�P�Ɉڍs
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain(1));
			//true���~�߂�
			m_key_flag = false;
		}
	}
	//T�L�[�ňڍs
	if (Input::GetVKey('T') == true)
	{
		//flag���^�̎��A�^�C�g���Ɉڍs
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			//true���~�߂�
			m_key_flag = false;
		}
	}
	else
	{
		//flag���I���ɂ���
		m_key_flag = true;
	}
}
//�Q�[���N���A�ŏo������UI�\��
void CObjClear::Draw()			
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//					  x	   y  size
	Font::StrDraw(L"GAME CLEAR", 250, 230, 60, c);

	Font::StrDraw(L"PUSH T KEY BACK TO TITLE", 200, 350, 30, c);

	Font::StrDraw(L"PUSH P KEY   STAGE1", 220, 390, 30, c);

	Font::StrDraw(L"PUSH C KEY   STAGE2", 220, 420, 30, c);
}