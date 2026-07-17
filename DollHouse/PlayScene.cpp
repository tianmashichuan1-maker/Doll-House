#include "PlayScene.h"
#include "Player.h"
#include "Box.h"

PlayScene::PlayScene()
{
	//生成したインスタンスをメンバー変数に代入する
	player = new Player();
	box = new Box();

	player->SetBox(box);
}

PlayScene::~PlayScene()
{
	delete player;
	delete box;
}

void PlayScene::Update()
{
	//プレイヤーの更新処理を毎フレーム呼び出す
	if (player != nullptr) {
		player->Update();
	}

	//キーが押されたら位置をリセットする
	if (CheckHitKey(KEY_INPUT_R)) {
		if (player != nullptr) {
			player->Reset();
		}
		if (box != nullptr) {
			box->Reset();
		}
	}

	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	// 4. 背景やオブジェクトの描画処理を呼び出す
	if (box != nullptr)    box->Draw();
	if (player != nullptr) player->Draw();

	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
	DrawString(100, 420, "Push [R]Key To Reset", GetColor(255, 255, 255));
}
