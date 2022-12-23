#include "Film.h"
#include "graphics.h"
#include "config.h"
#include "Button.h"



void Film::update()
{
}

void Film::draw()
{
	graphics::Brush br;
	init(0);
	graphics::drawText(10, 250, 35, getName(), br);
	init(1);
	graphics::drawText(10, 320, 16, "Director:", br);
	graphics::drawText(150, 320, 16, getDirector(), br);
	graphics::drawText(10, 340, 16, "Stars:", br);
	graphics::drawText(150, 340, 16, getProtagonist(), br);
	graphics::drawText(10, 360, 16, "Year:", br);
	graphics::drawText(150, 360, 16, getProductionDate(), br);
	graphics::drawText(10, 400, 16, "Summary:", br);
	graphics::drawText(10, 420, 16, getSummary(), br);
	getFilmGenre().draw();
	

}

void Film::init(int choice)
{
	if (choice == 0)
	{
		graphics::setFont(ASSET_PATH"OpenSans-Semibold.ttf");
	}
	else if(choice == 1)
	{
		graphics::setFont(ASSET_PATH"OpenSans-Regular.ttf");
	}
	else if (choice == 2)
	{
		graphics::setFont(ASSET_PATH"OpenSans-Light.ttf");
	}

}

Film::Film(std::string name, std::string productionDate, std::string director, std::string protagonist, Button filmGenre, std::string summary)
	:name{ name }, productionDate{ productionDate }, director{ director }, protagonist{ protagonist }, filmGenre{ filmGenre }, summary{ summary } {}

Film::~Film()
{
}

std::string Film::getName() {
	return name;
}

std::string Film::getProductionDate()
{
	return productionDate;
}

std::string Film::getDirector()
{
	return director;
}

std::string Film::getProtagonist()
{
	return protagonist;
}

Button Film::getFilmGenre()
{
	return filmGenre;
}

std::string Film::getSummary()
{
	return summary;
}
