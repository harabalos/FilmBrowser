#include "FilmBrowser.h"
#include "graphics.h"
#include "config.h"

void FilmBrowser::update()
{
	
}

void FilmBrowser::draw()
{
    graphics::Brush br;
    br.fill_color[0] = 0.0f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 0.0f;
    br.fill_opacity = 0.2f;
    br.fill_secondary_color[0] = 0.8f;
    br.fill_secondary_color[1] = 0.8f;
    br.fill_secondary_color[2] = 0.8f;
    br.fill_secondary_opacity = 0.9f;
    br.gradient_dir_u = 0.0f;
    br.gradient_dir_v = 0.6f;
    br.outline_opacity = 0.0f;
    br.gradient = true;

    graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
}

void FilmBrowser::init()
{
}

FilmBrowser::FilmBrowser()
{
}

FilmBrowser::~FilmBrowser()
{

}
