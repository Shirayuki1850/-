#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"


using namespace GameL;

#include "SceneMain.h"
#include "GameHead.h"

CSceneTitle::CSceneTitle()
{

}

CSceneTitle::~CSceneTitle()
{

}
//�^�C�g����ʂ�UI��\��
void CSceneTitle::InitScene()
{
	Font::SetStrTex(L"�����r���z���Ă���");

	//���y�����[�h
	Audio::LoadAudio(3, L"BGMSE/�Q�[���^�C�g��.wav", SOUND_TYPE::BACK_MUSIC);

	//�I�u�W�F�N�g�̃O���t�B�b�N�����[�h
	Draw::LoadImageW(L"�摜/�^�C�g���w�i.jpg", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"�摜/�񕜖�.png", 1, TEX_SIZE_512);

	//BGM��炷
	//float Volume = Audio::VolumeMaster(+0.5f);		//MasterVolume 0.8down
	Audio::Start(3);		//Music Start*/

	CObjTitle*obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 10);
}

void CSceneTitle::Scene()
{

}