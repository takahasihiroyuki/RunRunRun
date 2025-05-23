#include "stdafx.h"
#include "BoxManager.h"
#include "Box.h"
#include "Game.h"

BoxManager::BoxManager()
{

}

BoxManager::~BoxManager()
{
}

bool BoxManager::Start()
{
	game = FindGO<Game>("game");
	/*for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			box[i][j] = NewGO<Box>(0, "box");
			box[i][j] = FindGO <Box>("box");
			box[i][j]->m_position.x = (i * game->g_objectscale) + box[i][j]->m_position.x;
			box[i][j]->m_position.z = (j * game->g_objectscale) + box[i][j]->m_position.z;
		}
	}*/
	return false;
}

void BoxManager::Update()
{

}
