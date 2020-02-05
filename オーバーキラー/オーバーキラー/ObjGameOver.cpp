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

//�C�j�V�����C�Y
void CObjGameOver::Init()
{

}

//�A�N�V����
void CObjGameOver::Action()
{
	//�G���^�[�L�[�������Ǝw�肳�ꂽ�ꏊ�֑J��	
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	//R�L�[�������ƃ��X�|�[��
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

//�h���[
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�Q�[���I�[�o�[����UI��\��������
	Font::StrDraw(L"GAME�@OVER : PUSH ENTERKEY ", 200, 220, 30, c);

	
	Font::StrDraw(L"Retry: PUSH R KEY ", 250, 260, 30, c);
	

}
