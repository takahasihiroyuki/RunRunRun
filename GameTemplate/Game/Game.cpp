#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "sound/SoundEngine.h"
#include "BoxManager.h"
#include "Tube.h"
#include "TubeManager.h"
#include "GroundWhiteManager.h"
#include "Score.h"
#include "UI.h"
#include "Apple.h"


//!!!!!!!!!!!!!!!!!!!!
Game::Game()
{
	damageSE = NewGO<SoundSource>(1);
	//�v���C���[�̃I�u�W�F�N�g�����B
	player = NewGO<Player>(0, "player");

	//�Q�[���J�����̃I�u�W�F�N�g�����B
	gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//�w�i�̃I�u�W�F�N�g�����B
	backGround = NewGO<BackGround>(0);

	tubeManager = NewGO<TubeManager>(0);
	//groundWhiteManager = NewGO<GroundWhiteManager>(0);

	//�^�C�g����BGM��ǂݍ��ށB


	//�^�C�g����BGM���Đ�����B
	gameBGM = NewGO<SoundSource>(0);
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/audiostock_1002913.wav");//BGM
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/audiostock_18003.wav");//SE

	gameBGM->Init(0);

	/*m_groundWhiteManager= NewGO<GroundWhiteManager>(0);*/
	gameBGM->Play(true);
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	m_ui = NewGO<UI>(0);

	//apple=NewGO<Apple>(0);
}

Game::~Game()
{
	gameBGM->Stop();
	DeleteGO(tubeManager);
	DeleteGO(gameCamera);
	DeleteGO(gameBGM);
	DeleteGO(damageSE);
	DeleteGO(player);
	DeleteGO(backGround);
	DeleteGO(m_ui);
	m_score = NewGO<Score>(0);
	m_score->SetScore(/*tube->m_score*/m_time);
}

//�����蔻��֐�
void Game::Hit()
{
	m_isHit = false;
	const auto& Collision = g_collisionObjectManager->FindCollisionObjects("collisionobject");
	for (auto collision : Collision)
	{
		if (collision->IsHit(player->characterController))
		{
			   m_isHit = true;
		}
		}


	if (m_isHit == true)//����������
	{
	
		damageSE->Init(1);
		damageSE->Play(true);
		player->damage+=0.06;
		player->nowHP -= player->damage;

		seState = true;
		if (player->nowHP<=0) {
			/*gameBGM->Release();*/
			DeleteGO(this);
		}
	}
	else 
	{
		if (seState == true)
		{
			damageSE->Stop();
			seState = false;
		}
	}
}

//���x�̕ω����m���߂�
void Game::SpeadTest()
{
	test++;
	for (int i = 1; i < 11; i++) {
		if (test == 100 * i) {
			if (i % 2 == 1) {
				a = tubeManager->tube[0][0]->/*m_t*/speadUP;
			}
			if (i % 2 == 0)
			{
				b = tubeManager->tube[0][0]->/*m_t*/speadUP;
				testA[i/2 - 1] = b-a;
			}
		}
	}

}

void Game::TimeManager()
{
	m_time +=g_gameTime->GetFrameDeltaTime()/2/*/5*/;
}


void Game::Render(RenderContext& rc)
{
	m_fontRender.Draw(rc);
}


//�X�V�����B
void Game::Update()
{
	//���Ԃ��Ǘ�
	TimeManager();

	//�X�s�[�h�̕ω����m�F���邽�߂̊֐��B
	SpeadTest();

	//
	//setScore = time;
	tubeManager->Update();

	//�v���C���[�N���X�̃X�s�[�h�A�b�v������
	player->speadUP =  log(m_time)*0.010;

	//�����蔻��
	Hit();

	
}