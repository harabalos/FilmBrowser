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

	bool m_highlighted = false;
	bool m_active = false;
public:
	Button(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color);
	bool contains(float x, float y);
	void setHighlight(bool h) { m_highlighted = h; };
	void setActive(bool a) { m_active = a; };
	void setX(float x) { x_pos = x; };
	void setY(float y) { y_pos = y; };
};


