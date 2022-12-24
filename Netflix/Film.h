#pragma once
#include <string>
#include "Button.h"
using namespace std;



class Film
{
private:
	string name; 
	string productionDate;
	string director;
	string protagonist;
	Button filmGenre;
	string summary;


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
};