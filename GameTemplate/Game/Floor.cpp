#include "stdafx.h"
#include "Floor.h"

Floor::Floor()
{
	modelRender.Init("Assets/modelData/ground.tkm");
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
	modelRender.Update();
}

Floor::~Floor()
{
}

void Floor::Update()
{

}

void Floor::Render(RenderContext& rc)
{
}
