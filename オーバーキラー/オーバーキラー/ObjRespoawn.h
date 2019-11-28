#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjRespoawn:public CObj
{
public:
	CObjRespoawn() {};
	~CObjRespoawn() {};
	void Init();	//イニシャライズ
	void Actoin();	//アクション
	void Draw();	//ドロー

private:
};
