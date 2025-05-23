#pragma once
class Game;
class Tube : public IGameObject
{
public:
	Tube();
	~Tube();
	void Update();
	void SetScale();
	void SetRot();
	void Render(RenderContext& rc);
	void CreateGhostObject();
	void SetColour();
	ModelRender modelRender;
	PhysicsStaticObject physicsStaticObject;
	PhysicsGhostObject physicsGhostObject;
	Model model;
	float setrot;
	float scale = 1.0f;
	float speadUP = 0;
	float m_t;
	float InitialSpeed=1.01f;//èâä˙ë¨ìx
	float stopSize = 200;
	int color = 0;
	bool wait;
	enum tubeColour {
		YELLOW_TUBE,
		BULUE_TUBE,
		PINK_TUBE,
		RED_TUBE
	};
	Vector3 initPos{ 0.0f,0.0f,0.0f };
	/*static float speadUP;*/
	//bool tubeDelete = false;//TubeÇ™àÍíËÇÃëÂÇ´Ç≥Ç…Ç»Ç¡ÇΩÇÁtrue
	bool newgoIfSwitchi=false;
	float m_score;
	Vector3 setscale;
	Vector3 pos{ 0.0f,0.0f,0.0f };
	Quaternion rot{ 0.0f,0.0f,0.0f,0.0f };
	Quaternion ghostRot{ 0.0f,0.0f,0.0f,0.0f };
	Game* game;
	CollisionObject* collisionObject;
	Matrix m_matrix;
	//FontRender m_fontRender;
};

