#ifndef _TILEOBJ_H
#define _TILEOBJ_H
#include <_texture.h>
#include <_object.h>
#include <_common.h>

class _tileObj : public _object
{
    public:
        _tileObj();

        virtual ~_tileObj();

        vec2 pos, Size;
        float rotation;
        bool isSolid;
        bool isDoor;

        _texture *sprite;
        _tileObj(vec2,vec2, _texture* sprite);

    protected:

    private:
};

#endif // _TILEOBJ_H
