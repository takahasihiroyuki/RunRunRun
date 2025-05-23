#pragma once
class Apple : public IGameObject
{
public:
	Apple();
	~Apple();
	void Update();
	ModelRender modelRender;	//モデルレンダ―。
	void Render(RenderContext& rc);

	Vector3 m_scale{ 10.0f,10.0f,10.0f };
	Vector3 m_potision={0.0f,0.0f,0.0f};
};

