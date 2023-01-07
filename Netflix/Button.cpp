#include "Button.h" 
#include "graphics.h"
#include "config.h"


//function that helps us checks if the mouse is over the specified coordinates for circle
bool Button::contains(float x, float y, float x1, float y1,float z)
{
	return distance(x, y, x1, y1) < z;
}

Button::~Button(){}


//function that helps us checks if the mouse is over the specified coordinates for rectangle
bool Button::contains(float x, float y, float button_size_x, float button_size_y)
{
	bool contain = false;
	float container_x[2]{ x_pos - button_size_x / 2,x_pos + button_size_x / 2 };
	float container_y[2]{ y_pos - button_size_y / 2,y_pos + button_size_y / 2 };
	if ((x >= container_x[0] && x <= container_x[1]) && (y >= container_y[0] && y <= container_y[1])) {
		contain = true;
	}

	return contain;
}

//function that helps us checks if the mouse is over the specified coordinates for rectangle

bool Button::contains(float x, float y,float x_pos,float y_pos, float button_size_x, float button_size_y)
{
	bool contain = false;
	float container_x[2]{ x_pos - button_size_x / 2,x_pos + button_size_x / 2 };
	float container_y[2]{ y_pos - button_size_y / 2,y_pos + button_size_y / 2 };
	if ((x >= container_x[0] && x <= container_x[1]) && (y >= container_y[0] && y <= container_y[1])) {
		contain = true;
	}

	return contain;
}





Button::Button(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color)
	:x_pos{ x_pos }, y_pos{ y_pos }, size_x{ size_x }, size_y{ size_y }, r_color{ r_color }, g_color{ g_color }, b_color{ b_color } {}


