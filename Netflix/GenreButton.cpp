#include "GenreButton.h"
#include "graphics.h"
#include "config.h"
#include <string>
#include <vector>
#include "FilmBrowser.h"
#include "Film.h"

//constructor for the genre buttons below the films
GenreButton::GenreButton(std::string kind)
	:Button{ x_pos =48 , y_pos = 285,size_x = 55, size_y = 16,  r_color = 0.65f, g_color = 0.65f, b_color = 0.65f }, kind{ kind } {}

//constructor for the genre buttons of the dock and the clear button
GenreButton::GenreButton(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color, std::string kind)
	:Button{ x_pos = x_pos , y_pos = y_pos , size_x = size_x , size_y = size_y , r_color = r_color , g_color = g_color , b_color = b_color }, kind{ kind } {}


void GenreButton::draw()
{
	//variable that if gets > 1.0f if it highlighted, this is just for the effect 
	//animation
	float h = r_color + m_highlighted;
		graphics::Brush br;
		//draw button
		if (kind == "Clear Filters")
		{
			if (!m_highlighted)
			{
				br.fill_color[0] = r_color;
				br.fill_color[1] = g_color;
				br.fill_color[2] = b_color;
			}
			else
			{
				br.fill_color[0] = r_color+ 0.2f;
				br.fill_color[1] = g_color + 0.2f;
				br.fill_color[2] = b_color + 0.2f;
			}

		}
		else
		{
			br.fill_color[0] = h;
			br.fill_color[1] = h;
			br.fill_color[2] = h;
		}
		br.outline_opacity = 0.0f;
		graphics::drawRect(x_pos , y_pos, size_x, size_y, br);

		br.fill_color[0] = 0.0f;
		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 0.0f;
		graphics::setFont(ASSET_PATH"OpenSans-Regular.ttf");
		graphics::drawText(((x_pos)-(kind.length() / 2.0f) * 5.5f), y_pos + 3, 10, kind, br);
	
}

void GenreButton::update() {}

std::string GenreButton::getKind()
{
	return kind;
}


