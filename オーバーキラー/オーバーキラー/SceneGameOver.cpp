#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameL\SceneObjManager.h"
#include  "GameL\DrawFont.h"
#include "GameL\Audio.h"

using namespace GameL;

#include "SceneGameOver.h"
#include "GameHead.h"

//コンスト
CSceneGameOver::CSceneGameOver()
{

}

//デスト
CSceneGameOver::~CSceneGameOver()
{

}



//初期化
void CSceneGameOver::InitScene()
{
	Font::SetStrTex(L"GAME　OVER :PUSH ENTERKEY RESPOAWN");

	//Music loading
	Audio::LoadAudio(2, L"BGMSE/ゲームオーバー.wav", SOUND_TYPE::BACK_MUSIC);

	//Volume 1.0 return
	float v = Audio::VolumeMaster(-0.8f);
	v = Audio::VolumeMaster((1.0 - v));

	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);

	//Music Start
	Audio::Start(2);

	
}

//実行
void CSceneGameOver::Scene()
{

}