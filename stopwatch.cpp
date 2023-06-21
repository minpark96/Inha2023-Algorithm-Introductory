#include "stopwatch.h"

StopWatch::StopWatch()
{
    startTime = clock();
    endTime = 0;
}

clock_t StopWatch::getStartTime()
{
    return startTime;
}

clock_t StopWatch::getEndTime()
{
    return endTime;
}

void StopWatch::start()
{
    startTime = clock();
}

void StopWatch::stop()
{
    endTime = clock();
}

clock_t StopWatch::getElapsedTime()
{
    return endTime - startTime;
}
