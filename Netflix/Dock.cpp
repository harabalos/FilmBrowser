#include "Dock.h"
#include "graphics.h"
#include "config.h"

Dock::Dock()
    :Button{ x_pos = 500 , y_pos = -110,size_x = CANVAS_WIDTH / 2, size_y = CANVAS_WIDTH / 4, r_color = 1.0f, g_color = 1.0f, b_color = 1.0f } {}

Dock::~Dock()
{
}

void Dock::update()
{
    if (m_active)
    {
        setY(130);
        clearbutton->setY(110);
    }
    else
    {
        setY(-110);
        clearbutton->setY(-90);
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

    clearbutton->draw();



}
