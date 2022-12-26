#include "Film.h"
#include "graphics.h"
#include "config.h"
#include "Button.h"



void Film::update()
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

void Film::draw(int i)
{
	graphics::Brush br;

	float h = 1.0f * m_highlighted;


	br.fill_color[0] = h;
	br.fill_color[1] = h;
	br.fill_color[2] = h;
	br.outline_opacity = 1.0f * m_active;
	graphics::drawRect(m_pos[0], m_pos[1], 102, 136, br);


	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.fill_opacity = 1.0f;
	br.texture = ASSET_PATH+std::string("pic" + to_string(i) + ".png");
	br.outline_opacity = 0.0f;
	graphics::drawRect(m_pos[0], m_pos[1], 96, 128, br);
	

	

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

bool Film::contains(float x, float y)
{
	return distance(x, y, m_pos[0], m_pos[1]) < 50;
}