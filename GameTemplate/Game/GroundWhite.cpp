#include "stdafx.h"
#include "GroundWhite.h"
#include "Tube.h"

static float t=1;
GroundWhite::GroundWhite()
{
	/*tube = NewGO<Tube>(0, "tube");*/
	//FindGO<Tube>;
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	modelRender.Init("Assets/modelData/ground white.tkm");
	//physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}

GroundWhite::~GroundWhite()
{

}

void GroundWhite::Update()
{
	//Vector3 scale = {2.0f,2.0f,2.0f};
	/*modelRender.SetScale(scale);*/
	SetScale();
	modelRender.Update();
}

void GroundWhite::SetScale()
{

	/*speadUP = log(tube->m_x)*/;
	scale *= 1.1f/*InitialSpeed + speadUP * 0.3*/;
	size = { scale,1.0f,scale };
	modelRender.SetScale(size);
}

void GroundWhite::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}