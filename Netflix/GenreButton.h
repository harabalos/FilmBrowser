#pragma once
#include "Button.h"

class GenreButton : public Button {
protected:
	std::vector<std::string> kind;
public:
	GenreButton(float x_pos, float y_pos, float size_x, float size_y, float r_color, float g_color, float b_color, std::vector<std::string> kind);
	~GenreButton();
	void widgetSize(float& x, float& y, std::string kind) override;
	void widgetPos(float& x, float& y, float num1, float num2) override;
	void draw() override;
	std::vector<std::string> getKind();
};