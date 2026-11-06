#pragma once
#include "SceneBase.h"

class StageSelectScene : public SceneBase
{
public:
	StageSelectScene();
	~StageSelectScene();
	void Update() override;
	void Draw() override;
private:
	int hImage;
};
