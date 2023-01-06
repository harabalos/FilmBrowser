#include "SearchBar.h"
#include "graphics.h"
#include "config.h"

void SearchBar::draw()
{

	graphics::Brush br;
    br.outline_opacity = m_active;
    if (m_highlighted)
    {
        br.fill_color[0] = r_color + 0.2f;
        br.fill_color[1] = g_color + 0.2f;
        br.fill_color[2] = b_color + 0.2f;
    }
    else
    {
        br.fill_color[0] = r_color;
        br.fill_color[1] = g_color;
        br.fill_color[2] = b_color;
    }


    br.fill_opacity = 0.7f;

    graphics::drawRect(x_pos, y_pos, size_x, size_y, br);
}

void SearchBar::update()
{
    graphics::Brush br;
    br.fill_color[0] = 0.0f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 0.0f;
    
    if (m_active)
    {
        for (int i = graphics::SCANCODE_A; i < graphics::SCANCODE_Z; i++)
        {
            graphics::scancode_t sct = static_cast<graphics::scancode_t>(i);
            if (graphics::getKeyState(sct))
            {
                str += static_cast<char>(i+93);
            }
        }
    }
    if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE))
    {
        str = str.substr(0, str.size() - 1);
    }
    if (graphics::getKeyState(graphics::SCANCODE_SPACE))
    {
        str += static_cast<char>(32);
    }

    graphics::setFont(ASSET_PATH"OpenSans-Regular.ttf");
    if (str.length() < 28)
    {
        graphics::drawText(x_pos - 90, y_pos + 4, 12, str, br);
    }
    else
    {
        str.erase(str.begin());
        graphics::drawText(x_pos - 90, y_pos + 4, 12, str, br);
    }
}

SearchBar::SearchBar(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color)
	:Button{ x_pos = x_pos, y_pos = y_pos, size_x = size_x, size_y = size_y, r_color = r_color, g_color = g_color, b_color = b_color } {}

