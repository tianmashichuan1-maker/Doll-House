#include "Player.h"
#include "Screen.h"

Player::Player()
{
	hImage = LoadGraph("image/aoi.png");
	x = Screen::WIDTH / 2;
	y = Screen::HEIGHT / 2;
}

Player::~Player()
{
}

void Player::Update()
{
	if (CheckHitKey(KEY_INPUT_D))
	{
		x += 2.0f;  //âEÇ…êiÇﬁ
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		x -= 2.0f;
	}
	if (CheckHitKey(KEY_INPUT_W))
	{
		y -= 2.0f;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		y += 2.0f;
	}
	
}

void Player::Draw()
{
	DrawRectGraph(x, y, 0, 0, 64, 64, hImage, 1);
}
