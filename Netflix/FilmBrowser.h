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
	film_state state = STATE_INIT;
	GenreButton* filmGenre0 = new GenreButton("Drama");
	GenreButton* filmGenre1 = new GenreButton("History");
	GenreButton* filmGenre2 = new GenreButton( "SciFi");
	GenreButton* filmGenre3 = new GenreButton("Action" );
	GenreButton* filmGenre4 = new GenreButton( "Crime" );
	GenreButton* filmGenre5 = new GenreButton("Fantasy" );
	GenreButton* filmGenre6 = new GenreButton( "Adventure");
	FilmBrowser() {};
		 

public:
	void update();
	void draw();
	void init();
	static FilmBrowser* getInstance();
	static void releaseInstance() { if (m_instance)delete m_instance; m_instance = nullptr;};
	~FilmBrowser();
};