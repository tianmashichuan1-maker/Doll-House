#pragma once
#include "GameObject.h"

class Box;

class Player :public GameObject
{
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;

	void SetBox(Box* box);

	//“–‚½‚è”»’è
	RECT GetAABB() const;

private:
	int hImage;
	float x, y;

	bool IsHit(const RECT& a, const RECT& b)
	{
		return (a.left   < b.right &&
			a.right  > b.left &&
			a.top    < b.bottom &&
			a.bottom > b.top);
	}

	Box* box;
};

