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

	float walkX = x;
	float walkY = y;

	if (CheckHitKey(KEY_INPUT_D))
	{
		walkX += 1.0f;  //右に進む
	}
	else if (CheckHitKey(KEY_INPUT_A))
	{
		walkX -= 1.0f;
	}
	else if (CheckHitKey(KEY_INPUT_W))
	{
		walkY -= 1.0f;
	}
	else if (CheckHitKey(KEY_INPUT_S))
	{
		walkY += 1.0f;
	}

	// 次の位置の当たり判定用の矩形
	RECT nextPlayerAABB = {
		(int)walkX,
		(int)walkY,
		(int)walkX + 64,
		(int)walkY + 64
	};

	// Box の AABB を取得
	RECT boxAABB = box->GetAABB();

	// 当たり判定
	if (IsHit(nextPlayerAABB, boxAABB))
	{
		// 衝突している場合：箱を押す方向を判定
		float pushX = 0.0f;
		float pushY = 0.0f;

		if (walkX > x) pushX = 2.0f;   // 右へ押す
		if (walkX < x) pushX = -2.0f;  // 左へ押す
		if (walkY > y) pushY = 2.0f;   // 下へ押す
		if (walkY < y) pushY = -2.0f;  // 上へ押す

		// 箱の次の位置を計算
		float nextBoxX = box->x + pushX;
		float nextBoxY = box->y + pushY;

		RECT nextBoxAABB = {
			(int)nextBoxX,
			(int)nextBoxY,
			(int)nextBoxX + 64,
			(int)nextBoxY + 64
		};

		// 箱が壁などにぶつからない場合のみ押す（壁判定は後で追加）
		box->x = nextBoxX;
		box->y = nextBoxY;

		// プレイヤーも箱に合わせて移動
		x = walkX;
		y = walkY;
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
