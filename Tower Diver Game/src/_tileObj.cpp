#include "_tileObj.h"

_tileObj::_tileObj()
{
    //ctor
    pos.x = 0.0f;
    pos.y = 0.0f;

    Size.x = 1.0f;
    Size.y = 1.0f;
    isSolid = false;
    isDoor = false;

    rotation = 0.0;
}

_tileObj::~_tileObj()
{
    //dtor
}

_tileObj::_tileObj(vec2 position, vec2 Sizev, _texture* Sprite )
{
   pos = position;
   Size = Sizev;
   sprite = Sprite;
}
