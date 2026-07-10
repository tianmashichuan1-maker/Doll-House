#pragma once
#include "GameObject.h"

class Player :public GameObject
{
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	float x, y;

};

