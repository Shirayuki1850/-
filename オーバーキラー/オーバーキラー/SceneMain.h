#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F���C��
class CSceneMain :public CScene
{
public:
	CSceneMain(int x);
	~CSceneMain() ;
	void InitScene();//���������b�\�h
	void Scene();//���s�����\�b�h
private:
	int map_num;

};