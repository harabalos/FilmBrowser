#pragma once
#include "Film.h"
#include <vector>
#include "Button.h"


class FilmBrowser
{
public:
	enum filmState { STATE_INIT, STATE_LOADING, STATE_IDLE };

protected:
	static FilmBrowser* m_instance;
	std::vector<Film*> allFilms;
	Button filmGenre0{ 25.0f, 270.0f, 1.0f, 1.0f, 1.0f, {"Drama"}};
	Button filmGenre1{ 25.0f, 270.0f, 1.0f, 1.0f, 1.0f, {"Adventure","Action"}};
	Button filmGenre2{ 25.0f, 270.0f, 1.0f, 1.0f, 1.0f, {"Drama","Crime"}};
	Button filmGenre3{ 25.0f, 270.0f, 1.0f, 1.0f, 1.0f, {"Adventure","Action","Fantasy"}};
	Button filmGenre4{ 25.0f, 270.0f, 1.0f, 1.0f, 1.0f, {"Drama","History"}};
	Button filmGenre5{ 25.0f, 270.0f, 1.0f, 1.0f, 1.0f, {"Sci fi","Action"}};
	Film* m_active_film = nullptr;
	FilmBrowser() {};
		 

public:
	void update();
	void draw();
	void init();
	static FilmBrowser* getInstance();
	static void releaseInstance() { if (m_instance)delete m_instance; m_instance = nullptr;};
	~FilmBrowser();
};