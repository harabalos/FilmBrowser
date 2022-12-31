#pragma once
#include <string>

class Widget
{
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	inline void widgetSize(float& x, float& y, std::string kind) { float sum = 0; for (char i : kind) sum += 7;x = sum;}
	//virtual void widgetPos(float& x, float& y, float num1, float num2) = 0;
	virtual ~Widget() {};
};


