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

private:
	Player* player;
	Box* box;
	Timer timer;
};
