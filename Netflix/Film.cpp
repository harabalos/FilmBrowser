#include "Film.h"
#include "graphics.h"
#include "config.h"
#include "Button.h"
#include "GenreButton.h"



void Film::update()
{


	graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasX(ms.cur_pos_y);

	graphics::Brush br;
	init(0);
	graphics::drawText(30, 250, 35, getName(), br);
	init(1);
	graphics::drawText(30, 320, 16, "Director:", br);
	graphics::drawText(140, 320, 16, getDirector(), br);
	graphics::drawText(30, 340, 16, "Stars:", br);
	graphics::drawText(140, 340, 16, getProtagonist(), br);
	graphics::drawText(30, 360, 16, "Year:", br);
	graphics::drawText(140, 360, 16, getProductionDate(), br);
	graphics::drawText(30, 400, 16, "Summary:", br);
	if (getSummary().size() > 70) {
		std::string phrase1{ "" };
		float j = 420;
		int p = 0;
		for (char i : getSummary())
		{
			phrase1 += i;
			if (phrase1.size()>70 && i==' ') {
				graphics::drawText(30, j, 16, phrase1, br);
				phrase1.erase(0, phrase1.size() - 1);
				j += 20;
			}
			else if (p == getSummary().size() - 1) {
				graphics::drawText(30, j, 16, phrase1, br);
			}
			p++;
		}
	}
	else {
		graphics::drawText(10, 420, 16, getSummary(), br);
	}
	getFilmGenre().draw();

	//if (getFilmGenre().contains(mx, my))
	//{
	//	getFilmGenre().setHighlight(true);
	//}
	//else
	//{
	//	getFilmGenre().setHighlight(false);
	//}


	//for (size_t i = 0; i < getFilmGenre().getKind().size(); i++)
	//{
	//	if (getFilmGenre()->contains(mx, my))
	//	{
	//		allFilms[i]->getFilmGenre().setHighlight(false);
	//	}
	//	else
	//	{
	//		allFilms[i]->getFilmGenre().setHighlight(true);
	//	}
	//}

}

void Film::draw(int i)
{
	graphics::Brush br;

	float h = 1.0f * m_highlighted;
	float glow = 0.7f + 0.3f * sinf(graphics::getGlobalTime());


	br.fill_color[0] = h;
	br.fill_color[1] = h;
	br.fill_color[2] = h;
	br.outline_opacity = glow * m_active;
	graphics::drawRect(m_pos[0], m_pos[1], 102, 136, br);


	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.fill_opacity = 1.0f;
	br.texture = ASSET_PATH+std::string("pic" + to_string(i) + ".png");
	br.outline_opacity = 0.0f;
	graphics::drawRect(m_pos[0], m_pos[1], 96, 128, br);

	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.fill_opacity = 1.0f;
	br.texture = ASSET_PATH + std::string("pic" + to_string(i) + ".png");
	br.outline_opacity = 0.0f;
	br.fill_opacity = 0.2f;
	graphics::setOrientation(180.0f);
	graphics::drawRect(m_pos[0], m_pos[1] + 120, 96, 128, br);
	graphics::resetPose();

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

Film::Film(std::string name, std::string productionDate, std::string director, std::string protagonist, GenreButton filmGenre, std::string summary)
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

GenreButton Film::getFilmGenre()
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
