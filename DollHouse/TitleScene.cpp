#include "TitleScene.h"

TitleScene::TitleScene()
{
	hImage = LoadGraph("Image/Title.png");
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_P)) 
	{
		SceneManager::ChangeScene("PLAY");
	}

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		SceneManager::ChangeScene("STAGESELECT");
	}

	if (CheckHitKey(KEY_INPUT_C))
	{
		SceneManager::ChangeScene("GAMECLEAR");
	}

	if (CheckHitKey(KEY_INPUT_ESCAPE)) 
	{
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	extern const char* Version();

	DrawGraph(20, 30, hImage, TRUE);
	DrawString(0, 20, Version(), GetColor(255, 255, 255));
	DrawString(100, 300, "Push[ESC]Key To Exit", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [SPACE]Key To StageSelect", GetColor(255, 255, 255));
	DrawString(100, 500, "Push [P]Key To Play", GetColor(255, 255, 255));
	DrawString(100, 600, "Push[C]Key To GameClear", GetColor(255, 255, 255));
}
