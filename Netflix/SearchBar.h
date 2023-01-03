#pragma once
#include "Button.h"

class SearchBar:public Button
{
public:
	void draw();
	void update();
	SearchBar(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color);
	~SearchBar();

};