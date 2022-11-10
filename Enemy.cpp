#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"),
    hModel_(-1)
{
}

//�f�X�g���N�^
Enemy::~Enemy()
{
}

//������
void Enemy::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Enemy.fbx");
    assert(hModel_ >= 0);

    transform_.position_.x = (float)(rand() % 401 - 200) / 10;
    transform_.position_.z = 20.0f;
}

//�X�V
void Enemy::Update()
{

}

//�`��
void Enemy::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Enemy::Release()
{
}