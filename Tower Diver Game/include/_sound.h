#ifndef _SOUND_H
#define _SOUND_H
#include <stdlib.h>
#include <SOUNDS/irrKlang.h>
#include <iostream>
#include <_timer.h>

using namespace std;
using namespace irrklang;

class _sound
{
    public:
        _sound();
        virtual ~_sound();
        ISoundEngine *eng = createIrrKlangDevice();
        ISound *curSound;

        int vol;
        int pos;
        char *file;

        void playMusic(char*);
        void pauseMusic();
        void resumeMusic();
        void playSound(char*);
        void pauseSound(char*);
        int initSounds();

        _timer *timer = new _timer();

    protected:

    private:
};

#endif // _SOUND_H
