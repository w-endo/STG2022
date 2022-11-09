#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"

//コンストラクタ
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"),
	hModel_(-1)
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Player.fbx");
    assert(hModel_ >= 0);
}

//更新
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

//描画
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}