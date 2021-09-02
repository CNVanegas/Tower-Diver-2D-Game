#include "_timer.h"

_timer::_timer()
{
    //ctor
    startTime = 0;
    pauseTime = 0;
    paused = false;
    started = false;
}

_timer::~_timer()
{
    //dtor
}

bool _timer::isStarted()
{
    return started;
}

bool _timer::isStopped()
{
    return !started;
}

bool _timer::isPaused()
{
    return paused;
}

void _timer::Pause()
{
    if(paused || !started)
        return;
    paused = true;
    pauseTime = clock();
}

void _timer::Resume()
{
    if(!paused)
        return;
    paused = false;
    startTime += clock() - pauseTime;
}

void _timer::Start()
{
    if(started)
        return;
    started = true;
    paused = false;
    startTime = clock();
}

void _timer::Stop()
{
    started = false;
}

void _timer::Reset()
{
    paused = false;
    startTime = clock();
}

clock_t _timer::getTicks()
{
    if(!started)
        return 0;
    if(paused)
        return pauseTime - startTime;
    return clock() - startTime;
}
