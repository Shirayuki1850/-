#pragma once
#include "GameL\SceneManager.h"

using namespace GameL;

class CSceneGameOver :public CScene
{
public :
	CSceneGameOver(int x) ;
	~CSceneGameOver() ;
	void InitScene();
	void Scene();
private:
	int map_num;
};