#pragma once

//プレイヤークラス。
class TubeManager;
class Player : public IGameObject
{
public:
	Player();
	~Player();
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& rc);
	//移動処理。
	void Move();
	//回転処理。
	void Rotation();
	//ステート管理。
	void ManageState();
	//アニメーションの再生。
	void PlayAnimation();

	//メンバ変数。
	ModelRender modelRender;	//モデルレンダ―。
	float r=-2000;
	Vector3 position{0.0f,0.0f,r};			//座標。
	enum EnAnimationClip {		//アニメーション。
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Num,
	};
	Vector3 characterController_Initpos= {0.0f * (r + 1000) ,0.0,1.0f * (r + 1000) };;
	AnimationClip animationClips[enAnimationClip_Num];		//アニメーションクリップ。
	CharacterController characterController;  //キャラクターコントローラー。
	Vector3 moveSpeed{0.0f,0.0f,0.0f};		//移動速度。
	Quaternion rotation;  //クォータニオン。
	int playerState = 0;	//プレイヤーのステート(状態)を表す変数。
	int starCount = 0;	//集めた☆の数をカウントする。
	bool goingLeft=false;
	float theta=0;//角度θ
	float xround = 0;
	float yround = 0;
	float speadUP = 0;
	float damage = 0;
	const float maxHP = 100;
	float nowHP = maxHP;
	Vector3 previouspos= { sin(theta) * (r + 1000) ,0.0, cos(theta) * (r + 1000) };
	Quaternion playerRot{ 0.0f,0.0f,0.0f,0.0f };
	Vector3 renderpos;//キャラクターを映す場所
	TubeManager* tubeManager;
	
};