#pragma once
#include "SceneBase.h"
#include "Timer.h"

class Player;
class Box;

class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;

	void UpdatePauseMenu();
	void DrawPauseMenu();

private:
	Player* player;
	Box* box;
	Timer timer;

	// ポーズ管理
	bool isPause = false;

	// メニュー選択
	int pauseSelect = 0;
};
