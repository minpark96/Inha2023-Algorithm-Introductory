#pragma once
#include <ctime>

class StopWatch
{
private:
	clock_t startTime;
	clock_t endTime;
public:
	StopWatch();
	clock_t getStartTime();
	clock_t getEndTime();
	void start();
	void stop();
	clock_t getElapsedTime();
};
