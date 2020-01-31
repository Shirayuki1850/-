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
//タイトル画面のUIを表示
void CSceneTitle::InitScene()
{
	Font::SetStrTex(L"動く屍を越えていけ");

	//音楽をロード
	Audio::LoadAudio(3, L"BGMSE/ゲームタイトル.wav", SOUND_TYPE::BACK_MUSIC);

	//オブジェクトのグラフィックをロード
	Draw::LoadImageW(L"画像/タイトル背景.jpg", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"画像/回復薬.png", 1, TEX_SIZE_512);

	//BGMを鳴らす
	//float Volume = Audio::VolumeMaster(+0.5f);		//MasterVolume 0.8down
	Audio::Start(3);		//Music Start*/

	CObjTitle*obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 10);
}

void CSceneTitle::Scene()
{

}