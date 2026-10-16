#pragma once
#include "SceneBase.h"
#include "Timer.h"

class Player;
class Box;

/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>
class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;

private:
	Player* player;
	Box* box;

	Timer timer;
};
