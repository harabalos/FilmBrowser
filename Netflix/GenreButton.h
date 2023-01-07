#pragma once
#include "Button.h"

class GenreButton : public Button {
protected:
	std::string kind;
public:
	GenreButton(std::string kind);
	GenreButton(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color, std::string kind);
	~GenreButton() {};
	void draw() override;
	void update() override;
	std::string getKind();

};