#pragma once

class Timer {
private:
	bool isComplete = false;

public:
	Timer(float time = 0, float reset = 0, float speed = 1);

	float TimeReset = 0;
	float Time = 0;
	float speed = 1;

	bool Count(float deltaTime);
	bool Complete() const;
	void Reset();
};