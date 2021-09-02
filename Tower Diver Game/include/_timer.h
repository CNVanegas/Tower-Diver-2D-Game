#ifndef _TIMER_H
#define _TIMER_H
#include <time.h>
#include <iostream>

class _timer
{
    public:
        _timer();
        virtual ~_timer();

        bool isStarted();
        bool isStopped();
        bool isPaused();
        void Pause();
        void Resume();
        void Start();
        void Stop();
        void Reset();
        clock_t getTicks();

        clock_t startTime;
        clock_t pauseTime;

        bool started;
        bool paused;

        float FPS;
        clock_t baseTime;

    protected:

    private:
};

#endif // _TIMER_H
