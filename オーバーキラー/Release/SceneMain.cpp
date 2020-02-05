//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include "GameL\UserData.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���g���N�^
CSceneMain::CSceneMain(int x)
{
	map_num = x;
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
	p = Save::ExternalDataOpen(L"�}�b�v�f�[�^/�}�b�v001.csv", &size);//�O���f�[�^�̓ǂݍ���

	
	//�}�b�v�P�̏��
	//10�~200
	int map[10][200];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 200; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}
	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t>p2;//�X�e�[�W���|�C���^�[
	int size2;
	p2 = Save::ExternalDataOpen(L"�}�b�v�f�[�^/�}�b�v002.csv", &size2);//�O���f�[�^�̓ǂݍ���



	//�}�b�v�Q�̏��
	//10�~200
	int map2[10][200];
	int count2 = 1;
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 200; j++)
		{
			int w = 0;
			swscanf_s(&p2.get()[count2], L"%d", &w);

			map2[i][j] = w;
			count2 += 2;
		}
	}

	
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"�摜/���[����W��.png", 2,TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/�w�i�V.jpg", 0, TEX_SIZE_512);

	Draw::LoadImageW(L"�摜/�A�C�e���܂Ƃ�.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/mobblock.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/mob�܂Ƃ�.png", 5, TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/image.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/image2.png", 10, TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/����]���r.png", 11, TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/�{�X�O����.png",12,TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/���{�X�O����.png", 13, TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/�񕜖�.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/image3.png", 14, TEX_SIZE_512);

	
	//�T�E���h�o�^�@�ǂݍ���
	Audio::LoadAudio(5, L"BGMSE/�Q�[�����C��.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(8, L"BGMSE/���{�X.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(9, L"BGMSE/���X�{�X.wav", SOUND_TYPE::BACK_MUSIC);

	//�G�t�F�N�g�o�^�@�ǂݍ���
	Audio::LoadAudio(6, L"BGMSE/���p���`.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(7, L"��p���`.wav", SOUND_TYPE::EFFECT);
	

	//�V�[�����C���Ɉڍs������T�E���h5�Ԃ��Đ�
	Audio::Start(5);
	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero(map_num);
	Objs::InsertObj(obj, OBJ_HERO,12);

	//�u���b�N�I�u�W�F�N�g�쐬
	if(map_num==1)
	{
		//�}�b�v�Q�I�u�W�F�N�g
		CObjBlock* objb = new CObjBlock(map);
		Objs::InsertObj(objb, OBJ_BLOCK, 10);
	}
	if (map_num == 2)
	{
		//�}�b�v�Q�I�u�W�F�N�g
		CObjBlock* objb = new CObjBlock(map2);
		Objs::InsertObj(objb, OBJ_BLOCK, 10);
	}
	

	
	//�w�i�쐬
	CObjStage* objs = new CObjStage();
	Objs::InsertObj(objs, OBJ_STAGE, 0);

	
}

//���s�����\�b�h
void CSceneMain::Scene()
{




}