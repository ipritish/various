#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char a[] = "You look Great!";
	char *p;
	printf("%s\n",a);
	p = a;
	printf("address : %p\n",p);
	printf("%s\n",p);
	p = p+2;
	*p = 'p';
	printf("%s\n",a);
	return 0;
}
