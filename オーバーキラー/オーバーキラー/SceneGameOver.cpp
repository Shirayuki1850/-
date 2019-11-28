#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameL\SceneObjManager.h"
#include  "GameL\DrawFont.h"
#include "GameL\Audio.h"

using namespace GameL;

#include "SceneGameOver.h"
#include "GameHead.h"

//�R���X�g
CSceneGameOver::CSceneGameOver()
{

}

//�f�X�g
CSceneGameOver::~CSceneGameOver()
{

}



//������
void CSceneGameOver::InitScene()
{
	Font::SetStrTex(L"GAME�@OVER :PUSH ENTERKEY RESPOAWN");

	//Music loading
	Audio::LoadAudio(2, L"BGMSE/�Q�[���I�[�o�[.wav", SOUND_TYPE::BACK_MUSIC);

	//Volume 1.0 return
	float v = Audio::VolumeMaster(-0.8f);
	v = Audio::VolumeMaster((1.0 - v));

	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);

	//Music Start
	Audio::Start(2);

	
}

//���s
void CSceneGameOver::Scene()
{

}