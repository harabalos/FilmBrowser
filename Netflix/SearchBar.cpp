#include "SearchBar.h"
#include "graphics.h"
void SearchBar::draw()
{

	graphics::Brush br;
    br.outline_opacity = 1.0f;
    br.fill_color[0] = r_color;
    br.fill_color[1] = g_color;
    br.fill_color[2] = b_color;
    br.fill_opacity = 0.7f;

    graphics::drawRect(x_pos, y_pos, size_x, size_y, br);
}

void SearchBar::update()
{
}

SearchBar::SearchBar(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color)
	:Button{ x_pos = x_pos, y_pos = y_pos, size_x = size_x, size_y = size_y, r_color = r_color, g_color = g_color, b_color = b_color } {}

SearchBar::~SearchBar()
{
}
