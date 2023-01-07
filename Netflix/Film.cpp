
#include "Film.h"
#include "graphics.h"
#include "config.h"
#include "Button.h"
#include "GenreButton.h"
#include "NextButton.h"
#include "FilmBrowser.h"

void Film::update()
{

	//get the coordinates of the mouse
	graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasX(ms.cur_pos_y);


	//variables that helps us set the buttons as highlighted
	GenreButton* cur_but = nullptr;
	NextButton* cur_nxtBut = nullptr;


	//draw content of each film
	graphics::Brush br;
	init(0);
	graphics::drawText(30, 250, 35, getName(), br);
	init(1);
	graphics::drawText(30, 320, 16, "Director:", br);
	graphics::drawText(140, 320, 16, getDirector(), br);
	graphics::drawText(30, 340, 16, "Stars:", br);
	graphics::drawText(140, 340, 16, getProtagonist(), br);
	graphics::drawText(30, 360, 16, "Year:", br);
	graphics::drawText(140, 360, 16, to_string(getProductionDate()), br);
	graphics::drawText(30, 400, 16, "Summary:", br);
	//make the summary letters go in more than one line
	if (getSummary().size() > 70) {
		std::string phrase1{ "" };
		float j = 420;
		int p = 0;
		for (char i : getSummary())
		{
			phrase1 += i;
			if (phrase1.size() > 70 && i == ' ') {
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

	//draw the shots of each film
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.fill_opacity = 1.0f;
	string shotPath = ASSET_PATH + std::string("pic" + to_string(geti()) + "shots\\" + "shot" + to_string(j) + ".png");
	br.texture = ASSET_PATH + std::string("pic" + to_string(geti()) + "shots\\" + "shot" + to_string(j) + ".png");
	br.outline_opacity = 1.0f;
	br.fill_opacity = 1.0f;
	graphics::drawRect(820, 370, 256, 144, br);


	//draws the next buttons
	if (fileExists((ASSET_PATH + std::string("pic" + to_string(geti()) + "shots\\" + "shot2.png")).c_str()))
	{
		nextButtonR->draw();
		nextButtonL->draw();

		//set the buttons a little bit highlited if the mouse enters the coordinates of the picture
		nextButtonR->setHighlight(nextButtonR->contains(mx, my, 820, 370,256,144));
		nextButtonL->setHighlight(nextButtonL->contains(mx, my, 820, 370,256,144));

		
		//sets the buttons as highlited if the mouse enters the coordinates of the button
		if (nextButtonL->contains(mx, my,nextButtonL->getX(),nextButtonL->getY(),20))
		{
			nextButtonL->setHighlight1(true);
			cur_nxtBut = nextButtonL;
		}
		else
		{
			nextButtonL->setHighlight1(false);
		}

		//same here
		if (nextButtonR->contains(mx, my, nextButtonR->getX() + 200, nextButtonL->getY(), 20))
		{
			nextButtonR->setHighlight1(true);
			cur_nxtBut = nextButtonR;
		}
		else
		{
			nextButtonR->setHighlight1(false);
		}

		//sets the button as active if pressed
		if (ms.button_left_pressed && cur_nxtBut)
		{
			m_active_nxtbutton = cur_nxtBut;
			m_active_nxtbutton->setActive(true);

			//if the right button is pressed
			if (m_active_nxtbutton == nextButtonR)
			{
				//we set the other one as inactive
				nextButtonL->setActive(false);
				j++;
				//if there is no other picture after this one then go to the first image
				if (!fileExists((ASSET_PATH + std::string("pic" + to_string(geti()) + "shots\\" + "shot" + to_string(j) + ".png")).c_str()))
				{
					j = 1;
				}
			}
			else
			{
				//else set the right button as inactive
				nextButtonR->setActive(false);
				j--;
				//if there is no other picture before this one then go to the last one
				if (!fileExists((ASSET_PATH + std::string("pic" + to_string(geti()) + "shots\\" + "shot" + to_string(j) + ".png")).c_str()))
				{
					while (!fileExists((ASSET_PATH + std::string("pic" + to_string(geti()) + "shots\\" + "shot" + to_string(last) + ".png")).c_str()))
					{
						last--;
					}
					j = last;
				}
			}
		}
	}


	//draw each button
	for (size_t i = 0; i < getFilmGenre().size(); i++)
	{
		getFilmGenre()[i]->draw();
	}


	//genre button gets highlighted
	for (auto button : getFilmGenre())
	{
		if (button->contains(mx, my, button->getsizeX(), button->getsizeY()))
		{
			button->setHighlight(true);
			cur_but = button;
		}
		else
		{
			button->setHighlight(false);
		}
	}


	//genrebutton gets activated
	if (ms.button_left_pressed && cur_but)
	{
		m_active_button = cur_but;
		m_active_button->setActive(true);
		graphics::playSound(ASSET_PATH"button.wav", 0.5f);

		for (auto button : getFilmGenre())
		{
			if (button != m_active_button)
			{
				button->setActive(false);
			}
		}
	}

}

void Film::draw()
{
	graphics::Brush br;

	//variable that if gets > 1.0f if it highlighted, this is just for the effect 
	//animation
	float h = 1.0f * m_highlighted;

	//more animation
	//variable that gets values between 0.7 and 1.0 while the application runs
	//so when the film is activated the outline seems like it glows
	float glow = 0.7f + 0.3f * sinf(graphics::getGlobalTime());

	//draw rectangle before the film
	br.fill_color[0] = h;
	br.fill_color[1] = h;
	br.fill_color[2] = h;
	br.outline_opacity = glow * m_active;
	graphics::drawRect(m_pos[0], m_pos[1], 102, 136, br);


	//draw film
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.fill_opacity = 1.0f;
	br.texture = ASSET_PATH + std::string("pic" + to_string(geti()) + ".png");
	br.outline_opacity = 0.0f;
	graphics::drawRect(m_pos[0], m_pos[1], 96, 128, br);

	//draw shadow of the film
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.fill_opacity = 1.0f;
	br.texture = ASSET_PATH + std::string("pic" + to_string(geti()) + ".png");
	br.outline_opacity = 0.0f;
	br.fill_opacity = 0.2f;
	graphics::setOrientation(180.0f);
	graphics::drawRect(m_pos[0], m_pos[1] + 120, 96, 128, br);
	graphics::resetPose();

}

void Film::init(int choice)
{
	//initialization of fonts
	if (choice == 0)
	{
		graphics::setFont(ASSET_PATH"OpenSans-Semibold.ttf");
	}
	else if (choice == 1)
	{
		graphics::setFont(ASSET_PATH"OpenSans-Regular.ttf");
	}
	else if (choice == 2)
	{
		graphics::setFont(ASSET_PATH"OpenSans-Light.ttf");
	}

	//sets the coordinates of the genre buttons
	for (int i = 0; i < getFilmGenre().size(); i++)
	{
		getFilmGenre()[i]->setX(58 + (i * 63.0f));
		getFilmGenre()[i]->setY(285);

	}
}

Film::Film(std::string name, int productionDate, std::string director, std::string protagonist, std::vector<GenreButton*> filmGenre, std::string summary, int i)
	:name{ name }, productionDate{ productionDate }, director{ director }, protagonist{ protagonist }, filmGenre{ filmGenre }, summary{ summary }, i{ i } {}


std::string Film::getName() {
	return name;
}

int Film::getProductionDate()
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

std::vector<GenreButton*>  Film::getFilmGenre()
{
	return filmGenre;
}

std::string Film::getSummary()
{
	return summary;
}

int Film::geti()
{
	return i;
}


//function that helps us checks if the mouse is over the specified coordinates
bool Film::contains(float x, float y, float button_size_x, float button_size_y)
{
	bool contain = false;
	float container_x[2]{ m_pos[0] - button_size_x / 2,m_pos[0] + button_size_x / 2 };
	float container_y[2]{ m_pos[1] - button_size_y / 2,m_pos[1] + button_size_y / 2 };
	if ((x >= container_x[0] && x <= container_x[1]) && (y >= container_y[0] && y <= container_y[1])) {
		contain = true;
	}

	return contain;
}


//function that helps us check if the file exists
//this function is for the picture-shots 
bool Film::fileExists(const char* path)
{

	const char* dir = path;
	struct stat sb;
	if (stat(dir, &sb) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
