#pragma once
#include "GameL\SceneManager.h"

using namespace GameL;

class CSceneGameOver :public CScene
{
public :
	CSceneGameOver(int x) ;	//�R���g���N�^
	~CSceneGameOver() ;
	void InitScene();
	void Scene();
private:
	int map_num;
};