#include "graphics.h"
#include "FilmBrowser.h"
#include "config.h"


void update(float ms)
{
    FilmBrowser* fb = FilmBrowser::getInstance();
    fb->update();
}

void draw()
{
    FilmBrowser* fb = FilmBrowser::getInstance();
    fb->draw();
}

int main(int argc,char ** argv)
{
    FilmBrowser* fb = FilmBrowser::getInstance();
    //initialization
    fb->init();

    //creates window
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "FilmBrowser");

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
    
    graphics::startMessageLoop();
    FilmBrowser::releaseInstance();
    return 0;
}