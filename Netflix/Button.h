#pragma once
#include "Widget.h"
#include <string>
#include <vector>

class Button :public Widget
{
protected:
	float x_pos;
	float y_pos;
	float size_x;
	float size_y;
	float r_color;
	float g_color;
	float b_color;
public:
	Button(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color);
	void update() override;
	bool contains(float x, float y);
};


