//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjTitle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjRespoawn::Init()
{

}

//�A�N�V����
void CObjRespoawn::Actoin()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneMain(1));
	}
}
//�h���[
void CObjRespoawn::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"���X�|�[��", 0, 0, 32, c);

	Font::StrDraw(L"���X�|�[���FPushEnterKey", 200, 400, 32, c);
}