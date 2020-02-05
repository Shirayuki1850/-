#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"


using namespace GameL;

#include "SceneMain.h"
#include "GameHead.h"

CSceneStageChange::CSceneStageChange()
{

}

CSceneStageChange::~CSceneStageChange()
{

}

void CSceneStageChange::InitScene()
{
	Font::SetStrTex(L"NEXT STAGE CHALLENGE");

	//Music loading
	Audio::LoadAudio(1, L"BGMSE/�Q�[���N���A.wav", SOUND_TYPE::BACK_MUSIC);

	// image loading
	Draw::LoadImageW(L"�摜/�^�C�g���w�i.jpg", 0, TEX_SIZE_512);
	/*Draw::LoadImageW(L"�摜/�񕜖�.png", 1, TEX_SIZE_512);

	//BackMusic Start
	//float Volume = Audio::VolumeMaster(+0.5f);		//MasterVolume 0.8down*/	


	Audio::Start(1);

	CObjStageChange*obj = new CObjStageChange();
	Objs::InsertObj(obj, OBJ_STAGECHANGE, 10);
}

void CSceneStageChange::Scene()
{

}