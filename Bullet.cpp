#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//コンストラクタ
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet"),
    hModel_(-1)
{
}

//デストラクタ
Bullet::~Bullet()
{
}

//初期化
void Bullet::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Bullet.fbx");
    assert(hModel_ >= 0);
}

//更新
void Bullet::Update()
{

}

//描画
void Bullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Bullet::Release()
{
}