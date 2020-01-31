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
CSceneMain::CSceneMain(int x)
{
	map_num = x;
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
	p = Save::ExternalDataOpen(L"マップデータ/マップ001.csv", &size);//外部データの読み込み

	
	//マップ１の情報
	//10×200
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
	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t>p2;//ステージ情報ポインター
	int size2;
	p2 = Save::ExternalDataOpen(L"マップデータ/マップ002.csv", &size2);//外部データの読み込み



	//マップ２の情報
	//10×200
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
	Draw::LoadImageW(L"画像/image3.png", 14, TEX_SIZE_512);

	
	//サウンド登録　読み込み
	Audio::LoadAudio(5, L"BGMSE/ゲームメイン.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(8, L"BGMSE/中ボス.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(9, L"BGMSE/ラスボス.wav", SOUND_TYPE::BACK_MUSIC);

	//エフェクト登録　読み込み
	Audio::LoadAudio(6, L"BGMSE/小パンチ.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(7, L"大パンチ.wav", SOUND_TYPE::EFFECT);
	

	//シーンメインに移行したらサウンド5番を再生
	Audio::Start(5);
	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(map_num);
	Objs::InsertObj(obj, OBJ_HERO,12);

	//ブロックオブジェクト作成
	if(map_num==1)
	{
		//マップ２オブジェクト
		CObjBlock* objb = new CObjBlock(map);
		Objs::InsertObj(objb, OBJ_BLOCK, 10);
	}
	if (map_num == 2)
	{
		//マップ２オブジェクト
		CObjBlock* objb = new CObjBlock(map2);
		Objs::InsertObj(objb, OBJ_BLOCK, 10);
	}
	

	
	//背景作成
	CObjStage* objs = new CObjStage();
	Objs::InsertObj(objs, OBJ_STAGE, 0);

	
}

//実行中メソッド
void CSceneMain::Scene()
{




}