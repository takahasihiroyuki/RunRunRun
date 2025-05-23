#include "stdafx.h"
#include "UI.h"
#include"Player.h"

UI::UI()
{

	//HPバー(外側)
	hpBarOutSide.Init("Assets/modelData/HPbarOUT.DDS", 1024, 128);
	hpBarOutSide.SetPivot(Vector2(0.0f, 0.5f));
	hpBarOutSide.SetPosition(Vector3(-860.0f, 450.0f, 0.0f));
	hpBarOutSide.SetScale(m_InsideScale);

	////HPバー（内側）
	hpBarInSide.Init("Assets/modelData/HPbar.DDS", 1024, 128);
	hpBarInSide.SetPivot(Vector2(0.0f, 0.5f));
	hpBarInSide.SetPosition(Vector3(-850.0f, 450.0f, 0.0f));
	hpBarInSide.SetScale(Vector3{ 0.35f, 0.5f, 1.0f });

	m_player = FindGO<Player>("player");

}

UI::~UI()
{

}

void UI::Update()
{
	m_OutsideScale.x = m_player->nowHP / m_player->maxHP;
	hpBarInSide.SetScale(m_OutsideScale);

	hpBarOutSide.Update();
	hpBarInSide.Update();

	//player->
}

void UI::HP()
{
	//spriterender.Init();
}

void UI::Render(RenderContext& rc)
{
	hpBarOutSide.Draw(rc);
	hpBarInSide.Draw(rc);
}
