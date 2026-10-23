#include "Player.h"
#include "Screen.h"
#include "Box.h"

Player::Player()
{
	hImage = LoadGraph("image/aoi.png");
	x = Screen::WIDTH / 2.0f;
	y = Screen::HEIGHT / 2.0f;
	box = nullptr;

}

Player::~Player()
{
	if (hImage != -1)
	{
		DeleteGraph(hImage);
	}
}

// プレイヤーの位置を初期位置に戻す
void Player::Reset()
{
	x = Screen::WIDTH / 2.0f;
	y = Screen::HEIGHT / 2.0f;
}

RECT Player::GetAABB() const
{
	RECT rc;
	rc.left = (int)x;
	rc.top = (int)y;
	rc.right = (int)x + 64;
	rc.bottom = (int)y + 64;
	return rc;
}

void Player::SetBox(Box* b)
{
	box = b;
}

void Player::Update()
{
	if (box == nullptr) return;

	float moveX = 0.0f;
	float moveY = 0.0f;

	const float SPEED = 6.0f;

	if (CheckHitKey(KEY_INPUT_D))
	{
		moveX = SPEED;
	}

	if (CheckHitKey(KEY_INPUT_A))
	{
		moveX = -SPEED;
	}
	
	if (CheckHitKey(KEY_INPUT_W))
	{
		moveY = -SPEED;
	}
	
	if (CheckHitKey(KEY_INPUT_S))
	{
		moveY = SPEED;
	}

	float walkX = x + moveX;
	float walkY = y + moveY;

	// 次の位置の当たり判定用の矩形
	RECT nextPlayerAABB = {
		(LONG)walkX,
		(LONG)walkY,
		(LONG)(walkX + 64),
		(LONG)(walkY + 64)
	};

	// Box の AABB を取得
	RECT boxAABB = box->GetAABB();

	// 当たり判定
	if (IsHit(nextPlayerAABB, boxAABB))
	{
		// 箱を押す
		box->Move(moveX, moveY);

		// 箱の移動後の位置を取得
		boxAABB = box->GetAABB();

		//プレイヤーを箱の端へ補正
		// 右へ移動
		if (moveX > 0)
		{
			x = (float)boxAABB.left - 64.0f;
		}
		// 左へ移動
		else if (moveX < 0)
		{
			x = (float)boxAABB.right;
		}

		// 下へ移動
		if (moveY > 0)
		{
			y = (float)boxAABB.top - 64.0f;
		}
		// 上へ移動
		else if (moveY < 0)
		{
			y = (float)boxAABB.bottom;
		}
	}
	else
	{
		// 当たっていないなら普通に移動
		x = walkX;
		y = walkY;
	}
	
}

void Player::Draw()
{
	DrawRectGraph(x, y, 0, 0, 64, 64, hImage, 1);
}
