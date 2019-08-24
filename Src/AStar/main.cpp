#include "stdafx.h"

int main(void)
{
	FILE* originalMap;	fopen_s(&originalMap, "map.txt", "rt");
	FILE* recordedMap;	fopen_s(&recordedMap, "output.txt", "wt");
	char map[MAX_HEIGHT][MAX_WIDTH];	memset(map, INVISITABLE, sizeof(map));

	/* Load the map */
	{
		int col = 0;
		while (fgets(&map[++col][1], MAX_WIDTH, originalMap))
		{
			char* c = &map[col][strlen(&map[col][1])];
			if (*c == '\n')* c = INVISITABLE;
			if (*(c + 1) == '\0')* (c + 1) = INVISITABLE;
		}
	}

	int isVisited[MAX_HEIGHT][MAX_WIDTH] = { 0, };

	int parentX[MAX_HEIGHT][MAX_WIDTH] = { 0, };		// save parent x
	int parentY[MAX_HEIGHT][MAX_WIDTH] = { 0, };		// save parent y
	
	int sx, sy, ex, ey;

	/* record to isVisited[][] list */
	for (int i = 0; i < MAX_HEIGHT; i++)
	{
		for (int j = 0; j < MAX_WIDTH; j++)
		{
			if		(map[i][j] == INVISITABLE	) { isVisited[i][j] = 1; }
			else if (map[i][j] == START			) { sx = j; sy = i; }
			else if (map[i][j] == FINISH		) { ex = j; ey = i; }
		}
	}

	/* Declare the priority queue */
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	init(q);

	/* push start point */
	{
		int cx = sx;
		int cy = sy;
		int g = 0;
		int h = hCost(cx, cy, ex, ey);
		int f = g + h;

		ELEMTYPE start_data[MAX_ELEM_NUMBER] = { f, g, h, cy, cx };
		push(q, start_data);
	}

	while (!isEmpty(q))
	{
		ELEMTYPE current[MAX_ELEM_NUMBER] = { 0, };
		pop(q, current);

		if (isVisited[current[Y]][current[X]]) continue;
		else isVisited[current[Y]][current[X]] = 1;

		if (current[X] == ex && current[Y] == ey) break;

		/* Calculate priority subordinated by 8 directions */
		int px[MAX_DIRECTIONS] = { 0, };
		int py[MAX_DIRECTIONS] = { 0, };
		getVector(px, py, current[X] - ex, current[Y] - ey);	

		for (int i = 0; i < MAX_DIRECTIONS; i++)
		{
			int cx = current[X] + px[i];
			int cy = current[Y] + py[i];

			if (isVisited[cy][cx])			continue;	// already visited
			if (map[cy][cx] == INVISITABLE) continue;	// wall

			int g = current[GCOST] + (px[i] && py[i] ? 14 : 10);
			int h = hCost(cx, cy, ex, ey);
			int f = g + h;

			ELEMTYPE neighbor[] = { f, g, h, cy, cx };

			/* if (cx, cy) is already in queue, calculate the f cost and compare it */
			if (!getFCostInQueue(q, cx, cy) || neighbor[FCOST] < getFCostInQueue(q, cx, cy))
			{
				push(q, neighbor);
				parentX[cy][cx] = current[X];
				parentY[cy][cx] = current[Y];
			}
		}
	}

	/* output */
	{
		/* record the path from end point */
		int cx = parentX[ey][ex];
		int cy = parentY[ey][ex];
		while (!(cx == sx && cy == sy))
		{
			map[cy][cx] = VISITED;

			int tmp = cx;
			cx = parentX[cy][cx];
			cy = parentY[cy][tmp];
		}

		/* print the map */
		for (int col = 1; col < MAX_HEIGHT - 1; col++)
		{
			for (int row = 1; row < MAX_WIDTH - 1; row++)
			{
				fprintf(recordedMap, "%c", map[col][row]);
			}
			fprintf(recordedMap, "\n");
		}
	}
	
	putQueue(q);
	fclose(originalMap);
	fclose(recordedMap);
	return 0;
}
