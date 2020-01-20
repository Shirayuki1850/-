#pragma once
#include "GameL\SceneManager.h"

using namespace GameL;

class CSceneGameOver :public CScene
{
public :
	CSceneGameOver(int x) ;	//コントラクタ
	~CSceneGameOver() ;
	void InitScene();
	void Scene();
private:
	int map_num;
};