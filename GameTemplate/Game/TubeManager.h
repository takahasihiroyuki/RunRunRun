#pragma once
class Tube;
class Player;
class TubeManager : public IGameObject
{
public:
	TubeManager();
	~TubeManager();
	bool Start();
	void Update();
	void DeleteTube(int num);
	//Tubeを作成
	void MakeTube();
	void PatternManager(int num);
	void Pattern0(int num);
	void Pattern1(int num);
	void Pattern2(int num);
	void SpeadUP(int num);
	/*void Hit();*/
	void PatternSetRot(int num, int numofTube);
	float speadUP=1.0f;
	float tyubVvalidRange;//チューブの角度の有効範囲
	bool makeTube[10];
	int color = 0;
	float tubeMakeSize = 2.0f;//Tubeがこのサイズの時に次のTubeを作成する。
	bool newgocheck_tube[10] = { false,false,false,false,false,false,false,false,false,false };
	float tubeDelete = 100.0f;//Tubeが一定の大きさになったらtrue
	float InitialSpeed = 1.01f;//初期速度
	bool tubeDeleteState = false;
	bool secondNewGOCheck = false;
	/*bool m_isHit=false;*/
	int numberofTube=10;//
	int previousTubePattern;
	int pattern0State = 0;//パターン0の向きを決める（パターン0が連続で続くとき右に1回すか左に1回すか向きを変えない、のどれかにする）
	int PatternState[10] = { 0,0,0,0,0,0,0,0,0,0 };
	Tube* tube[10][4];
	Player* m_player;
};