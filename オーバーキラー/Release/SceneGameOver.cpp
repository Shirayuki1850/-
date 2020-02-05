#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameL\SceneObjManager.h"
#include  "GameL\DrawFont.h"
#include "GameL\Audio.h"

using namespace GameL;

#include "SceneGameOver.h"
#include "GameHead.h"

//コンスト
CSceneGameOver::CSceneGameOver(int x)
{
	map_num = x;
}

//デスト
CSceneGameOver::~CSceneGameOver()
{

}



//初期化
void CSceneGameOver::InitScene()
{
	Font::SetStrTex(L"GAME　OVER :PUSH ENTERKEY ");

	//Music loading
	Audio::LoadAudio(2, L"BGMSE/ゲームオーバー.wav", SOUND_TYPE::BACK_MUSIC);



	CObjGameOver* obj = new CObjGameOver(map_num);
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);

	//Music Start
	Audio::Start(2);

	
}

//実行
void CSceneGameOver::Scene()
{

}