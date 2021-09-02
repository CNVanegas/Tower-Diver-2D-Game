#ifndef _SCENE_H
#define _SCENE_H
#include <windows.h>
#include <GL/glut.h>
#include <stack>
#include <iostream>
#include <vector>
//#include <_scene.h>
#include <_texture.h>
#include <_player.h>
#include <_enemy.h>
#include <_inputs.h>
#include <_sound.h>
#include <_timer.h>
#include <_common.h>

class _scene
{
    public:
        _scene();
        virtual ~_scene();
        GLint InitGL();
        GLint DrawScene();
        GLvoid ResizeScene(GLsizei, GLsizei);
        int winMsg(HWND,UINT,WPARAM,LPARAM);

        virtual void Init(int,int)=0;
        virtual void Draw()=0;
        virtual void Action(std::string act) = 0;
        virtual void ScreenResized(int,int) = 0;

        float screenHeight, screenWidth, aspectRatio;
        int mouseX, mouseY;

        std::stack<_scene*>* sceneList;

        _inputs *kBMs;
        _timer *timer;

    protected:

    private:
};

#endif // _SCENE_H
