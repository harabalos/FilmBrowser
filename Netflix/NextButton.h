#pragma once
#include "Button.h"


class NextButton:public Button
{
	bool dir;
public:
	NextButton(bool dir);
	~NextButton();
	void draw() override;
	void update() override;
};