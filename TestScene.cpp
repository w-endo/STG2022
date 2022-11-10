#include "TestScene.h"
#include "Player.h"
#include "Enemy.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{
	Instantiate<Player>(this);

	for (int i = 0; i < 3; i++)
	{
		Instantiate<Enemy>(this);
	}
}

//更新
void TestScene::Update()
{
}

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}
