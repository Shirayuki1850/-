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


	//サウンド1番にゲームクリアbgmを登録する
	Audio::LoadAudio(1, L"BGMSE/ゲームクリア.wav",SOUND_TYPE::BACK_MUSIC);

	//Volume 1.0 return
	//float v = Audio::VolumeMaster(+0.5f);
	//v = Audio::VolumeMaster((1 + v));

	//サウンド1番を再生させる
	Audio::Start(1);

	//clear object
	CObjClear* obj = new CObjClear();
	Objs::InsertObj(obj, OBJ_CLEAR, 10);
}

//実行中
void CSceneClear::Scene()
{

}