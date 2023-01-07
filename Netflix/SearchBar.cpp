#include "SearchBar.h"
#include "graphics.h"
#include "config.h"

void SearchBar::draw()
{
    //draw searchbar

	graphics::Brush br;

    //animation to show if the search bar is active
    br.outline_opacity = m_active;

    //animation to show if the search bar is being hovered
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
    
    //if the search bar is active we iterate though every letter in the keyboard and checks if it is pressed
    //+ the backspace and space keywords
    if (m_active)
    {
        //iterate though scancodes of the libraby
        for (int i = graphics::SCANCODE_A; i < graphics::SCANCODE_Z; i++)
        {
            graphics::scancode_t sct = static_cast<graphics::scancode_t>(i);
            if (graphics::getKeyState(sct))
            {
                //Show the lowercase letters
                str += static_cast<char>(i+93);
            }
        }
    }

    //backspace
    if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE))
    {
        //remove the last letter of the string
        str = str.substr(0, str.size() - 1);
    }

    //space
    if (graphics::getKeyState(graphics::SCANCODE_SPACE))
    {
        //add space
        str += static_cast<char>(32);
    }

    graphics::setFont(ASSET_PATH"OpenSans-Regular.ttf");

    if (str.length() < 28)
    {
        graphics::drawText(x_pos - 90, y_pos + 4, 12, str, br);
    }
    else
    {
        //animation to erase the first letter if the we type too many words is the search bar that doesnt make sense
        str.erase(str.begin());
        graphics::drawText(x_pos - 90, y_pos + 4, 12, str, br);
    }
}

SearchBar::SearchBar(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color)
	:Button{ x_pos = x_pos, y_pos = y_pos, size_x = size_x, size_y = size_y, r_color = r_color, g_color = g_color, b_color = b_color } {}

