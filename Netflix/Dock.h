#pragma once
#include "Button.h"
#include "GenreButton.h"

class Dock:public Button
{

public:
	GenreButton* clearbutton = new GenreButton(600 , -90 , 70 , 25 , 1.0f , 1.0f , 0.0f , "Clear Filters" );
	Dock();
	~Dock();
	void update();
	void draw();
};