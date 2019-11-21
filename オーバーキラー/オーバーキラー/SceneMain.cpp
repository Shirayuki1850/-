//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include "GameL\UserData.h"

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
	p = Save::ExternalDataOpen(L"マップEasy.csv", &size);//外部データの読み込み
	//p = Save::ExternalDataOpen(L"マップNomal.csv", &size);//外部データの読み込み
	//p = Save::ExternalDataOpen(L"マップ.Hard.csv", &size);//外部データの読み込み

	int map[10][100];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 100; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

	
	//グラフィック読み込み
	Draw::LoadImageW(L"うーたん集合.png", 2,TEX_SIZE_512);
	Draw::LoadImageW(L"背景昼間.jpg", 0, TEX_SIZE_512);
	//Draw::LoadImageW(L"背景昼間.jpg", 0, TEX_SIZE_512);
	//Draw::LoadImageW(L"背景昼間.jpg", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"銃,アーマーまとめ.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"アイテムまとめ.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"test.png", 1, TEX_SIZE_512);
	//Draw::LoadImageW(L"昼用弾丸.png", 5, TEX_SIZE_512);
	//Draw::LoadImageW(L"夕方用弾丸.png", 6, TEX_SIZE_512);
	//Draw::LoadImageW(L"夜用弾丸.png", 7, TEX_SIZE_512);
	
	

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO,12);

	//ブロックオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 10);

	//背景作成
	CObjStage* objs = new CObjStage();
	Objs::InsertObj(objs, OBJ_STAGE, 1);

	

}

//実行中メソッド
void CSceneMain::Scene()
{




}