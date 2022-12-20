#pragma once
#include "FilmObject.h"

class Fantasy : public FilmObject
{
public:
	void update() override;
	void draw() override;
	void init() override;
};