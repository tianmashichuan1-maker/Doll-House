#pragma once
#include "SceneBase.h"

class GameOverScene : public SceneBase
{
public:
	GameOverScene();
	~GameOverScene();
	void Update() override;
	void Draw() override;
private:
	int hImage;
};
