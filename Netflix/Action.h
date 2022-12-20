#pragma once
#include "FilmObject.h"

class Action : public FilmObject
{
public:
	void update() override;
	void draw() override;
	void init() override;
};