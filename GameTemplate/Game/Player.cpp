#include "stdafx.h"
#include "Player.h"
#include "TubeManager.h"

Player::Player()
{
	//アニメーションクリップをロードする。
	animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	//ユニティちゃんのモデルを読み込む。
	modelRender.Init("Assets/modelData/unityChan.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

	//キャラコンを初期化する。
	characterController.Init(25.0f, 75.0f, characterController_Initpos);
}

Player::~Player()
{

}

//更新処理。
void Player::Update()
{
	//移動処理。
	Move();

	//回転処理。
	Rotation();

	//ステート管理。
	ManageState();

	//アニメーションの再生。
	PlayAnimation();

	//絵描きさんの更新処理。
	modelRender.Update();
}

void Player::Move()
{
	//xzの移動速度を0.0fにする。
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//左スティックの入力量を取得。
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//カメラの前方向と右方向のベクトルを持ってくる。
	Vector3 forward /*g_camera3D->GetForward();*/;
	Vector3 right/*g_camera3D->GetRight();*/;
	//y方向には移動させない。
	forward.y = 0.0f;
	right.y = 0.0f;

	//左スティックの入力量と120.0fを乗算。
	right .x= stickL.x * 120.0f;
	forward.y= stickL.y * 120.0f;

	//移動速度にスティックの入力量を加算する。
	moveSpeed += right + forward;

	//地面に付いていたら。
	if (position.y==0)
	{
		//重力を無くす。
		moveSpeed.y = 0.0f;
		//Aボタンが押されたら。
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//ジャンプさせる。
			moveSpeed.y = 240.0f;
		}
	}
	//地面に付いていなかったら。
	else
	{
		//重力を発生させる。
		moveSpeed.y -= 2.5f;
	}

	//キャラクターが回る円の角度設定
	theta -= g_pad[0]->GetLStickXF()*(0.10+speadUP);
	//キャラクターのポジションを設定
	position.x = sin(theta)*r;
	position.z = cos(theta)*r;
	
	//実際に映す位置の設定
	renderpos = { sin(theta) * (r + 1000) ,0.0, cos(theta) * (r + 1000) };//映す場所を実際の場所より前にずらす

	//moveSpeed = { (800 + r)* cos(theta) ,0.0f,-(800 + r)* sin(theta) };//ポジションの関数の導関数

	//
	///*if (g_pad[0]->GetLStickXF() > 0)
	//{
	//	moveSpeed = { -(renderpos.x) + position.x,moveSpeed.y, -(renderpos.z) + position.z };
	//}
	//moveSpeed = { renderpos.x - previouspos.x ,renderpos.y - previouspos.y ,renderpos.z - previouspos.z };*/
	//characterController.Execute(moveSpeed /*renderpos*/, 1.0f / 60.0f);
	characterController.Execute(theta,moveSpeed, 1.0f / 60.0f);
	//characterController.Execute(/*theta,*/ moveSpeed, 1.0f / 60.0f);
	/*if (g_pad[0]->GetLStickXF() < 0) {
		characterController.SetPosition({ sin(theta+0.1f) * (r + 1000) ,0.0, cos(theta+0.1f) * (r + 1000) });
	}
	if (g_pad[0]->GetLStickXF() >0) {
		characterController.SetPosition({ sin(theta - 0.1f) * (r + 1000) ,0.0, cos(theta - 0.1f) * (r + 1000) });
	}
	if (g_pad[0]->GetLStickXF() == 0) {
		characterController.SetPosition(renderpos);
	}*/
	playerRot.SetRotationY(theta);
	modelRender.SetScale({2.0f,2.0f,2.0f});
	modelRender.SetRotation(playerRot);
	modelRender.SetPosition(characterController.GetPosition()/*renderpos*/);
	previouspos = renderpos;
}

void Player::Rotation()
{
	////xかzの移動速度があったら(スティックの入力があったら)。
	//if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	//{
	//	//キャラクターの方向を変える。
	//	rotation.SetRotationYFromDirectionXZ(moveSpeed);
	//	//絵描きさんに回転を教える。
	//	modelRender.SetRotation(rotation);
	//}
}

//ステート管理。
void Player::ManageState()
{
	playerState = 2;
	////地面に付いていなかったら。
	//if (characterController.IsOnGround() == false)
	//{
	//	//ステートを1(ジャンプ中)にする。
	//	playerState = 1;
	//	//ここでManageStateの処理を終わらせる。
	//	return;
	//}

	////地面に付いていたら。
	////xかzの移動速度があったら(スティックの入力があったら)。
	//if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	//{
	//	//ステートを2(歩き)にする。
	//	playerState = 2;
	//}
	////xとzの移動速度が無かったら(スティックの入力が無かったら)。
	//else
	//{
	//	//ステートを0(待機)にする。
	//	playerState = 0;
	//}
}

//アニメーションの再生。
void Player::PlayAnimation()
{
	//switch文。
	switch (playerState) {
		//プレイヤーステートが0(待機)だったら。
	case 0:
		//待機アニメーションを再生する。
		modelRender.PlayAnimation(enAnimationClip_Idle);
		break;
		//プレイヤーステートが1(ジャンプ中)だったら。
	case 1:
		//ジャンプアニメーションを再生する。
		modelRender.PlayAnimation(enAnimationClip_Jump);
		break;
		//プレイヤーステートが2(歩き)だったら。
	case 2:
		//歩きアニメーションを再生する。
		modelRender.PlayAnimation(enAnimationClip_Walk);
		break;
	}
}

//描画処理。
void Player::Render(RenderContext& rc)
{
	//ユニティちゃんを描画する。
	modelRender.Draw(rc);
}