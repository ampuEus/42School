#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	//TEST 1
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010101",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {16, 0};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	// TEST 2
	t_point begin1 = {0, 0};
	flood_fill(area, size, begin1);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	// TEST 3
	char**  area2 = make_area(zone, size);

	t_point begin2 = {1, 1};
	flood_fill(area2, size, begin2);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area2[i]);
	printf("\n");

	// TEST 4
	char**  area3 = make_area(zone, size);

	t_point begin3 = {5, 1};
	flood_fill(area3, size, begin3);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area3[i]);
	printf("\n");


	return (0);
}
