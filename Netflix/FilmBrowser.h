#pragma once
#include "Film.h"
#include <vector>
#include "GenreButton.h"


class FilmBrowser
{
public:
	enum film_state {STATE_INIT,STATE_IDLE};
protected:
	static FilmBrowser* m_instance;
	std::vector<Film*> allFilms;
	Film* m_active_film = nullptr;
	GenreButton filmGenre0 = GenreButton(30, 285, 42, 16, 0.8f, 0.8f, 0.8f, {"Drama"});
	GenreButton filmGenre1 = GenreButton(30, 285, 42, 16, 0.8f, 0.8f, 0.8f, { "Drama","History" });
	GenreButton filmGenre2 = GenreButton(30, 285, 42, 16, 0.8f, 0.8f, 0.8f, { "SciFi","Action" });
	GenreButton filmGenre3 = GenreButton(30, 285, 42, 16, 0.8f, 0.8f, 0.8f, { "Adventure","Action" });
	GenreButton filmGenre4 = GenreButton(30, 285, 42, 16, 0.8f, 0.8f, 0.8f, { "Drama","Crime" });
	GenreButton filmGenre5 = GenreButton(30, 285, 42, 16, 0.8f, 0.8f, 0.8f, { "Adventure","Action","Fantasy" });
	FilmBrowser() {};
		 

public:
	void update();
	void draw();
	void init();
	static FilmBrowser* getInstance();
	static void releaseInstance() { if (m_instance)delete m_instance; m_instance = nullptr;};
	~FilmBrowser();
};