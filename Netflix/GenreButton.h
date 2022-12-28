#pragma once
#include "Button.h"

class GenreButton : public Button {
protected:
	std::string kind;
	bool m_highlighted = false;
	bool m_active = false;
public:
	GenreButton(std::string kind);
	~GenreButton();
	void widgetSize(float& x, float& y, std::string kind) override;
	void widgetPos(float& x, float& y, float num1, float num2) override;
	void draw(int i) override;
	std::string getKind();
	bool contains(float x, float y);
	void setHighlight(bool h) { m_highlighted = h; };
	void setActive(bool a) { m_active = a; };
	void setX(float x) { x_pos = x; };
	void setY(float y) { y_pos = y; };

};