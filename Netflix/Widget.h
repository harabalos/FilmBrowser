#pragma once
#include <string>

//abstract class
class Widget
{
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	inline void widgetSize(float& x, float& y, const std::string kind) { float sum = 0; for (char i : kind) sum += 7;x = sum;}
	virtual ~Widget() {};
};


