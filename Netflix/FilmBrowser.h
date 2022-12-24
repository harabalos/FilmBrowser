#pragma once
#include "Film.h"
#include <vector>
#include "Button.h"


class FilmBrowser
{
	static FilmBrowser* m_instance;
	
	std::vector<Film*> allFilms;
	Button filmGenre{ 25.0f, 270.0f, 1.0f, 1.0f, 1.0f, {"Drama"}};
	FilmBrowser() {};
		 

public:
	void update();
	void draw();
	void init();
	static FilmBrowser* getInstance();
	static void releaseInstance() { if (m_instance)delete m_instance; m_instance = nullptr;};
	~FilmBrowser();
};