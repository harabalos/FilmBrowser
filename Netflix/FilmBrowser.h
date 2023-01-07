#pragma once
#include "Film.h"
#include <vector>
#include "GenreButton.h"
#include "Dock.h"


class FilmBrowser
{
public:
	//initialization of the states
	enum film_state {START,DRAMA,HISTORY,SCIFI,ACTION,CRIME,FANTASY,ADVENTURE};
	//initialization of evety genre button
	GenreButton* Drama = new GenreButton("Drama");
	GenreButton* History = new GenreButton("History");
	GenreButton* SciFi = new GenreButton("SciFi");
	GenreButton* Action = new GenreButton("Action");
	GenreButton* Crime = new GenreButton("Crime");
	GenreButton* Fantasy = new GenreButton("Fantasy");
	GenreButton* Adventure = new GenreButton("Adventure");
	GenreButton* m_active_button = nullptr;
protected:
	//unique static instance of this class
	static FilmBrowser* m_instance;
	//initialization of each genre vector
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
	Dock* dock = new Dock();


public:
	void update();
	void draw();
	void init();
	static FilmBrowser* getInstance();
	//deletes the instance
	static void releaseInstance() { if (m_instance)delete m_instance; m_instance = nullptr;};
	void filterFilms(std::vector<Film*> f);
	string lowerCase(string str);
	~FilmBrowser();
	FilmBrowser() {};
};