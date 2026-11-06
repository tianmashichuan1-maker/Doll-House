#include "GameOverScene.h"

GameOverScene::GameOverScene()
{
	hImage = LoadGraph("Image/GameOver.png");
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T))
	{
		SceneManager::ChangeScene("TITLE");
	}

	if (CheckHitKey(KEY_INPUT_P)) 
	{
		SceneManager::ChangeScene("PLAY");
	}
}

void GameOverScene::Draw()
{
	DrawGraph(20, 30, hImage, TRUE);
	DrawString(100, 300, "Push [T]Key To Title", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [P]Key To Play", GetColor(255, 255, 255));
}
