#pragma once

#define ASSET_PATH "assets\\"
#define WINDOW_WIDTH 1300
#define WINDOW_HEIGHT 650
#define CANVAS_WIDTH 1000
#define CANVAS_HEIGHT 500

inline float distance(float x1, float y1, float x2, float y2)
{
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx + dy * dy);
}