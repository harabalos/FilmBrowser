#pragma once


class FilmObject
{
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
};