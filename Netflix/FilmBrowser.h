#pragma once
#include "Film.h"
#include <vector>
#include "Button.h"


class FilmBrowser
{
	std::vector<Film*> allFilms;
	Button* button1 = new Button(80.0f,300.0f,1.0f,1.0f,1.0f);
	Button* button2 = new Button(100.0f, 200.0f, 1.0f, 1.0f, 1.0f);
		 

public:
	void update();
	void draw();
	void init();
	void initializeVectorFilms();
	FilmBrowser();
	~FilmBrowser();
};