#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"


//コンストラクタ
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"),
    hModel_(-1)
{
}

//デストラクタ
Enemy::~Enemy()
{
}

//初期化
void Enemy::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Enemy.fbx");
    assert(hModel_ >= 0);

    transform_.position_.x = (float)(rand() % 401 - 200) / 10;
    transform_.position_.z = 20.0f;

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.2f);
    AddCollider(collision);
}

//更新
void Enemy::Update()
{

}

//描画
void Enemy::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Enemy::Release()
{
}

//何かに当たった
void Enemy::OnCollision(GameObject* pTarget)
{
    //当たったときの処理
    //弾に当たったとき
    if (pTarget->GetObjectName() == "Bullet")
    {
        KillMe();
        pTarget->KillMe();
    }
}