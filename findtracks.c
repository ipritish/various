#include<stdio.h>
#include<string.h>

char tracks[][80] = {
	"I left my heart in Harvard Medical School",
	"Newark, Newark - a wonderful town",
	"Dancing with the dork",
	"From here to maternity",
	"The girl from Iwo Jima",
	"Sadi Gali",
};

void find_track(char search_for[])
{
	int i;
	for (i=0;i<6;i++)
	{
		if(strstr(tracks[i],search_for))
			{
				int j = i + 1;
				printf("Track %i: '%s'\n",j,tracks[i]);
			}
	}
}

int main()
{
	char search_for[80];
	printf("Search for :");
	fgets(search_for,80,stdin);
	search_for[strlen(search_for) - 1] = '\0';
	find_track(search_for);
	return 0;
}
