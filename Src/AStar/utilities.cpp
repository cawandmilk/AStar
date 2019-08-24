#include "utilities.h"

int hCost(int cx, int cy, int ex, int ey)
{
	int x = cx - ex > 0 ? cx - ex : ex - cx;
	int y = cy - ey > 0 ? cy - ey : ey - cy;
	return x > y ? 14 * y + 10 * (x - y) : 14 * x + 10 * (y - x);
}

void getVector(int* px_, int* py_, int dx, int dy)
{
	/* Suppose that current point is located in origin points,
	 * then we can calculate the related directions indecated
	 * to end point from 1st to 4rd quadrant.
	 */

	 /* the 1st quadrant */
	if (dx < 0 && dy >  0)
	{
		int px[] = { -1, -1, 0, -1, 1, 0, 1, 1 };
		int py[] = { 1, 0, 1, -1, 1, -1, 0, -1 };
		memcpy(px_, &px, sizeof(int) * MAX_DIRECTIONS);
		memcpy(py_, &py, sizeof(int) * MAX_DIRECTIONS);
	}
	else if (dx < 0 && dy == 0)
	{
		int px[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
		int py[] = { 0, -1, 1, -1, 1, -1, 1, 0 };
		memcpy(px_, &px, sizeof(int) * MAX_DIRECTIONS);
		memcpy(py_, &py, sizeof(int) * MAX_DIRECTIONS);
	}
	/* the 2st quadrant */
	else if (dx < 0 && dy < 0)
	{
		int px[] = { -1, -1, 0, -1, 1, 0, 1, 1 };
		int py[] = { -1, 0, -1, 1, -1, 1, 0, 1 };
		memcpy(px_, &px, sizeof(int) * MAX_DIRECTIONS);
		memcpy(py_, &py, sizeof(int) * MAX_DIRECTIONS);
	}
	else if (dx == 0 && dy < 0)
	{
		int px[] = { 0, 1, -1, 1, -1, 0, 1, -1 };
		int py[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
		memcpy(px_, &px, sizeof(int) * MAX_DIRECTIONS);
		memcpy(py_, &py, sizeof(int) * MAX_DIRECTIONS);
	}
	/* the 3nd quadrant */
	else if (dx > 0 && dy < 0)
	{
		int px[] = { 1, 1, 0, 1, -1, 0, -1, -1 };
		int py[] = { -1, 0, -1, 1, -1, 1, 0, 1 };
		memcpy(px_, &px, sizeof(int) * MAX_DIRECTIONS);
		memcpy(py_, &py, sizeof(int) * MAX_DIRECTIONS);
	}
	else if (dx > 0 && dy == 0)
	{
		int px[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
		int py[] = { 0, -1, 1, -1, 1, 0, -1, 1 };
		memcpy(px_, &px, sizeof(int) * MAX_DIRECTIONS);
		memcpy(py_, &py, sizeof(int) * MAX_DIRECTIONS);
	}
	/* the 4rd quadrant */
	else if (dx > 0 && dy > 0)
	{
		int px[] = { 1, 1, 0, 1, -1, 0, -1, -1 };
		int py[] = { 1, 0, 1, -1, 1, -1, 0, -1 };
		memcpy(px_, &px, sizeof(int) * MAX_DIRECTIONS);
		memcpy(py_, &py, sizeof(int) * MAX_DIRECTIONS);
	}
	else if (dx == 0 && dy > 0)
	{
		int px[] = { -1, 1, 0, -1, 1, -1, 1, 0 };
		int py[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
		memcpy(px_, &px, sizeof(int) * MAX_DIRECTIONS);
		memcpy(py_, &py, sizeof(int) * MAX_DIRECTIONS);
	}
}
