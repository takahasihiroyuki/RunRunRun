#pragma once
class Title;
class Score : public IGameObject
{
public:
	Score();
	~Score();
	void Update();
	void Render(RenderContext& rc);
	void SetScore(float inScore);
	float m_score = 0;
	SoundSource* gameBGM;
	FontRender m_fontRender;
	SpriteRender spriteRender;
	SoundSource* titleBGM;			//タイトルのBGM。
	Title* title;
	SoundSource* se;
};

