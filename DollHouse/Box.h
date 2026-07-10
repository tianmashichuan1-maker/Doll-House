#pragma once
#include "GameObject.h"

class Box : public GameObject
{
public:
	Box();
	~Box();
	void Update() override;
	void Draw() override;

	//“–‚½‚è”»’è
	RECT GetAABB() const;

	float x, y;

private:
	int hImage;
};

