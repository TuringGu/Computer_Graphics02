#pragma once

#include "stdafx.h"

inline void Cirpot_eight_part(int x0, int y0, int x, int y, int color)
{
	putpixel((x0 + x), (y0 + y), color);
	putpixel((x0 + y), (y0 + x), color);
	putpixel((x0 + y), (y0 - x), color);
	putpixel((x0 + x), (y0 - y), color);
	putpixel((x0 - x), (y0 - y), color);
	putpixel((x0 - y), (y0 - x), color);
	putpixel((x0 - y), (y0 + x), color);
	putpixel((x0 - x), (y0 + y), color);
}