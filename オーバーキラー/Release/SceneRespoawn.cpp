//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"
#include"SceneRespoawn.h"

//�R���g���N�^
CSceneRespoawn::CSceneRespoawn()
{

}

//�f�X�g���N�^
CSceneRespoawn::~CSceneRespoawn()
{

}

//�Q�[�����C�����������\�b�h
void CSceneRespoawn::InitScene()
{
	//�o�͂�����O���t�B�b�N���쐬
	Font::SetStrTex(L"���X�|�[��");


	//�I�u�W�F�N�g�쐬
	//CObjRespoawn*obj = new CObjRespoawn();
	//Objs::InsertObj(obj, OBJ_RESPOAWN, 10);
}

//�Q�[�����C�����s�����\�b�h
void CSceneRespoawn::Scene()
{

}