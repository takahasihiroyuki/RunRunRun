#pragma once
#include "sound/SoundSource.h"

//�^�C�g���B
class Title : public IGameObject
{
public:
	Title();
	~Title();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender spriteRender;
	SoundSource* gameBGM;
	SoundSource* titleBGM;			//�^�C�g����BGM�B
	SoundSource* se;

};
