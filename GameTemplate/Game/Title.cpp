#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"

Title::Title()
{
	spriteRender.Init("Assets/ModelData/title.dds", 1280.0f*1.5, 720.0f*1.5);

	////タイトルのBGMを読み込む。
	/*g_soundEngine->ResistWaveFileBank(0, "Assets/sound/audiostock_936123.wav");*/
	////タイトルのBGMを再生する。
	//titleBGM = NewGO<SoundSource>(0);
	//titleBGM->Init(0);
	//titleBGM->Play(true);
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/audiostock_1019713.wav");
	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/audiostock_1249688.wav");
	//タイトルのBGMを再生する。
	gameBGM = NewGO<SoundSource>(0);
	gameBGM->Init(2);
	gameBGM->Play(true);
	se = NewGO<SoundSource>(0);
	se->Init(4);
}

Title::~Title()
{
		DeleteGO(gameBGM);
}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		se->Play(false);
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}

