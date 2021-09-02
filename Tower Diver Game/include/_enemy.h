#ifndef _ENEMY_H
#define _ENEMY_H
#include <_object.h>
#include <_player.h>

class _enemy : public _object
{
    public:
        _enemy();
        virtual ~_enemy();

        void Init(char *,int,int);
        void Actions(int);
        void tP(std::string);
        std::string collision(floatPair, floatPair);

        bool alive;
        bool deathDone;
        int hp;
        int enemyType;
        bool enemyCollision;

    protected:

    private:
};

#endif // _ENEMY_H
