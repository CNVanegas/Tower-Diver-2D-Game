#ifndef _TEXTURE_H
#define _TEXTURE_H
#include <SOIL.h>
#include <GL/gl.h>
#include <map>
#include <iostream>
#include <utility>
#include <_common.h>

typedef std::pair<int,int> intPair;

class _texture
{
    public:
        _texture();
        virtual ~_texture();

        void loadTexture(char*,int,int,float pX = 0.0, float pY = 0.0);
        void texBind();
        bool flip = false;
        bool mirror = false;
        void makeAnimation(std::string,int,int);
        void setAnimation(std::string,bool,bool,int);
        void Draw(float xPos, float yPos, float xScale = 1.0, float yScale = 1.0, bool flip = false, bool mirror = false);

        int width, height;
        float widthP, heightP;
        unsigned char* image;
        GLuint tex;
        int cellsX;
        float offsetX, offsetY;
        float pivX, pivY;

        bool playAnim;
        bool loopAnim;
        std::string curAnim;
        std::map<std::string,intPair> animations;
        int curFrame;
        int lifeLeft;


    protected:

    private:
};

#endif // _TEXTURE_H
