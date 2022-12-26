#include "GenreButton.h"
#include "graphics.h"
#include "config.h"
#include <string>

GenreButton::GenreButton(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color, std::vector<std::string> kind)
	:x_pos{ x_pos }, y_pos{ y_pos }, size_x{ size_x }, size_y{ size_y }, r_color{ r_color }, g_color{ g_color }, b_color{ b_color }, kind{ kind } {}

GenreButton::~GenreButton()
{
}

void GenreButton::widgetSize(float& x, float& y, std::string kind)
{
	float sum = 0;
	for (char i : kind) {
		sum += 7;
	}
	x = sum;
}

void GenreButton::widgetPos(float& x, float& y, float num1, float num2)
{
	x = x + num1;
	y = y + num2;
}

void GenreButton::draw()
{
	float size_x1 = 0;
	for (size_t i = 0; i < kind.size(); i++)
	{
		widgetSize(size_x, size_y, kind[i]);
		if (i > 0) {
			widgetPos(x_pos, y_pos, (size_x1 / 2 + 5 + size_x / 2), 0);
		}
		else if (i == 0) {
			widgetPos(x_pos, y_pos, size_x / 2, 0);
		}
		graphics::Brush br;
		br.fill_color[0] = r_color;
		br.fill_color[1] = g_color;
		br.fill_color[2] = b_color;
		br.fill_opacity = 1.0f;
		if (i == 0) {
			graphics::drawRect(x_pos, y_pos, size_x, size_y, br);
		}
		else if (i < 4 || i>4) {
			graphics::drawRect(x_pos, y_pos, size_x, size_y, br);
		}
		else {
			x_pos = 30;
			widgetPos(x_pos, y_pos, size_x / 2, 20);
			graphics::drawRect(x_pos, y_pos, size_x, size_y, br);
		}
		br.fill_color[0] = 0.0f;
		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 0.0f;
		graphics::setFont(ASSET_PATH"OpenSans-Light.ttf");
		graphics::drawText((x_pos)-(kind[i].length() / 2) * 5.5, y_pos + 3, 10, kind[i], br);
		size_x1 = size_x;
	}
}

void GenreButton::update()
{
}

std::vector<std::string> GenreButton::getKind()
{
	return kind;
}
