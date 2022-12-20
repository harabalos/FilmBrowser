#pragma once
#include "FilmObject.h"

class Adventure : public FilmObject
{
public:
	void update() override;
	void draw() override;
	void init() override;
};