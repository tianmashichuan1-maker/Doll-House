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

	isPause = false;
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	static int oldEsc = 0;

	int esc = CheckHitKey(KEY_INPUT_ESCAPE);

	// ESC押下瞬間
	if (esc && !oldEsc)
	{
		isPause = !isPause;
	}

	oldEsc = esc;

	if (isPause)
	{
		if (CheckHitKey(KEY_INPUT_P))
		{
			isPause = false;
		}

		if (CheckHitKey(KEY_INPUT_T))
		{
			SceneManager::ChangeScene("TITLE");
		}

		return;
	}

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
	}
}


void PlayScene::Draw()
{
	player->Draw();
	box->Draw();
	timer.Draw();

	DrawString(100, 420, "Push [R]Key To Reset", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [ESC] Key To Pause", GetColor(255, 255, 255));

	if (isPause)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawString(850, 400, "PAUSE", GetColor(255, 255, 255));
		DrawString(760, 500, "P : Resume", GetColor(255, 255, 255));
		DrawString(760, 550, "T : Title", GetColor(255, 255, 255));
	}
}
