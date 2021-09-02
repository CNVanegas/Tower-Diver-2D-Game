#include "_texture.h"

_texture::_texture()
{
    //ctor
    playAnim = false;
    loopAnim = false;
    curAnim = "";
    curFrame = 0;

}

_texture::~_texture()
{
    //dtor
}

void _texture::loadTexture(char* fileName, int cX, int cY, float pX, float pY)
{
    glGenTextures(1,&tex);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

    glBindTexture(GL_TEXTURE_2D, tex);
    image = SOIL_load_image(fileName,&width,&height, 0,SOIL_LOAD_RGBA);

    if(!image)
       std::cout<<"fail to find image"<< std::endl;


    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width, height,0,GL_RGBA,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);

    cellsX = cX;

    offsetX = 1.0/cX;
    offsetY = 1.0/cY;

    widthP = width/cX/(float)defaultScreenSizeX;
    heightP = height/cY/(float)defaultScreenSizeY;

    pivX = pX;
    pivY = pY;
}

void _texture::texBind()
{
    glBindTexture(GL_TEXTURE_2D,tex);
}

void _texture::makeAnimation(std::string name, int start , int frames)
{
    animations[name] = std::make_pair(start,frames);
}

void _texture::setAnimation(std::string name, bool isPlaying, bool isLooping, int startFrame)
{
    curAnim = name;
    playAnim = isPlaying;
    loopAnim = isLooping;
    curFrame = startFrame;
}

void _texture::Draw(float xPos, float yPos, float xScale, float yScale, bool flip, bool mirror)
{
    int curFrameX, curFrameY;
    if(curAnim == "")
    {
        curFrameX = curFrame % cellsX;
        curFrameY = curFrame / cellsX;
    }
    else
    {
        int start = animations[curAnim].first;
        int frames = animations[curAnim].second;

        curFrameX = (start + curFrame) % cellsX;
        curFrameY = (start + curFrame) / cellsX;

        if(playAnim)
        {
            curFrame++;
            if(curFrame >= frames)
            {
                if(loopAnim)
                    curFrame = 0;
                else
                    curFrame = frames;
            }

        }
    }

    float xMin, xMax, yMin, yMax;

    xMin = offsetX * curFrameX;
    xMax = offsetX * curFrameX + offsetX;
    yMin = offsetY * curFrameY;
    yMax = offsetY * curFrameY + offsetY;

    if(flip)
    {
        float tempX = xMin;
        xMin = xMax;
        xMax = tempX;
    }

    if(mirror)
    {
        float tempY = yMin;
        yMin = yMax;
        yMax = tempY;
    }

    glBegin(GL_QUADS);
     glTexCoord2f(xMin,yMin); glVertex3f(xPos-(pivX*widthP*xScale),yPos-(pivY*heightP*yScale),0.0);

     glTexCoord2f(xMin,yMax); glVertex3f(xPos-(pivX*widthP*xScale),yPos-(pivY*heightP*yScale)+(heightP*yScale),0.0);

     glTexCoord2f(xMax,yMax); glVertex3f(xPos-(pivX*widthP*xScale)+(widthP*xScale),yPos-(pivY*heightP*yScale)+(heightP*yScale),0.0);

     glTexCoord2f(xMax,yMin); glVertex3f(xPos-(pivX*widthP*xScale)+(widthP*xScale),yPos-(pivY*heightP*yScale),0.0);
    glEnd();
}
