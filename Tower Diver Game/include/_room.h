#ifndef _ROOM_H
#define _ROOM_H
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <stack>
#include <utility>
#include <_texture.h>
#include <fstream>
#include <istream>
#include <sstream>
#include <_common.h>
#include <_tileObj.h>
#include <vector>

using namespace std;

typedef std::pair<int,int> intPair;

class _room
{
    public:
        _room();
        virtual ~_room();
        vec2 pos, Size;
        void makeRoom(int);
        //void Init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight);
        void drawRoom(int);
        void movePly(std::string);
        //void readLevel(const char*,unsigned int, unsigned int);

        float rotation;
        bool isfloor;
        bool isDoor;

        _texture *stage1;
        _texture *stage2;
        _texture *stage3;
        _texture *bricks;
        _texture *pillar;
        _texture *pillars;
        _texture *bottomwall;
        _texture *carpet;
        _texture *chandalier;
        _texture *fence;
        _texture *platform;
        _texture *platform2;
        _texture *platform3;
        _texture *topwall;
        _texture *walkpaths;
        _texture *wall2;
        _texture *wall3;
        _texture *wallcontinue;
        _texture *woodsupport;
        _texture *window;


        //vector<_tileObj> block;

    protected:

    private:
};

#endif // _ROOM_H
