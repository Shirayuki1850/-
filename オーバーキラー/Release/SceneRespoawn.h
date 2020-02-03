#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：リスポーン
class CSceneRespoawn:public CScene
{
public:
	CSceneRespoawn();
	~CSceneRespoawn();
	void InitScene();
	void Scene();
private:
};
