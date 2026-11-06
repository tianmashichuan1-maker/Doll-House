#include "GameClearScene.h"

GameClearScene::GameClearScene()
{
	hImage = LoadGraph("Image/GameClear.png");
}

GameClearScene::~GameClearScene()
{
}

void GameClearScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T))
	{
		SceneManager::ChangeScene("TITLE");
	}

}

void GameClearScene::Draw()
{
	DrawGraph(20, 30, hImage, TRUE);
	DrawString(100, 300, "Push [T]Key To Title", GetColor(255, 255, 255));
}
