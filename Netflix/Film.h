#pragma once
#include <string>
using namespace std;



class Film
{
private:
	string name; 
	string productionDate;
	string director;
	string protagonist;
	string filmGenre;
	string summary;


public:
	Film(string name, string productionDate, string director, string protagonist, string filmGenre,string summary);
	~Film();

	void update();
	void draw();
	void init(int choice);
	string getProductionDate();
	string getName();
	string getDirector();
	string getProtagonist();
	string getFilmGenre();
	string getSummary();
};