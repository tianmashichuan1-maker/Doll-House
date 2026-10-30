#include "PlayScene.h"
#include "Player.h"
#include "Box.h"

PlayScene::PlayScene()
{
	//生成したインスタンスをメンバー変数に代入する
	player = new Player();
	box = new Box();

	player->SetBox(box);

	timer.SetTime(3.0f);
	timer.Start();
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	timer.Update();

	if (timer.IsTimeUp())
	{
		SceneManager::ChangeScene("GAMEOVER");
		return;
	}

	//キーが押されたら位置をリセットする
	if (CheckHitKey(KEY_INPUT_R)) 
	{
		player->Reset();
		box->Reset();

		//timer.Reset();
		//timer.Start();
	}

	if (CheckHitKey(KEY_INPUT_T)) 
	{
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	timer.Draw();

	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
	DrawString(100, 420, "Push [R]Key To Reset", GetColor(255, 255, 255));
}
