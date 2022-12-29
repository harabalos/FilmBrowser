#pragma once
#include "Button.h"

class GenreButton : public Button {
protected:
	std::string kind;
public:
	GenreButton(std::string kind);
	~GenreButton();
	void widgetSize(float& x, float& y, std::string kind) override;
	void widgetPos(float& x, float& y, float num1, float num2) override;
	void draw(int i) override;
	void update() override;
	std::string getKind();


};