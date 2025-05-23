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
	//プレイヤーのオブジェクトを作る。
	player = NewGO<Player>(0, "player");

	//ゲームカメラのオブジェクトを作る。
	gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//背景のオブジェクトを作る。
	backGround = NewGO<BackGround>(0);

	tubeManager = NewGO<TubeManager>(0);
	//groundWhiteManager = NewGO<GroundWhiteManager>(0);

	//タイトルのBGMを読み込む。


	//タイトルのBGMを再生する。
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

//当たり判定関数
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


	if (m_isHit == true)//当たったら
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

//速度の変化を確かめる
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


//更新処理。
void Game::Update()
{
	//時間を管理
	TimeManager();

	//スピードの変化を確認するための関数。
	SpeadTest();

	//
	//setScore = time;
	tubeManager->Update();

	//プレイヤークラスのスピードアップを入れる
	player->speadUP =  log(m_time)*0.010;

	//当たり判定
	Hit();

	
}