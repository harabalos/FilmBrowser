#pragma once
#include "Widget.h"
#include <string>
#include <vector>

class Button :public Widget
{
private:
	float x_pos; // position
	float y_pos;
	float r_color; //color
	float g_color;
	float b_color;
	std::vector<std::string> genre;
	bool highlighted = false;


public:
	Button(float x_pos, float y_pos, float r_color,float g_color,float b_color, std::vector<std::string> genre);

	void draw() override;
	void update() override;
	bool setHighlight(bool h) { highlighted = h; }
	bool contains(float x, float y);
};