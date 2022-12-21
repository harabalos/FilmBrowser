#pragma once
#include "Film.h"
#include <vector>


class FilmBrowser
{
	Film*  fightClub = nullptr;
	std::vector<Film> allFilms;

public:
	void update();
	void draw();
	void init();
	void initializeVectorFilms();
	FilmBrowser();
	~FilmBrowser();
};