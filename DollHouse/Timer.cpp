#include "Timer.h"

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
}

void Timer::Start()
{
}

void Timer::Stop()
{
}

float Timer::GetRemainingTime() const
{
    return 0.0f;
}

float Timer::GetRemainingSeconds() const
{
    return 0;
}

bool Timer::IsTimeUp() const
{
    return false;
}
