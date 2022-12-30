#pragma once
#include "Film.h"
#include <vector>
#include "GenreButton.h"


class FilmBrowser
{
public:
	enum film_state {START,IDLE,DRAMA,HISTORY,SCIFI,ACTION,CRIME,FANTASY,ADVENTURE};
	GenreButton* Drama = new GenreButton("Drama");
	GenreButton* History = new GenreButton("History");
	GenreButton* SciFi = new GenreButton("SciFi");
	GenreButton* Action = new GenreButton("Action");
	GenreButton* Crime = new GenreButton("Crime");
	GenreButton* Fantasy = new GenreButton("Fantasy");
	GenreButton* Adventure = new GenreButton("Adventure");
protected:
	static FilmBrowser* m_instance;
	std::vector<Film*> films;
	std::vector<Film*> allFilms;
	std::vector<Film*> dramaFilms;
	std::vector<Film*> historyFilms;
	std::vector<Film*> scifiFilms;
	std::vector<Film*> actionFilms;
	std::vector<Film*> crimeFilms;
	std::vector<Film*> fantasyFilms;
	std::vector<Film*> adventureFilms;
	Film* m_active_film = nullptr;
	film_state state = START;



	std::vector<GenreButton*> filmGenres;



public:
	void update();
	void draw();
	void init();
	static FilmBrowser* getInstance();
	static void releaseInstance() { if (m_instance)delete m_instance; m_instance = nullptr;};
	~FilmBrowser();
	FilmBrowser() {};
};