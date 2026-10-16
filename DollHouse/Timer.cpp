#include "Timer.h"
#include "DxLib.h"
#include <cmath>

Timer::Timer()
{
    limitTime = 0.0f;
    remainingTime = 0.0f;
    isOperation = false;
}

Timer::~Timer()
{
}

void Timer::Update()
{
    // 停止中ならカウントしない
    if (!isOperation)
    {
        return;
    }

    // 残り時間から1フレーム分の時間を引く
    remainingTime -= Time::DeltaTime();

    // 0秒未満にならないようにする
    if (remainingTime <= 0.0f)
    {
        remainingTime = 0.0f;
        isOperation = false;
    }
}

void Timer::Start()
{
    // タイムアップ済みなら開始しない
    if (remainingTime <= 0.0f)
    {
        return;
    }

    isOperation = true;
}

void Timer::Stop()
{
    isOperation = false;
}

void Timer::SetTime(float time)
{
    limitTime = time;
    remainingTime = time;
}

void Timer::Reset()
{
    remainingTime = limitTime;
    isOperation = false;
}

float Timer::GetRemainingTime() const
{
    return remainingTime;
}

int Timer::GetRemainingSeconds() const
{
    return static_cast<int>(ceilf(remainingTime));
}

bool Timer::IsTimeUp() const
{
    return remainingTime <= 0.0f;
}

void Timer::Draw()
{
    DrawFormatString(500,20,GetColor(255, 255, 255),"TIME : %d",GetRemainingSeconds());
}
