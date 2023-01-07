#pragma once
#include "Button.h"
#include "GenreButton.h"
#include "Slider.h"
#include "SearchBar.h"
#include <vector>



class Dock:public Button
{

public:

	//we initialize everything inside the dock with y = -90, because we dont want to see it if the dock is not active
	
	GenreButton* clearbutton = new GenreButton(680 , -90 , 70 , 25 , 0.7f , 0.7f , 0.0f , "Clear Filters" );
	Slider* m_active_sliderFrom = nullptr;
	Slider* m_active_sliderTo = nullptr;
	SearchBar* m_active_searchBar = nullptr;
	Slider* sliderFrom = new Slider(300, -90,8,16,0.7f,0.7f,0.7f,true);
	Slider* sliderTo = new Slider(390, -90, 8, 16, 0.7f, 0.7f, 0.7f,false);
	SearchBar* titleSearch = new SearchBar(635, -90, 200, 18,0.7f,0.7f,0.7f);
	SearchBar* actorSearch = new SearchBar(635, -90, 200, 18,0.7f,0.7f,0.7f);
	SearchBar* directorSearch = new SearchBar(635, -90, 200, 18,0.7f,0.7f,0.7f);
	GenreButton* Drama = new GenreButton(300, -90, 55, 16, 0.65f, 0.65f, 0.65f, "Drama");
	GenreButton* History = new GenreButton(360, -90, 55, 16, 0.65f, 0.65f, 0.65f, "History");
	GenreButton* SciFi = new GenreButton(420, -90, 55, 16, 0.65f, 0.65f, 0.65f, "SciFi");
	GenreButton* Action = new GenreButton(480, -90, 55, 16, 0.65f, 0.65f, 0.65f, "Action");
	GenreButton* Crime = new GenreButton(300, -90, 55, 16, 0.65f, 0.65f, 0.65f, "Crime");
	GenreButton* Fantasy = new GenreButton(360, -90, 55, 16, 0.65f, 0.65f, 0.65f, "Fantasy");
	GenreButton* Adventure = new GenreButton(420, -90, 55, 16, 0.65f, 0.65f, 0.65f, "Adventure");
	std::vector<SearchBar*> searchbars = { titleSearch ,actorSearch,directorSearch };
	std::vector<GenreButton*> filmGenres = { Drama,History ,SciFi ,Action ,Crime ,Fantasy ,Adventure };

	//variables that help us check whether the sound is played one time or not
	bool playSoundMax = true;
	bool playSoundMin = false;


	//variable for the dock animation
	float anim = 0;
	Dock();
	~Dock() {};
	void update();
	void draw();
};