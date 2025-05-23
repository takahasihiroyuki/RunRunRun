#pragma once
class Tube;
class SpeadUP : public IGameObject
{
public:
	SpeadUP();
	void Update();
	Tube* tube;
	float m_timer;
};

