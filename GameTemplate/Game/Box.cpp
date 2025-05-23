#include "stdafx.h"
#include "Box.h"

bool Box::Start()
{
	m_position = { 0.0f,0.0f,0.0f };
	m_size = { 40.0f,40.0f,40.0f };
	m_physicsGhostObject.CreateBox(m_position, Quaternion::Identity, m_size);
	return false;
}

void Box::Update()
{
}
