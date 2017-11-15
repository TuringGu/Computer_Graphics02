#pragma once

#include "stdafx.h"

// swap the value of the two (int)
inline void swap_value_int(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}