#pragma once
#include "FilmObject.h"

class Crime : public FilmObject
{
public:
	void update() override;
	void draw() override;
	void init() override;
};