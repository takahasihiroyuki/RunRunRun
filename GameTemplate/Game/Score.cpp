#include "stdafx.h"
#include "Score.h"
#include "Title.h"

Score::Score()
{
	spriteRender.Init("Assets/ModelData/Score.dds", 1280.0f * 1.5, 720.0f * 1.5);
	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/audiostock_972782.wav");
	//タイトルのBGMを再生する。
	gameBGM = NewGO<SoundSource>(0);
	se = NewGO<SoundSource>(0);
	se->Init(4);
	gameBGM->Init(3);
	gameBGM->Play(true);
}

Score::~Score()
{
	//DeleteGO(titleBGM);
	DeleteGO(gameBGM);
}

void Score::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		se->Play(false);
		NewGO<Title>(0, "Title");
		DeleteGO(this);
	}
	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"%d", int(m_score*10));
	m_fontRender.SetText(wcsbuf);
}

void Score::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
	m_fontRender.Draw(rc);
}

void Score::SetScore(float inScore)
{
	m_score = inScore;
}


