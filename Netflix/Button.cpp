#include "Button.h" 
#include "graphics.h"
#include "config.h"

void Button::update()
{

}

//bool Button::contains(float x, float y)
//{
//	return distance(x, y, x_pos, y_pos)<36*12;
//}

void Button::widgetSize(float& x, float& y, std::string kind)
{
}

void Button::widgetPos(float& x, float& y, float num1, float num2)
{
}

void Button::draw()
{
	/*for (size_t i = 0; i < genre.size(); i++)
	{
		graphics::Brush br;
		br.fill_color[0] = r_color;
		br.fill_color[1] = g_color;
		br.fill_color[2] = b_color;
		br.outline_opacity = 1.0f;
		graphics::drawRect(x_pos + (i * 60), y_pos, 36, 12, br);
		br.fill_color[0] = 0.0f;
		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 0.0f;
		graphics::setFont(ASSET_PATH"OpenSans-Light.ttf");
		graphics::drawText((x_pos - 15)+(i*60), y_pos + 5, 10, genre[i], br);
	}*/
}
