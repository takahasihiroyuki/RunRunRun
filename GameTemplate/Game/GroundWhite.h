#pragma once
class Tube;
class GroundWhite : public IGameObject
{
public:
	GroundWhite();
	~GroundWhite();
	void Update();
	void SetScale();
	void Render(RenderContext& rc);

	ModelRender modelRender;
	//PhysicsStaticObject physicsStaticObject;
	//Tube* tube;
	float scale=1;
	bool newgoIfSwitchi = false;
	float speadUP=1;
	float InitialSpeed = 1.01f;//èâä˙ë¨ìx
	float m_x=0;
	Vector3 size;
};

