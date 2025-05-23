#include "stdafx.h"
#include "Apple.h"

Apple::Apple()
{
	int i = 0;
	modelRender.Init("Assets/modelData/apple.tkm");
	modelRender.SetPosition(m_potision);
	modelRender.SetScale(m_scale);
}

Apple::~Apple()
{

}

void Apple::Update()
{


}

void Apple::Render(RenderContext& rc)
{
		modelRender.Draw(rc);
}
