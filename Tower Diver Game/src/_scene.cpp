#include "_scene.h"

_scene::_scene()
{
    //ctor
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    timer = new _timer();
    kBMs = new _inputs(timer);
}

_scene::~_scene()
{
    //dtor
}

GLint _scene::InitGL()
{
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    Init(screenWidth,screenHeight);
    timer->Start();
    return true;
}

GLint _scene::DrawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    Draw();


}

GLvoid _scene::ResizeScene(GLsizei width, GLsizei height)
{
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1,1,0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    aspectRatio = 1.0 * height/width;
    ScreenResized(width, height);
}

int _scene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if(kBMs)
        kBMs->wParam = wParam;
    std::string act;

    switch(uMsg)
    {
        case WM_KEYDOWN:
            if(!timer->isPaused() && !(lParam & 0x40000000))
                kBMs->keyPress();
            break;
        case WM_KEYUP:
            if(wParam == VK_ESCAPE)
                Action("KB_Esc");
            if(wParam == VK_RETURN)
                Action("KB_Enter");
            if(!timer->isPaused())
            {
                if(kBMs)
                    kBMs->keyRelease();
                if(wParam >= 'A' && wParam <= 'Z')
                {
                    char c = (char)(int)wParam;
                    std::string s = "KB_";
                    s+=c;
                    Action(s);
                }
            }

            break;

        case WM_LBUTTONDOWN:
            break;
        case WM_RBUTTONDOWN:
            break;
        case WM_MBUTTONDOWN:
            break;

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
            kBMs->wParam = wParam;
            if(kBMs)
                act = kBMs->mouseUp();
            if(act != "")
                Action(act);
            break;

        case WM_MOUSEMOVE:
            mouseX = LOWORD(lParam);
            mouseY = HIWORD(lParam);
            break;
    }
}
