#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

using namespace GameL;

#include "SceneClear.h"
#include "GameHead.h"

//コンスト
CSceneClear::CSceneClear()
{

}

//デスト
CSceneClear::~CSceneClear()
{

}

//初期化
void CSceneClear::InitScene()
{
	Font::SetStrTex(L"GAME CLEAR");


	//Music loading
	Audio::LoadAudio(1, L"BJMSE/ゲームクリア.wav", BACK_MUSIC);

	//Volume 1.0 return
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1 - v));

	//Music Start
	Audio::Start(0);

	//clear object
	CObjClear* obj = new CObjClear();
	Objs::InsertObj(obj, OBJ_CLEAR, 10);
}

//実行中
void CSceneClear::Scene()
{

}