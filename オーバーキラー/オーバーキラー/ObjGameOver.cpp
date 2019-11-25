#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"

using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{

}

//�A�N�V����
void CObjGameOver::Action()
{
	//EnterKey push:tereport	�G���^�[��������
	if (Input::GetVKey(VK_RETURN) == true)
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

//�h���[
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	//�Q�[���I�[�o�[
	Font::StrDraw(L"GAME OVER",0,0,32,c);
	//���X�|�[��
	Font::StrDraw(L"NEW GAME : RESPORN", 0, 0, 32, c);
}
