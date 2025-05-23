#include "stdafx.h"
#include "TubeManager.h"
#include "Player.h"
#include "Tube.h"

TubeManager::TubeManager()
{
	//一番初めのチューブを作成する。
	for (int i = 0; i < 3; i++) {
		tube[0][i] = NewGO<Tube>(0, "tube");
	}
	//回転を設定する。
	tube[0][0]->setrot = (rand() % 5 + 1) * 72;
	tube[0][1]->setrot = tube[0][0]->setrot + 72;
	tube[0][2]->setrot = tube[0][1]->setrot + 72;
	tube[0][0] = FindGO<Tube>("tube");
	//ステート設定
	PatternState[0] = 0;
	newgocheck_tube[0] = true;
	//m_player = NewGO<Player>(0, "playler");
	
}

TubeManager::~TubeManager()
{
	for (int i = 0; i < 10; i++)
	{
		if (PatternState[i]=!nullptr) {

			switch (PatternState[i])
			{
			case 0://パターン0の時に3つ消す
				/*if (tubeDeleteState == true) {*/
					for (int j = 0; j < 3; j++) {
						DeleteGO(tube[i][j]);
					}
			/*	}*/
				break;
			case 1://パターン1の時に4つ消す
			/*	if (tubeDeleteState == true) {*/
					for (int j = 0; j < 4; j++) {
						DeleteGO(tube[i][j]);
					}
	/*			}*/
				break;
			case 2://パターン2の時に2つ消す
		/*		if (tubeDeleteState == true) {*/
					for (int j = 0; j < 2; j++) {
						DeleteGO(tube[i][j]);
					}
			/*	}*/
				break;
			default:
				break;
			}
		}
	}
}

bool TubeManager::Start()
{
	//m_player = FindGO<Player>("playler");
	return false;
}


void TubeManager::DeleteTube(int nextnum)
{
	if (nextnum == 9) {
		tubeDeleteState = true;
	}
	if (nextnum == 10)
	{
		nextnum = 0;
	}
	switch (PatternState[nextnum])
	{
	case 0://パターン0の時に3つ消す
		if (tubeDeleteState == true) {
			for (int k = 0; k < 3; k++) {
				DeleteGO(tube[nextnum][k]);
			}
		}
		break;
	case 1://パターン1の時に4つ消す
		if (tubeDeleteState == true) {
			for (int k = 0; k < 4; k++) {
				DeleteGO(tube[nextnum][k]);
			}
		}
		break;
	case 2://パターン2の時に2つ消す
		if (tubeDeleteState == true) {
			for (int k = 0; k < 2; k++) {
				DeleteGO(tube[nextnum][k]);
			}
		}
		break;
	default:
		break;
	}
	//for (int i = 0; i < 10; i++)
	//{
	//	if (newgocheck_tube[i] == true) {//まだNewGOできていないクラスの、メンバ変数を判別しないようにする。
	//		if (tube[i][0]->scale >= tubeDelete)//i番目が大きくなったら、それを消す。
	//		{
	//			newgocheck_tube[i] = false;
	//			/*tube[i]->tubeDelete = false;*/
	//			tube[i][0]->newgoIfSwitchi = false;
	//			DeleteGO(tube[i]);
	//		}
	//	}
	//}
}

void TubeManager::MakeTube() {
	for (int i = 0; i < 10; i++)
	{
		int nextnum = i + 1;
		if (nextnum == 10)
		{
			nextnum = 0;
		}
		if (newgocheck_tube[i] == true) {//まだNewGOできていないクラスの、メンバ変数を判別しないようにする。
			///*if(a[i] == true) {*/
			if (tube[i][0]->scale >= tubeMakeSize &&//i番目が一定の大きさになったら、。i+1番目をNewGOする。
				tube[i][0]->newgoIfSwitchi == false) //これを何回も実行しないようにする。
			{
				DeleteTube(nextnum);
				
				/*if (i==9) {
					tubeDeleteState = true;
				}
				if (tubeDeleteState == true) {
					for (int k= 0; k < 3; k++) {
						DeleteGO(tube[nextnum][k]);
					}
				}*/
				secondNewGOCheck = true;
				PatternManager(nextnum);
				
				/*tube[i][0]->color = color;*/
			/*	for (int k = 0; k < 4; i++) {
					tube[nextnum][k] = NewGO<Tube>(0, "tube");
				}*/
				newgocheck_tube[nextnum] = true;
			/*	tube[nextnum] = FindGO<Tube>("tube");*/
				///*a[i] = false;*/
				tube[i][0]->newgoIfSwitchi = true;
				newgocheck_tube[i] = false;
			}
			///*}*/
		}
	}
}

void TubeManager::PatternManager(int num)
{
	int patternNum = rand() % 3;
	switch (patternNum)
	{
	case 0:
		Pattern0(num);
		break;
	case 1:
		Pattern1(num);
		break;
	case 2:
		Pattern2(num);
		break;
	default:
		break;
	}


}

void TubeManager::Pattern0(int num)//チューブ３つ
{
	for (int i = 0; i < 3; i++) {
		tube[num][i] = NewGO<Tube>(0, "tube");
	}
	if (secondNewGOCheck == true) 
	{
		int randum0 = rand() % 3;
		int randum1 = rand() % 2;
		int randum2 = rand() % 4;
		int previousNum = num - 1;
		if (previousNum == -1)
		{
			previousNum = 9;
		}
		previousTubePattern = PatternState[previousNum];
		switch (previousTubePattern)
		{
		case 0:
			switch (randum0)
			{
			case 0:
				tube[num][0]->setrot = tube[previousNum][0]->setrot + 72;
				break;
			case 1:
				tube[num][0]->setrot = tube[previousNum][0]->setrot - 72;
				break;
			case 2:
				tube[num][0]->setrot = tube[previousNum][0]->setrot;
				break;
			default:
				break;
			}
			break;

		case 1:
			switch (randum1)
			{
			case 0:
				tube[num][0]->setrot = tube[previousNum][0]->setrot + 72;
				break;
			case 1:
				tube[num][0]->setrot = tube[previousNum][0]->setrot;
				break;
			default:
				break;
			}
			break;

		case 2:
			switch (randum1)
			{
			case 0:
				tube[num][0]->setrot = tube[previousNum][0]->setrot;
				break;
			case 1:
				tube[num][0]->setrot = tube[previousNum][0]->setrot + 72;
				break;

			case 2:
				tube[num][0]->setrot = tube[previousNum][0]->setrot + 72 * 3;
				break;

			case 3:
				tube[num][0]->setrot = tube[previousNum][0]->setrot + 72 * 4;
				break;
			}
			break;

		default:
			break;
		}


		//大きさを合わせる。
		for (int j = 1; j < 3; j++) {
			tube[num][j]->scale = tube[num][0]->scale;
		}


		tube[num][1]->setrot = tube[num][0]->setrot + 72;
		tube[num][2]->setrot = tube[num][1]->setrot + 72;
	}
	else {
		tube[num][0]->setrot = (rand() % 5 + 1) * 72;
		tube[num][1]->setrot = tube[num][0]->setrot + 72;
		tube[num][2]->setrot = tube[num][1]->setrot + 72;
	}
	PatternState[num] = 0;
}

void TubeManager::Pattern1(int num)
{
	for (int i = 0; i < 4; i++) 
	{
		tube[num][i] = NewGO<Tube>(0, "tube");
	}
	if (secondNewGOCheck == true)
	{
		
			int randum0 = rand() % 2;
			int randum2 = rand() % 3;
			int previousNum = num - 1;
			if (previousNum == -1)
			{
				previousNum = 9;
			}
			previousTubePattern = PatternState[previousNum];

			switch (previousTubePattern)
			{
			case 0:
				switch (randum0)
				{
				case 0:
					tube[num][0]->setrot = tube[previousNum][0]->setrot;
					break;
				case 1:
					tube[num][0]->setrot = tube[previousNum][0]->setrot - 72;
					break;
				}
				break;
			case 1:
				tube[num][0]->setrot = tube[previousNum][0]->setrot;
				break;

			case 2:
				switch (randum2)
				{
				case 0:
					tube[num][0]->setrot = tube[previousNum][0]->setrot;
					break;
				case 1:
					tube[num][0]->setrot = tube[previousNum][0]->setrot+72*3;
					break;

				case 2:
					tube[num][0]->setrot = tube[previousNum][0]->setrot + 72 * 4;
					break;
				}
				break;

			default:
				break;
			}
			//大きさを合わせる。
			for (int j = 1; j < 4; j++) {
				tube[num][j]->scale = tube[num][0]->scale;
			}
			//残りの角度を決める
			tube[num][1]->setrot = tube[num][0]->setrot + 72;
			tube[num][2]->setrot = tube[num][1]->setrot + 72;
			tube[num][3]->setrot = tube[num][2]->setrot + 72;
			PatternState[num] = 1;
	}
	/*else {
		tube[num][0]->setrot = (rand() % 5 + 1) * 72;
		tube[num][1]->setrot = tube[num][0]->setrot + 72;
		tube[num][2]->setrot = tube[num][1]->setrot + 72;
		tube[num][3]->setrot = tube[num][2]->setrot + 72;
	}*/
}

void TubeManager::Pattern2(int num)//チューブを二つ
{
	for (int i = 0; i < 2; i++)
	{
		tube[num][i] = NewGO<Tube>(0, "tube");
	}
	if (secondNewGOCheck == true)
	{

		int randum0 = rand() % 4;
		int randum1 = rand() % 3;
		int randum2 = rand()%3;

		int previousNum = num - 1;
		if (previousNum == -1)
		{
			previousNum = 9;
		}
		previousTubePattern = PatternState[previousNum];

		switch (previousTubePattern)
		{
		case 0:
			switch (randum0)
			{
			case 0:
				tube[num][0]->setrot = tube[previousNum][0]->setrot;
				break;
			case 1:
				tube[num][0]->setrot = tube[previousNum][0]->setrot+72;
				break;

			case 2:
				tube[num][0]->setrot = tube[previousNum][0]->setrot + 72*2;
				break;

			case 3:
				tube[num][0]->setrot = tube[previousNum][0]->setrot + 72*4;
				break;
			}
			break;
		case 1:
			switch (randum1)
			{
			case 0:
				tube[num][0]->setrot = tube[previousNum][0]->setrot;
				break;
			case 1:
				tube[num][0]->setrot = tube[previousNum][0]->setrot + 72;
				break;

			case 2:
				tube[num][0]->setrot = tube[previousNum][0]->setrot + 72 * 2;
				break;
			}
			break;
		case 2:
			switch (randum2)
			{
			case 0:
				tube[num][0]->setrot = tube[previousNum][0]->setrot;
				break;
			case 1:
				tube[num][0]->setrot = tube[previousNum][0]->setrot + 72;
				break;

			case 2:
				tube[num][0]->setrot = tube[previousNum][0]->setrot + 72 * 4;
				break;
			}
			break;
		default:
			break;
		}
		//大きさを合わせる。
		for (int j = 1; j < 2; j++) {
			tube[num][j]->scale = tube[num][0]->scale;
		}
		tube[num][1]->setrot = tube[num][0]->setrot + 72;
		PatternState[num] = 2;
	}
}

//void TubeManager::Hit()
//{
//	 m_isHit = false;
//	for (int i = 0; i < 10; i++) {
//		if (newgocheck_tube[i] == true) {//まだNewGOできていないクラスを判別しないようにする。
//			switch (PatternState[i]) {
//			case 0:
//				for (int j = 0; j < 3; j++) {
//					PhysicsWorld::GetInstance()->ContactTest(m_player->characterController, [&](const btCollisionObject& contactObject) {
//						if (tube[i][j]->physicsGhostObject.IsSelf(contactObject) == true)
//						{
//							//m_physicsGhostObjectとぶつかった。
//							//フラグをtrueにする。
//							m_isHit = true;
//						}
//						});
//				}
//			case 1:
//				for (int j = 0; j < 4; j++) {
//					PhysicsWorld::GetInstance()->ContactTest(m_player->characterController, [&](const btCollisionObject& contactObject) {
//						if (tube[i][j]->physicsGhostObject.IsSelf(contactObject) == true) {
//							//m_physicsGhostObjectとぶつかった。
//							//フラグをtrueにする。
//							m_isHit = true;
//						}
//						});
//				}
//			case 2:
//				for (int j = 0; j < 2; j++) {
//					PhysicsWorld::GetInstance()->ContactTest(m_player->characterController, [&](const btCollisionObject& contactObject) {
//						if (tube[i][j]->physicsGhostObject.IsSelf(contactObject) == true) {
//							//m_physicsGhostObjectとぶつかった。
//							//フラグをtrueにする。
//							m_isHit = true;
//						}
//						});
//				}
//			}
//		}
//	}
//}
//
//void TubeManager::PatternSetRot(int num,int numofTube)
//{
//	for(int i = 1; i < numofTube; i++)
//	tube[num][i]->setrot = tube[num][0]->setrot + 72;
//}




void TubeManager::Update()
{
	//Hit();
	/*tube[0][0]->speadUP = 0;*/
	/*tube[0][0]->speadUP +=d g_gameTime->GetFrameDeltaTime();*/
	//speadUP += 0.005;
	MakeTube();
	//DeleteTube();
}