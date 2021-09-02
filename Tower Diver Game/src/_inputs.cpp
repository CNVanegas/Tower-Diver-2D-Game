#include "_inputs.h"

_inputs::_inputs(_timer* t)
{
    //ctor
    timer = t;
    animTime = 0;
}

_inputs::~_inputs()
{
    //dtor
}

void _inputs::initPly(_object* o)
{
    ply = o;
}
void _inputs::initEnmy(_object * e)
{
    enmy = e;
}


void _inputs::initBtns(_buttons* b)
{
    btns = b;
}

void _inputs::initSnd(_sound* s)
{
    snd = s;
}

void _inputs::keyPress()
{
    if(!timer->isPaused())
    {

        switch(wParam)
        {
            case VK_LEFT:
                if(ply)
                {
                    ply->Actions(1);
                    if(ply->xPos > enmy->xPos)
                        enmy->Actions(4);
                    else
                        enmy->Actions(1);
                }
                break;
            case VK_RIGHT:
                if(ply)
                {
                    ply->Actions(4);
                    if(ply->xPos < enmy->xPos)
                        enmy->Actions(1);
                    else
                        enmy->Actions(4);
                }
                break;
            case VK_UP:
                if(ply)
                {
                    ply->Actions(8);
                }
                break;
            case VK_DOWN:
                if(ply)
                {
                    ply->Actions(2);
                }
                break;

            case VK_SPACE:
                if(ply)
                {
                    animTime = 9;
                    attacking = true;
                    ply->Actions(7);
                    ply->isAttacking = true;
                }

                break;

            case VK_RETURN:
                break;
        }
    }
}

void _inputs::keyRelease()
{
    if(!timer->isPaused())
    {
        switch(wParam)
        {
            case VK_LEFT:
                if(ply)
                {
                   ply->Actions(-1);
                   if(enmy->dirFlag == 4)
                       enmy->Actions(-4);
                   else
                    enmy->Actions(-1);
                }


                break;
            case VK_RIGHT:
                if(ply)
                {
                    ply->Actions(-4);
                    if(enmy->dirFlag ==1)
                        enmy->Actions(-1);
                    else
                        enmy->Actions(-4);
                }


                break;
            case VK_UP:
                if(ply)
                    ply->Actions(-8);
                break;
            case VK_DOWN:
                if(ply)
                    ply->Actions(-2);
                break;

            case VK_SPACE:
                if(ply)
                {
                    ply->Actions(-7);
                    ply->isAttacking = false;
                    /*
                    if (animTime > 0)
                    {

                        //ply->Actions(-7);
                        ply->dirFlag = 0;
                        //ply->Actions(0);
                    }
                    else
                        ply->Actions(-7);*/

                        //ply->Actions(-7);
                    cout << "Anim time= " << animTime << endl;

                }

                break;
        }
    }


}

void _inputs::mouseDown(double x, double y)
{
    prevMouseX = x;
    prevMouseY = y;

    switch(wParam)
    {
        case MK_LBUTTON:
            break;

        case MK_RBUTTON:
            break;

        default:
            break;
    }
}

std::string _inputs::mouseUp()
{
    if(btns)
        return btns->chkclick();
    return "";
}


void _inputs::mouseMove(double x, double y)
{
    prevMouseX = x;
    prevMouseY = y;
}
