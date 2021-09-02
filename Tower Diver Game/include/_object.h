#ifndef _OBJECT_H
#define _OBJECT_H
#include <cstdlib>
#include <GL/gl.h>
#include <_texture.h>
#include <_common.h>
#include <math.h>

class _object
{
    public:
        _object();
        virtual ~_object();

        void DrawObject();
        floatPair GetNextXY();
        floatPair EnemGetNextXY(floatPair);
        void PositionObject(floatPair);

        virtual void Init(char*,int,int) = 0;
        virtual void Actions(int) = 0;

        float xPos, yPos;
        //bool mirror;

        int dirFlag;
        std::string idleAnim;

        float walkSpeed, runSpeed;
        bool isSolid;
        bool isAttacking;

        _texture *tex;

    protected:

    private:
};

#endif // _OBJECT_H
