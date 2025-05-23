#include "stdafx.h"
#include "Tube.h"
#include <time.h> 
#include"Game.h"


Tube::Tube()
{
	//ランダム
	srand(time(nullptr));


	//ランダムで色を決める
	SetColour();
	//physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
	//setrot=rand()/*0*/;
}

Tube::~Tube()
{
	/*DeleteGO(collisionObject);*/
}

void Tube::Update()
{
	game = FindGO<Game>("game");

	if (scale <= stopSize) //チューブの大きさが100以上の時、プログラムを止める。
	{
		SetScale();//大きさを設定

		SetRot();//向きを設定

		modelRender.SetPosition(pos);//

		CreateGhostObject();

		modelRender.Update();

		//コメントアウトする。
		PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	}
}

void Tube::SetScale()
{

	if(game!=nullptr){
		speadUP = log(game->m_time) / 20/*15*/;
	}
	
	scale *=InitialSpeed+speadUP*0.3;

	setscale = { scale,scale,scale };

	m_matrix.MakeScaling(setscale);

	modelRender.SetScale(setscale);
}

void Tube::SetRot()
{
	rot.SetRotationDegY(setrot);
	ghostRot.SetRotationDegY(0);
	modelRender.SetRotation(rot);
}

void Tube::Render(RenderContext& rc)
{
	/*m_fontRender.Draw(rc);*/
	modelRender.Draw(rc);
}

void Tube::CreateGhostObject()
{
	collisionObject = NewGO<CollisionObject>(0, "collisionobject");
	//physicsGhostObject.CreateMesh(pos, ghostRot, modelRender.GetModel(), modelRender.GetWorldMatrix(0));
	collisionObject->CreateMesh(pos, ghostRot, modelRender.GetModel(), /*m_matrix*/modelRender.GetWorldMatrix(0));
	/*collisionObject->SetIsEnableAutoDelete(false);*/
}

void Tube::SetColour()
{
	switch (rand() % 4)
	{
	case tubeColour::RED_TUBE:
		modelRender.Init
		(
			"Assets/modelData/tube.tkm",
			nullptr,
			0,
			enModelUpAxisZ,
			true,
			1
		);
		break;

	case tubeColour::YELLOW_TUBE:
		modelRender.Init
		(
			"Assets/modelData/tubeYellow.tkm",
			nullptr,
			0,
			enModelUpAxisZ,
			true,
			1
		);
		break;

	case tubeColour::BULUE_TUBE:
		modelRender.Init
		(
			"Assets/modelData/tubeBlue.tkm",
			nullptr,
			0,
			enModelUpAxisZ,
			true,
			1
		);
		break;

	case tubeColour::PINK_TUBE:
		modelRender.Init
		(
			"Assets/modelData/tubePink.tkm",
			nullptr,
			0,
			enModelUpAxisZ,
			true,
			1
		);
		break;

	default:
		break;
	}
}
