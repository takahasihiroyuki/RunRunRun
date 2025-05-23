#pragma once
#include"sound/SoundSource.h"

class Player;
class GameCamera;
class BackGround;
class BoxManager;
class Tube;
class TubeManager;
class SpeadUP;
class GroundWhiteManager;
class Score;
class UI;
class Apple;

//Game�V�[�����Ǘ�����N���X�B
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//�X�V�����B
	void Update();
	void Hit();//�����蔻��
	void SpeadTest();//�X�s�[�h�e�X�g
	void TimeManager();//���ԊǗ�
	////Tube���쐬
	//void MakeTube();
	void Render(RenderContext& rc);

	bool m_isHit = false;//
	float m_objectscale = 40.0f;//3DSmax�̍��W�Ƃ����̍��W�����킹�邽�߂̐��B
	//float tyubVvalidRange;//�`���[�u�̊p�x�̗L���͈�
	//bool makeTube[3];
	//float tubeMakeSize=20.0f;//Tube�����̃T�C�Y�̎��Ɏ���Tube���쐬����B
	//bool newgocheck_tube[3] = { false,false,false };
	//bool a[3] = { true,true,true };
	int test = 0;
	float a = 0;
	float b = 0;
	float testA[10] = { 0.0f,0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, };
	float setScore;
	float m_time=1;
	bool seState=false;
	Player* player;			//�v���C���[�B
	GameCamera* gameCamera;			//�Q�[���J�����B
	BackGround* backGround;
	SoundSource* gameBGM;
	SoundSource* damageSE;
	BoxManager* boxManager;
	//Tube* tube;
	TubeManager* tubeManager;
	SpeadUP* speadUP;
	GroundWhiteManager* m_groundWhiteManager;
	FontRender m_fontRender;
	Score* m_score;
	UI* m_ui;
	Apple* apple;
};

