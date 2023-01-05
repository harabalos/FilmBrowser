#pragma once
#include <string>
#include <vector>
#include "NextButton.h"
#include "GenreButton.h"
using namespace std;



class Film
{
private:
	int m_pos[2];

	string name; 
	int productionDate;
	string director;
	string protagonist;
	std::vector<GenreButton*> filmGenre;
	string summary;
	int i;


	bool m_highlighted = false;
	bool m_active = false;

public:
	Film(string name, int productionDate, string director, string protagonist, std::vector<GenreButton*> filmGenre ,string summary,int i);
	~Film();
	GenreButton* m_active_button = nullptr;
	NextButton* m_active_nxtbutton = nullptr;
	void update();
	void draw();
	void init(int choice);
	int getProductionDate();
	string getName();
	string getDirector();
	string getProtagonist();
	std::vector<GenreButton*>  getFilmGenre();
	string getSummary();
	int geti();
	NextButton* nextButtonL = new NextButton(true);
	NextButton* nextButtonR = new NextButton(false);
	int j = 1;
	int last = 6;

	void setX(float x) { m_pos[0] = x; };
	void setY(float y) { m_pos[1] = y; };

	void setHighlight(bool h) { m_highlighted = h; };
	void setActive(bool a) { m_active = a; };

	bool contains(float x, float y);
	bool fileExists(const char* path);

};