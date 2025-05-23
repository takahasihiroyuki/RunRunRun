#pragma once
class Player;

class UI : public IGameObject
{
public:
	UI();
	~UI();
	void Update();
	void HP();
	void Render(RenderContext& rc);
	Vector3 m_OutsideScale{ 0.0f,0.855f,0.0f };
	Vector3 m_InsideScale{ 1.02f,1.0f,1.0f };

	SpriteRender hpBarInSide;
	SpriteRender hpBarOutSide;
	Player* m_player;

};

