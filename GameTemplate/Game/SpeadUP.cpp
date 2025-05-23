#include "stdafx.h"
#include "SpeadUP.h"
#include "Tube.h"

SpeadUP::SpeadUP()
{
	FindGO<Tube>;
}

void SpeadUP::Update()
{
	m_timer += g_gameTime->GetFrameDeltaTime();
	tube->speadUP = (log(m_timer) * 0.15);
}
