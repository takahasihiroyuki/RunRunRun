#pragma once
class GroundWhite;
class Tube;
class GroundWhiteManager : public IGameObject
{
public:
	GroundWhiteManager();
	//~GroundWhiteManager();
	void Delete(int num);
	//bool Start();
	void Update();
	void MakeGround();

	Tube* m_tube;
	GroundWhite* groundWhite[10];

	Vector3 m_scale;
	bool newgocheck[10] = { false,false,false,false,false,false,false,false,false,false };
	float groundMakeSize = 2.0;
	bool groundDeleteState = false;
};

