#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneMain :public CScene
{
public:
	CSceneMain(int x);
	~CSceneMain() ;
	void InitScene();//初期化メッソド
	void Scene();//実行中メソッド
private:
	int map_num;

};