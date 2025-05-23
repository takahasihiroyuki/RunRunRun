#pragma once

//�v���C���[�N���X�B
class TubeManager;
class Player : public IGameObject
{
public:
	Player();
	~Player();
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);
	//�ړ������B
	void Move();
	//��]�����B
	void Rotation();
	//�X�e�[�g�Ǘ��B
	void ManageState();
	//�A�j���[�V�����̍Đ��B
	void PlayAnimation();

	//�����o�ϐ��B
	ModelRender modelRender;	//���f�������_�\�B
	float r=-2000;
	Vector3 position{0.0f,0.0f,r};			//���W�B
	enum EnAnimationClip {		//�A�j���[�V�����B
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Num,
	};
	Vector3 characterController_Initpos= {0.0f * (r + 1000) ,0.0,1.0f * (r + 1000) };;
	AnimationClip animationClips[enAnimationClip_Num];		//�A�j���[�V�����N���b�v�B
	CharacterController characterController;  //�L�����N�^�[�R���g���[���[�B
	Vector3 moveSpeed{0.0f,0.0f,0.0f};		//�ړ����x�B
	Quaternion rotation;  //�N�H�[�^�j�I���B
	int playerState = 0;	//�v���C���[�̃X�e�[�g(���)��\���ϐ��B
	int starCount = 0;	//�W�߂����̐����J�E���g����B
	bool goingLeft=false;
	float theta=0;//�p�x��
	float xround = 0;
	float yround = 0;
	float speadUP = 0;
	float damage = 0;
	const float maxHP = 100;
	float nowHP = maxHP;
	Vector3 previouspos= { sin(theta) * (r + 1000) ,0.0, cos(theta) * (r + 1000) };
	Quaternion playerRot{ 0.0f,0.0f,0.0f,0.0f };
	Vector3 renderpos;//�L�����N�^�[���f���ꏊ
	TubeManager* tubeManager;
	
};