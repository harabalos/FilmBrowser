#pragma once
#include "FilmObject.h"

class History : public FilmObject
{
public:
	void update() override;
	void draw() override;
	void init() override;
};