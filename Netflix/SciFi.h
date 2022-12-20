#pragma once
#include "FilmObject.h"

class SciFi : public FilmObject
{
public:
	void update() override;
	void draw() override;
	void init() override;
};