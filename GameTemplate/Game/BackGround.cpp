#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	Vector3 size = { 100.0f,1.0f,100.0f };
	modelRender.Init("Assets/modelData/ground brack.tkm");
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
	modelRender.SetScale(size);
	modelRender.Update();
}

BackGround::~BackGround()
{

}

void BackGround::Update()
{
	//Vector3 scale = {2.0f,2.0f,2.0f};
	/*modelRender.SetScale(scale);*/
}

void BackGround::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}