#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"),
	hModel_(-1)
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Player.fbx");
    assert(hModel_ >= 0);
}

//�X�V
void Player::Update()
{
    if(Input::IsKey(DIK_RIGHT))
    {
        transform_.position_.x += 0.3f;
    }
    if (Input::IsKey(DIK_LEFT))
    {
        transform_.position_.x -= 0.3f;
    }

    if (Input::IsKeyDown(DIK_SPACE))
    {
        Instantiate<Bullet>( GetParent() );
    }
}

//�`��
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}