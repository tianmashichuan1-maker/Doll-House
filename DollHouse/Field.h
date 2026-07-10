#pragma once
#include "GameObject.h"

class Field : public GameObject
{
public:
	Field();
	~Field();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	float x, y;
};

