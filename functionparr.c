#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum response_type {DUMP,SECOND_CHANCE,MARRIAGE};

typedef struct 
{
   char *name;
   enum response_type type;
}response;

void dump(response r)
{
   printf("Dear %s,\n",r.name);
   printf("Unfortunately you are dumped\n");
}

void second_chance(response r)
{
   printf("Dear %s,\n",r.name);
   printf("You are given a second chance\n");
}

void marriage (response r)
{
   printf("Dear %s,\n",r.name);
   printf("You will be married soon.\n");
}

void (*replies[])(response) = {dump,second_chance,marriage};

int main()
{
   response r[] = {{"Mike",DUMP},{"Luis",SECOND_CHANCE},
                  {"Matt",SECOND_CHANCE},{"William",MARRIAGE}};
   int i;
   for (i=0;i<4;i++)
   {
      (replies[r[i].type])(r[i]);
   }
   return 0;
}
