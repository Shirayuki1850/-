//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"
#include"SceneRespoawn.h"

//コントラクタ
CSceneRespoawn::CSceneRespoawn()
{

}

//デストラクタ
CSceneRespoawn::~CSceneRespoawn()
{

}

//ゲームメイン初期化メソッド
void CSceneRespoawn::InitScene()
{
	//出力させるグラフィックを作成
	Font::SetStrTex(L"リスポーン");


	//オブジェクト作成
	//CObjRespoawn*obj = new CObjRespoawn();
	//Objs::InsertObj(obj, OBJ_RESPOAWN, 10);
}

//ゲームメイン実行中メソッド
void CSceneRespoawn::Scene()
{

}