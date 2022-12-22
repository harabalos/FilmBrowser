#pragma once
#include "Widget.h"

class Button :public Widget
{
private:
	float x_pos; // position
	float y_pos;
	float r_color; //color
	float g_color;
	float b_color;


public:
	Button(float x_pos, float y_pos, float r_color,float g_color,float b_color);

	void draw() override;
	void update() override;
};