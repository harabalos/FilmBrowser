#include "Slider.h"
#include "graphics.h"


Slider::Slider(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color)
	:Button{ x_pos = x_pos , y_pos = y_pos , size_x = size_x , size_y = size_y , r_color = r_color , g_color = g_color , b_color = b_color } {}

Slider::~Slider()
{
}

void Slider::draw()
{
	graphics::Brush br;
	float h = r_color + m_highlighted;

	br.fill_color[0] = h;
	br.fill_color[1] = h;
	br.fill_color[2] = h;
	br.outline_opacity = 1.0f;
	graphics::drawLine(300, y_pos, 390, y_pos, br);
	graphics::drawRect(x_pos, y_pos, size_x, size_y, br);




}

void Slider::update()
{
}
