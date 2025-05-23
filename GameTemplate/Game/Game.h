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

//Gameシーンを管理するクラス。
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//更新処理。
	void Update();
	void Hit();//当たり判定
	void SpeadTest();//スピードテスト
	void TimeManager();//時間管理
	////Tubeを作成
	//void MakeTube();
	void Render(RenderContext& rc);

	bool m_isHit = false;//
	float m_objectscale = 40.0f;//3DSmaxの座標とここの座標を合わせるための数。
	//float tyubVvalidRange;//チューブの角度の有効範囲
	//bool makeTube[3];
	//float tubeMakeSize=20.0f;//Tubeがこのサイズの時に次のTubeを作成する。
	//bool newgocheck_tube[3] = { false,false,false };
	//bool a[3] = { true,true,true };
	int test = 0;
	float a = 0;
	float b = 0;
	float testA[10] = { 0.0f,0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, };
	float setScore;
	float m_time=1;
	bool seState=false;
	Player* player;			//プレイヤー。
	GameCamera* gameCamera;			//ゲームカメラ。
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

