#include "Button.h" 
#include "graphics.h"
#include "config.h"

bool Button::contains(float x, float y)
{
	return distance(x, y, x_pos, y_pos)<20;
}


Button::Button(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color)
	:x_pos{ x_pos }, y_pos{ y_pos }, size_x{ size_x }, size_y{ size_y }, r_color{ r_color }, g_color{ g_color }, b_color{ b_color } {}



void Button::update()
{


}

