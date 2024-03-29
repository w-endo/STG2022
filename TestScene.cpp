#include "TestScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
#include "Engine/Camera.h"

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
	Camera::SetPosition(XMFLOAT3(0, 5, -8));
	Camera::SetTarget(XMFLOAT3(0, 3, 0));

}

//更新
void TestScene::Update()
{
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}
