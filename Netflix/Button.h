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

//#pragma once
//#include "Widget.h"
//#include <string>
//#include <vector>
//
//class Button :public Widget
//{
//public:
//	Button() {};
//	~Button();
//	virtual void widgetSize(float& x, float& y, std::string kind);
//	virtual void widgetPos(float& x, float& y, float num1, float num2);
//	virtual void draw();
//	virtual void update();
//};
//

