#include "Dock.h"
#include "graphics.h"
#include "config.h"
#include "FilmBrowser.h"

Dock::Dock()
    :Button{ x_pos = 500 , y_pos = -110,size_x = CANVAS_WIDTH / 2, size_y = CANVAS_WIDTH / 4, r_color = 1.0f, g_color = 1.0f, b_color = 1.0f }{}

Dock::~Dock()
{
}

void Dock::update()
{

    graphics::MouseState ms;
    graphics::getMouseState(ms);

    float mx = graphics::windowToCanvasX(ms.cur_pos_x);
    float my = graphics::windowToCanvasX(ms.cur_pos_y);

    GenreButton* cur_clearButton = nullptr;
    if (m_active)
    {
        setY(95);
        clearbutton->setY(60);
        //for (auto but : filmGenres)
        //{
        //    but->setY(60);
        //}
    }
    else
    {
        setY(-110);
        clearbutton->setY(-90);
        //for (auto but : filmGenres)
        //{
        //    but->setY(-90);
        //}
    }

    if (clearbutton->contains(mx, my))
    {
        clearbutton->setHighlight(true);
        cur_clearButton = clearbutton;
    }
    else
    {
        clearbutton->setHighlight(false);
    }

    if (ms.button_left_pressed && cur_clearButton)
    {
        clearbutton->setActive(true);
    }
    else
    {
        clearbutton->setActive(false);
    }
}

void Dock::draw()
{
    graphics::Brush br;

    br.fill_color[0] = r_color;
    br.fill_color[1] = g_color;
    br.fill_color[2] = b_color;
    br.outline_opacity = 0.0f;
    br.fill_opacity = 1.0f;
    br.texture = ASSET_PATH"dock.png";
    graphics::drawRect(x_pos, y_pos, size_x, size_y, br);

    graphics::Brush br1;

    br1.fill_color[0] = 0.6f;
    br1.fill_color[1] = 0.6f;
    br1.fill_color[2] = 0.6f;
    br1.outline_opacity = 0.0f;
    br1.fill_opacity = 1.0f;
    graphics::drawRect(x_pos, y_pos - 80, size_x - 5, CANVAS_HEIGHT / 16, br1);

    br1.fill_color[0] = 1.0f;
    br1.fill_color[1] = 1.0f;
    br1.fill_color[2] = 1.0f;
    graphics::setFont(ASSET_PATH"OpenSans-Regular.ttf");
    graphics::drawText(x_pos-20, y_pos-70, 20, "Filters", br1);
    graphics::drawText(x_pos - 200, y_pos - 45, 15, "Genres:", br1);

    clearbutton->draw();

    //for (auto but : filmGenres)
    //{
    //    but->draw();
    //}


}
