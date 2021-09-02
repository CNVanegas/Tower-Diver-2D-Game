#ifndef _COMMON_H
#define _COMMON_H
#include <utility>

struct vec3
{
    float x;
    float y;
    float z;

};

struct vec2
{
    float x;
    float y;
};

typedef std::pair<int,int> intPair;
typedef std::pair<float,float> floatPair;

extern int defaultScreenSizeX;
extern int defaultScreenSizeY;

#endif // _COMMON_H
