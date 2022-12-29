#pragma once
#include <string>
#include <vector>
#include "GenreButton.h"
using namespace std;



class Film
{
private:
	float m_pos[2];

	string name; 
	string productionDate;
	string director;
	string protagonist;
	std::vector<GenreButton*> filmGenre;
	string summary;
	int i;

	bool m_highlighted = false;
	bool m_active = false;

public:
	Film(string name, string productionDate, string director, string protagonist, std::vector<GenreButton*> filmGenre ,string summary,int i);
	~Film();
	GenreButton* m_active_button = nullptr;
	void update();
	void draw();
	void init(int choice);
	string getProductionDate();
	string getName();
	string getDirector();
	string getProtagonist();
	std::vector<GenreButton*>  getFilmGenre();
	string getSummary();
	int geti();

	void setX(float x) { m_pos[0] = x; };
	void setY(float y) { m_pos[1] = y; };

	void setHighlight(bool h) { m_highlighted = h; };
	void setActive(bool a) { m_active = a; };

	bool contains(float x, float y);



};