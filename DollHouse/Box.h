#pragma once
#include "GameObject.h"

class Box : public GameObject
{
public:
	Box();
	~Box();
	void Update() override;
	void Draw() override;
	void Reset();

	//“–‚½‚è”»’è
	RECT GetAABB() const;

	void Move(float dx, float dy);

private:
	int hImage;
	float x;
	float y;
};

