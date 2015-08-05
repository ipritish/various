#include<stdio.h>

void go_south_east(int *lat, int *lon)
{
	*lat = *lat - 1;
	*lon = *lon + 1;
}

int main()
{
	int latitude = 32;
	int longitude = -64;
	printf("Hey we were here [%d,%d]\n",latitude,longitude);
	go_south_east(&latitude,&longitude);
	printf("Now we are here [%d,%d]\n",latitude,longitude);
	return 0;
}
