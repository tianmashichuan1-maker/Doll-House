#include "Box.h"

Box::Box()
{
	hImage = LoadGraph("image/bird.png");
	x = 500;
	y = 250;
}

Box::~Box()
{
}

void Box::Update()
{
}

RECT Box::GetAABB() const
{
    RECT rc;
    rc.left = (int)x;
    rc.top = (int)y;
    rc.right = (int)x + 64;
    rc.bottom = (int)y + 64;
    return rc;
}

void Box::Draw()
{
	DrawRectGraph(x, y, 0, 0, 64, 64, hImage,1);
}
