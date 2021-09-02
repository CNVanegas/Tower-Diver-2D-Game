#include "_object.h"

_object::_object()
{
    //ctor
    tex = new _texture();
    isAttacking = false;
}

_object::~_object()
{
    //dtor
}

void _object::DrawObject()
{
    tex->texBind();
    if(tex->flip)
        tex->Draw(xPos,yPos,2.0,2.0, true);   //influence object scale
    else
        tex->Draw(xPos,yPos,2.0,2.0, false);
}

floatPair _object::GetNextXY()
{
    float tempX = xPos;
    float tempY = yPos;

    if(dirFlag == 1)
        tempX -= walkSpeed;
    //if(dirFlag & 2)
     //   tempY += walkSpeed;
    else if(dirFlag == 4)
        tempX += walkSpeed;
    else if (dirFlag == 7)
        tempX -= 0;
    //if(dirFlag & 8)
    //    tempY -= walkSpeed;
    //std::cout << "temp X" << tempX << std::endl;
   // std::cout << "temp Y" << tempY << std::endl;
   //if(dirFlag == 7)
    //return std::make_pair(xPos,yPos);
   return std::make_pair(tempX,tempY);
}

floatPair _object::EnemGetNextXY(floatPair PlyCoords)
{
    float enmyX = xPos;
    float enmyY = yPos;

    float tempPlyX = PlyCoords.first;
    //float tempPlyY = PlyCoords.second;

    float distX = enmyX - tempPlyX;

    if(abs(distX) < 0.35)
    {
        if (distX > 0)
        {

            enmyX -= walkSpeed;
        }

        else if (distX < 0)
        {

            enmyX += walkSpeed;
        }

    }

    return std::make_pair(enmyX,enmyY);
}

void _object::PositionObject(floatPair location)
{
    xPos = location.first;
    yPos = location.second;
}
