#include "stdafx.h"
#include "GroundWhiteManager.h"
#include"GroundWhite.h";
#include "Tube.h";

GroundWhiteManager::GroundWhiteManager()
{
		groundWhite[0] = NewGO<GroundWhite>(0, "groundWhite");
		newgocheck[0] = true;
}

void GroundWhiteManager::Delete(int num)
{
	int nextnum = num + 1;
	if (nextnum == 10)
	{
		nextnum = 0;
	}
	if (num == 9) {
		groundDeleteState = true;
	}
	if (groundDeleteState == true) {
			for (int k = 0; k < 3; k++) {
				DeleteGO(groundWhite[nextnum]);
			}
		}
}

void GroundWhiteManager::Update()
{
	MakeGround();
}

void GroundWhiteManager::MakeGround()
{
	m_tube = FindGO<Tube>("tube");
	m_scale = m_tube->setscale;
	//for (int i = 0; i < 10; i++)
	//{
	//	int nextnum = i + 1;
	//	if (nextnum == 10)
	//	{
	//		nextnum = 0;
	//	}
	//	if (newgocheck[i]==true)
	//	{
	//		groundWhite[i] = FindGO<GroundWhite>("groundwhite");
	//		if (groundWhite[i]->scale >= groundMakeSize &&//i番目が一定の大きさになったら、。i+1番目をNewGOする。
	//			groundWhite[i]->newgoIfSwitchi == false) //これを何回も実行しないようにする。
	//		{
	//			Delete(i);
	//		/*	secondNewGOCheck = true;*/
	//			newgocheck[nextnum] = true;
	//			/*	tube[nextnum] = FindGO<Tube>("tube");*/
	//				///*a[i] = false;*/
	//			groundWhite[i]->newgoIfSwitchi = true;
	//			newgocheck[i] = false;
	//		}
	//	}
	//}
}
