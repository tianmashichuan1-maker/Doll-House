#include "TitleScene.h"

TitleScene::TitleScene()
{
	hImage = LoadGraph("Image/DollHouse.png");
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_P)) {
		SceneManager::ChangeScene("PLAY");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	extern const char* Version();

	DrawGraph(200, 100, hImage, TRUE);
	DrawString(0, 20, Version(), GetColor(255, 255, 255));
	DrawString(0, 0, "TITLE SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [P]Key To Play", GetColor(255, 255, 255));
}
