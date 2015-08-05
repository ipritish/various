#include<stdio.h>
#include<hfcal.h>

void display_calories(float weight , float distance, float coeff)
{ 
   printf("Weight: %3.2f kg\n",weight/4.2);
   printf("Distance: %3.2f km\n",distance*1.61);
   printf("Calories burned: %4.2f cal\n",coeff*weight*distance);
}
