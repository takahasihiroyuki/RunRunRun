#pragma once
class Player;
class Box : public IGameObject
{
public:
	bool Start();
	void Update();
	Vector3 m_position;
	Vector3 m_size;
	//ゴーストオブジェクト。
	PhysicsGhostObject m_physicsGhostObject;
};

