#pragma once
#include "Button.h"

class Slider:public Button
{
private:
	bool up;
public:
	int yearsFrom;
	int yearsTo;
	Slider(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color,bool up);
	~Slider() {};
	void draw();
	void update();

};