#include "Button.h"
#include "graphics.h"

void Button::update()
{
}

Button::Button(float x_pos, float y_pos, float r_color, float g_color, float b_color)
	:x_pos{ x_pos }, y_pos{ y_pos }, r_color{ r_color }, g_color{ g_color }, b_color{ b_color }{}

void Button::draw()
{
	graphics::Brush br;
	br.fill_color[0] = r_color;
	br.fill_color[1] = g_color;
	br.fill_color[2] = b_color;
	br.outline_opacity = 1.0f;
	graphics::drawRect(x_pos,y_pos,30,10,br);
}

