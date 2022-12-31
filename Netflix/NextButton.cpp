#include "NextButton.h"
#include "graphics.h"
#include "config.h"

NextButton::NextButton(bool dir)
	:Button{ x_pos = 720 , y_pos = 370,size_x = 28, size_y = 28, r_color = 1.0f, g_color = 1.0f, b_color = 1.0f }, dir{ dir } {}

NextButton::~NextButton()
{
}


void NextButton::update()
{
	graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasX(ms.cur_pos_y);

}



void NextButton::draw()
{
	graphics::Brush br;

	if (dir)
	{
		br.fill_color[0] = 0.5f + m_active;
		br.fill_color[1] = g_color;
		br.fill_color[2] = b_color;
		br.fill_opacity = 1.0f;
		br.texture = ASSET_PATH + std::string("arrow.png");
		br.outline_opacity = 0.0f;
		br.fill_opacity = 0.0f + (m_highlighted - 0.5f) + m_highlighted1;
		graphics::drawRect(x_pos, y_pos, size_x, size_y, br);
	}
	else
	{
		br.fill_color[0] = 0.5f + m_active;
		br.fill_color[1] = g_color;
		br.fill_color[2] = b_color;
		br.fill_opacity = 1.0f;
		br.texture = ASSET_PATH + std::string("arrow.png");
		br.outline_opacity = 0.0f;
		br.fill_opacity = 0.0f + (m_highlighted - 0.5f) + m_highlighted1;
		graphics::setOrientation(180.0f);
		graphics::drawRect(x_pos + 200, y_pos, size_x, size_y, br);
		graphics::resetPose();
	}
}

