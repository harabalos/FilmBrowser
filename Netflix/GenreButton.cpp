#include "GenreButton.h"
#include "graphics.h"
#include "config.h"
#include <string>

GenreButton::GenreButton(std::string kind)
	:Button{ x_pos =48 , y_pos = 285,size_x = 42, size_y = 16, r_color = 0.65f, g_color = 0.65f, b_color = 0.65f }, kind{ kind } {}

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

void GenreButton::draw(int i)
{
	float h = r_color + m_highlighted;
		graphics::Brush br;
		br.fill_color[0] = h;
		br.fill_color[1] = h;
		br.fill_color[2] = h;
		br.outline_opacity = 1.0f;
		float size_x1 = 0;

		widgetSize(size_x, size_y, kind);
		//if (i > 0) {
		//	widgetPos(x_pos, y_pos, (size_x1 / 2 + 5 + size_x / 2), 0);
		//}
		//else if (i == 0) {
		//	widgetPos(x_pos, y_pos, size_x / 2, 0);
		//}

		graphics::drawRect(x_pos , y_pos, size_x, size_y, br);

		br.fill_color[0] = 0.0f;
		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 0.0f;
		graphics::setFont(ASSET_PATH"OpenSans-Light.ttf");
		graphics::drawText(((x_pos)-(kind.length()/2)*5.5) , y_pos + 3, 10, kind, br);
		size_x1 = size_x;
	
}

std::string GenreButton::getKind()
{
	return kind;
}


bool GenreButton::contains(float x, float y)
{
	return distance(x, y, x_pos, y_pos) < 20;
}

