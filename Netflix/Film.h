#pragma once
#include <string>
#include "Button.h"
using namespace std;



class Film
{
private:
	float m_pos[2];

	string name; 
	string productionDate;
	string director;
	string protagonist;
	Button filmGenre;
	string summary;

	bool m_highlighted = false;
public:
	Film(string name, string productionDate, string director, string protagonist, Button filmGenre,string summary);
	~Film();

	void update();
	void draw(int i);
	void init(int choice);
	string getProductionDate();
	string getName();
	string getDirector();
	string getProtagonist();
	Button getFilmGenre();
	string getSummary();

	void setX(float x) { m_pos[0] = x; };
	void setY(float y) { m_pos[1] = y; };

	void setHighlight(bool h) { m_highlighted = h; };

	bool contains(float x, float y);

};