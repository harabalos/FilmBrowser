#pragma once
#include "Button.h"
#include "GenreButton.h"
#include "Slider.h"
#include "SearchBar.h"
#include <vector>



class Dock:public Button
{

public:
	GenreButton* clearbutton = new GenreButton(680 , -90 , 70 , 25 , 0.7f , 0.7f , 0.0f , "Clear Filters" );
	//GenreButton* m_active_button = nullptr;
	Slider* m_active_sliderFrom = nullptr;
	Slider* m_active_sliderTo = nullptr;
	Slider* sliderFrom = new Slider(300, -90,8,16,0.7f,0.7f,0.7f,true);
	Slider* sliderTo = new Slider(390, -90, 8, 16, 0.7f, 0.7f, 0.7f,false);
	SearchBar* titleSearch = new SearchBar(635, -90, 200, 18,0.7f,0.7f,0.7f);
	SearchBar* actorSearch = new SearchBar(635, -90, 200, 18,0.7f,0.7f,0.7f);
	SearchBar* directorSearch = new SearchBar(635, -90, 200, 18,0.7f,0.7f,0.7f);

	//GenreButton* Drama = new GenreButton(300, -90, 42, 16, 0.65f, 0.65f, 0.65f, "Drama");
	//GenreButton* History = new GenreButton(350, -90, 42, 16, 0.65f, 0.65f, 0.65f, "History");
	//GenreButton* SciFi = new GenreButton(400, -90, 42, 16, 0.65f, 0.65f, 0.65f, "SciFi");
	//GenreButton* Action = new GenreButton(450, -90, 42, 16, 0.65f, 0.65f, 0.65f, "Action");
	//GenreButton* Crime = new GenreButton(500, -90, 42, 16, 0.65f, 0.65f, 0.65f, "Crime");
	//GenreButton* Fantasy = new GenreButton(550, -90, 42, 16, 0.65f, 0.65f, 0.65f, "Fantasy");
	//GenreButton* Adventure = new GenreButton(600, -90, 42, 16, 0.65f, 0.65f, 0.65f, "Adventure");
	//std::vector<GenreButton*> filmGenres = { Drama,History ,SciFi ,Action ,Crime ,Fantasy ,Adventure };
	
	Dock();
	~Dock();
	void update();
	void draw();
};