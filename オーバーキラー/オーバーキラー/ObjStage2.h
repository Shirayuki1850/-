#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CObjStage2 :public CObj
{
public:
	CObjStage2() {};
	~CObjStage2() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:

};