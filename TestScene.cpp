#include "TestScene.h"
#include "Player.h"
#include "Enemy.h"

//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//������
void TestScene::Initialize()
{
	Instantiate<Player>(this);

	for (int i = 0; i < 3; i++)
	{
		Instantiate<Enemy>(this);
	}
}

//�X�V
void TestScene::Update()
{




}

//�`��
void TestScene::Draw()
{
}

//�J��
void TestScene::Release()
{
}
