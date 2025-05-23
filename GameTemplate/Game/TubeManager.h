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
	//Tube���쐬
	void MakeTube();
	void PatternManager(int num);
	void Pattern0(int num);
	void Pattern1(int num);
	void Pattern2(int num);
	void SpeadUP(int num);
	/*void Hit();*/
	void PatternSetRot(int num, int numofTube);
	float speadUP=1.0f;
	float tyubVvalidRange;//�`���[�u�̊p�x�̗L���͈�
	bool makeTube[10];
	int color = 0;
	float tubeMakeSize = 2.0f;//Tube�����̃T�C�Y�̎��Ɏ���Tube���쐬����B
	bool newgocheck_tube[10] = { false,false,false,false,false,false,false,false,false,false };
	float tubeDelete = 100.0f;//Tube�����̑傫���ɂȂ�����true
	float InitialSpeed = 1.01f;//�������x
	bool tubeDeleteState = false;
	bool secondNewGOCheck = false;
	/*bool m_isHit=false;*/
	int numberofTube=10;//
	int previousTubePattern;
	int pattern0State = 0;//�p�^�[��0�̌��������߂�i�p�^�[��0���A���ő����Ƃ��E��1�񂷂�����1�񂷂�������ς��Ȃ��A�̂ǂꂩ�ɂ���j
	int PatternState[10] = { 0,0,0,0,0,0,0,0,0,0 };
	Tube* tube[10][4];
	Player* m_player;
};