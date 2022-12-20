#include "graphics.h"
#include "FilmBrowser.h"
#include "config.h"


void update(float ms)
{
    FilmBrowser* fb = reinterpret_cast<FilmBrowser*> (graphics::getUserData());
    fb->update();
}


void draw()
{
    FilmBrowser* fb = reinterpret_cast<FilmBrowser*> (graphics::getUserData());
    fb->draw();
}

int main()
{
    FilmBrowser fb;

    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Netflix");

    graphics::setUserData(&fb);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);




    fb.init();
    graphics::startMessageLoop();

    return 0;
}