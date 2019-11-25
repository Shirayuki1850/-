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
	
}

//実行
void CSceneGameOver::Scene()
{
	Font::SetStrTex(L"GAME OVER");
	Font::SetStrTex(L"NEW GAME : RESPORN");

	//Music loading
	Audio::LoadAudio(2, L"BJMSE/ゲームオーバー.wav", BACK_MUSIC);

	//Volume 1.0 return
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//Music Start
	Audio::Start(0);

	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);

}