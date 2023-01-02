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
	bool m_highlighted1 = false;
	bool m_active = false;
public:
	Button(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color);
	bool contains(float x, float y);
	bool contains(float x, float y, float x1, float y1,float z);
	void setHighlight(bool h) { m_highlighted = h; };
	void setHighlight1(bool h) { m_highlighted1 = h; };
	void setActive(bool a) { m_active = a; };
	bool getActive() { return m_active; };
	void setX(float x) { x_pos = x; };
	void setY(float y) { y_pos = y; };
};


