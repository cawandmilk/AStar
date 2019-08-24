#pragma once

#include <string.h>

#define FCOST	0
#define GCOST	1
#define HCOST	2
#define Y		3
#define X		4

#define MAX_ELEM_NUMBER 5
#define MAX_DIRECTIONS 8

#define MAX_HEIGHT 50
#define MAX_WIDTH  71

#define VISITED		'#'
#define VISITABLE	'.'
#define INVISITABLE 'o'
#define START		'S'
#define FINISH		'F'

int hCost(int cx, int cy, int ex, int ey);
void getVector(int* px_, int* py_, int dx, int dy);
