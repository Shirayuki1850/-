//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include "GameL\UserData.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コントラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{
	
}

//初期化メソッド
void CSceneMain::InitScene()
{
	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;
	p = Save::ExternalDataOpen(L"マップデータ/マップ1.csv", &size);//外部データの読み込み
	//p = Save::ExternalDataOpen(L"マップNomal.csv", &size);//外部データの読み込み
	//p = Save::ExternalDataOpen(L"マップ.Hard.csv", &size);//外部データの読み込み

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

	
	//グラフィック読み込み
	Draw::LoadImageW(L"画像/うーたん集合.png", 2,TEX_SIZE_512);
	Draw::LoadImageW(L"画像/背景新.jpg", 0, TEX_SIZE_512);

	Draw::LoadImageW(L"画像/アイテムまとめ.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"画像/mobblock.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"画像/mobまとめ.png", 5, TEX_SIZE_512);
	Draw::LoadImageW(L"画像/image.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"画像/image2.png", 10, TEX_SIZE_512);
	Draw::LoadImageW(L"画像/特殊ゾンビ.png", 11, TEX_SIZE_512);
	Draw::LoadImageW(L"画像/ボス前向き.png",12,TEX_SIZE_512);
	Draw::LoadImageW(L"画像/中ボス前向き.png", 13, TEX_SIZE_512);
	Draw::LoadImageW(L"画像/回復薬.png", 4, TEX_SIZE_512);

	/*Draw::LoadImageW(L"画像/Title.png",9,TEX_SIZE_512);*/
	//Draw::LoadImageW(L"昼用弾丸.png", 5, TEX_SIZE_512);
	//Draw::LoadImageW(L"夕方用弾丸.png", 6, TEX_SIZE_512);
	//Draw::LoadImageW(L"夜用弾丸.png", 7, TEX_SIZE_512);
	
	//Music loading
	Audio::LoadAudio(5, L"BGMSE/ゲームメイン.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(6, L"BGMSE/小パンチ.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(7, L"大パンチ.wav", SOUND_TYPE::EFFECT);
	

	/*//Volume 1.0 return
	float v = Audio::VolumeMaster(+0.5f);
	v = Audio::VolumeMaster((1 + v));*/

	Audio::Start(5);
	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO,12);

	//ブロックオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 10);

	/*//6オブジェクト作成
	CObjMediumBoss*obj6 = new CObjMediumBoss(map);
	Objs::InsertObj(obj6, OBJ_MEDIUM_BOSS, 15);
	*/
	//背景作成
	CObjStage* objs = new CObjStage();
	Objs::InsertObj(objs, OBJ_STAGE, 0);

	/*//敵オブジェクト作成
	CObjEnemy*obje = new CObjEnemy();
	Objs::InsertObj(obje, OBJ_ENEMY, 13);*/


}

//実行中メソッド
void CSceneMain::Scene()
{




}