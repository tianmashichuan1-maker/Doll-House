#include "Player.h"
#include "Screen.h"
#include "Box.h"

Player::Player()
{
	hImage = LoadGraph("image/aoi.png");
	x = Screen::WIDTH / 2;
	y = Screen::HEIGHT / 2;
}

Player::~Player()
{
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

void Player::SetBox(Box* box)
{
	
}

void Player::Update()
{
	float nextX = x;
	float nextY = y;

	if (CheckHitKey(KEY_INPUT_D))
	{
		x += 2.0f;  //右に進む
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

	// 次の位置の当たり判定用の矩形
	RECT nextPlayerAABB = {
		(int)nextX,
		(int)nextY,
		(int)nextX + 64,
		(int)nextY + 64
	};

	// Box の AABB を取得
	RECT boxAABB = box->GetAABB();

	// 当たり判定
	if (IsHit(nextPlayerAABB, boxAABB))
	{
		// 衝突している場合：箱を押す方向を判定
		float pushX = 0.0f;
		float pushY = 0.0f;

		if (nextX > x) pushX = 2.0f;   // 右へ押す
		if (nextX < x) pushX = -2.0f;  // 左へ押す
		if (nextY > y) pushY = 2.0f;   // 下へ押す
		if (nextY < y) pushY = -2.0f;  // 上へ押す

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
		x = nextX;
		y = nextY;
	}
	else
	{
		// 当たっていないなら普通に移動
		x = nextX;
		y = nextY;
	}
	
}

void Player::Draw()
{
	DrawRectGraph(x, y, 0, 0, 64, 64, hImage, 1);
}
