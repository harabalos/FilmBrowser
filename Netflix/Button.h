#pragma once
#include "Widget.h"
#include <string>

class Button :public Widget
{
private:
	float x_pos; // position
	float y_pos;
	float r_color; //color
	float g_color;
	float b_color;
	std::string genre;


public:
	Button(float x_pos, float y_pos, float r_color,float g_color,float b_color,std::string genre);

	void draw() override;
	void update() override;
};