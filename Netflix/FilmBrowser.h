#pragma once
#include "Film.h"
#include <vector>
#include "Button.h"


class FilmBrowser
{
	std::vector<Film*> allFilms;
	Button filmGenre {25.0f, 270.0f, 1.0f, 1.0f, 1.0f, "drama"};

		 

public:
	void update();
	void draw();
	void init();
	void initializeVectorFilms();
	FilmBrowser();
	~FilmBrowser();
};