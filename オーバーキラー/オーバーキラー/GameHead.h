#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_HERO,
	OBJ_BLOCK,
	OBJ_ENEMY,
	OBJ_BULLET,
	OBJ_BULLET_LEFT,
	OBJ_BOSS_ENEMY,
	OBJ_STAGE,
	OBJ_TITLE,
	OBJ_MEDIUM_BOSS,
	OBJ_SPECIAL_ENEMY,
	OBJ_ENEMY_BOSS,
	OBJ_RESPOAWN,
	OBJ_GAMEOVER,
	OBJ_CLEAR,
	OBJ_HEAL_ITEM,
	//OBJ_STAGECHANGE,
	//OBJ_STAGE2,
	OBJ_BULLET_ITEM,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_BULLET,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	int BulletData;	//弾の数

};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjHero.h"
#include "ObjBlock.h"
#include "ObjEnemy.h"
#include "CobjBullet.h"
#include "ObjStage.h"
#include "CObjMediumBoss.h"
#include "CObjSpecialEnemy.h"
#include "ObjEnemyBoss.h"
#include "ObjTitle.h"
#include "ObjRespoawn.h"
#include "ObjClear.h"
#include "ObjGameOver.h"
#include "CObjBulletLeft.h"
#include "ObjHealItem.h"
//#include "ObjStageChange.h"
//#include "ObjStage2.h"
#include "ObjBulletItem.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneRespoawn.h"
#include "SceneGameOver.h"
#include "SceneClear.h"
//#include "SceneStageChange.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle  
//-----------------------------------------------