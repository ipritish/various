#include<stdio.h>

int linearSearch (int a[], int n, int x)
{
	int old_value;
	int found = 1;
	int not_found = 0;
	int i = 0;
	old_value = a[n-1];
	a[n-1] = x;
	while (a[i] != x)
	{
		i++;
	}
	a[n-1] = old_value;
	if (i<n-1 || a[n-1] == x)
	{
		return found;		
	}
	else
	{
		return not_found;
	}
}

int main()
{
	int a[5] = {1,2,3,4,5};
	int check = linearSearch(a,5,6); 
	if (check)
		printf("found");
	else 
		printf("not_found");

}
