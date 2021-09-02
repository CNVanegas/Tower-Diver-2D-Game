#include "_sound.h"

_sound::_sound()
{
    //ctor
    curSound = 0;
    vol = 2;
    pos = 0;
    eng->setSoundVolume(0.25);

}

_sound::~_sound()
{
    //dtor
    eng->drop();
}

void _sound::playMusic(char* File)
{
    curSound = eng->play2D(File,true);
    file = File;
}

void _sound::pauseMusic()
{
    eng->setAllSoundsPaused();
}

void _sound::resumeMusic()
{
    eng->setAllSoundsPaused(false);
}

void _sound::playSound(char* File)
{
    if(!eng->isCurrentlyPlaying(File))
        eng->play2D(File,false,false);
}

void _sound::pauseSound(char* File)
{
    eng->play2D(File,true,false);
}

int _sound::initSounds()
{
    if(!eng)
    {
        cout << "Sound Engine Initialization Failed" << endl;
        return 0;
    }
    return 1;
}
