#pragma once
class Player;
class Box : public IGameObject
{
public:
	bool Start();
	void Update();
	Vector3 m_position;
	Vector3 m_size;
	//�S�[�X�g�I�u�W�F�N�g�B
	PhysicsGhostObject m_physicsGhostObject;
};

