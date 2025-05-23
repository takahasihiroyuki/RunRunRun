#pragma once
class Box;
class Game;
class BoxManager : public IGameObject
{
public:
	BoxManager();
	~BoxManager();
	bool Start();
	void Update();
	
	Box* box[4][10];
	Game* game;

};

