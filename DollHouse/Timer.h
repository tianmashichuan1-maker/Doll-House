#pragma once
#include "Time.h"

class Timer
{
public:
	Timer();
	~Timer();
	void Update();
	void Draw();
	void Start();
	void Stop();
	
	float GetRemainingTime() const;
	float GetRemainingSeconds() const;
	bool IsTimeUp() const;

private:
	float limitTime = 0.0f;
	float remainingTime = 0.0f;
	bool isOperation = false;

};

