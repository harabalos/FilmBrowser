#pragma once
#include "FilmObject.h"

class Drama : public FilmObject
{
public:
	void update() override;
	void draw() override;
	void init() override;
};