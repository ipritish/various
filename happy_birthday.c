#include<stdio.h>

typedef struct{
   const char *name;
   const char *species;
   int age;
}turtle;

void happy_birthday(turtle *t)
{
   t->age = t->age + 1;
   printf("Happy Birthday %s You are now %i years old\n",t->name,t->age);
}

int main()
{
   turtle my_turtle = {"MyTurtle","LeatheBack Turtles",99};
   happy_birthday(&my_turtle);
   printf("%s's age is now %i\n",my_turtle.name,my_turtle.age);
   return 0;
}


