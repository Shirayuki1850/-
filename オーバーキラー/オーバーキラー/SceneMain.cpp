//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{
	
}

//���������\�b�h
void CSceneMain::InitScene()
{
	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size;
	p = Save::ExternalDataOpen(L"�}�b�v�f�[�^/�}�b�vEasy.csv", &size);//�O���f�[�^�̓ǂݍ���
	//p = Save::ExternalDataOpen(L"�}�b�vNomal.csv", &size);//�O���f�[�^�̓ǂݍ���
	//p = Save::ExternalDataOpen(L"�}�b�v.Hard.csv", &size);//�O���f�[�^�̓ǂݍ���

	int map[10][100];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 100; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

	
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"�摜/���[����W��.png", 2,TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/�w�i����.jpg", 0, TEX_SIZE_512);

	Draw::LoadImageW(L"�摜/�e,�A�[�}�[�܂Ƃ�.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/�A�C�e���܂Ƃ�.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/mobblock.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/mob�܂Ƃ�.png", 5, TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/image.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/image2.png", 10, TEX_SIZE_512);

	/*Draw::LoadImageW(L"�摜/Title.png",9,TEX_SIZE_512);*/
	//Draw::LoadImageW(L"���p�e��.png", 5, TEX_SIZE_512);
	//Draw::LoadImageW(L"�[���p�e��.png", 6, TEX_SIZE_512);
	//Draw::LoadImageW(L"��p�e��.png", 7, TEX_SIZE_512);
	
	

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO,12);

	//�u���b�N�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 10);

	/*//6�I�u�W�F�N�g�쐬
	CObjMediumBoss*obj6 = new CObjMediumBoss(map);
	Objs::InsertObj(obj6, OBJ_MEDIUM_BOSS, 15);*/

	//�w�i�쐬
	CObjStage* objs = new CObjStage();
	Objs::InsertObj(objs, OBJ_STAGE, 0);

	/*//�G�I�u�W�F�N�g�쐬
	CObjEnemy*obje = new CObjEnemy();
	Objs::InsertObj(obje, OBJ_ENEMY, 13);*/

	

}

//���s�����\�b�h
void CSceneMain::Scene()
{




}