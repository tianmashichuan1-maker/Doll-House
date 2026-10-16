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
	void Reset();

	void SetBox(Box* b);

	//“–‚½‚è”»’è
	RECT GetAABB() const;

private:
	bool IsHit(const RECT& a, const RECT& b)
	{
		return (a.left   < b.right &&
			a.right  > b.left &&
			a.top    < b.bottom &&
			a.bottom > b.top);
	}

private:
	int hImage;

	float x;
	float y;

	Box* box;

};

