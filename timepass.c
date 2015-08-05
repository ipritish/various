#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int count,lcm,hcf,number,sqrt_number;
    int is_it_prime = 1;
    printf("Prime Checker, Give Number:\n");
    scanf("%d",&number);
    sqrt_number = sqrt(number);
    
    if (number < 2)
    {
        is_it_prime = 0;
    }
    else if (number % 2 == 0)
    {
        is_it_prime = 0;
    }
    //printf("square_root number : %d\n",sqrt_number);
    else
    {
        for (count = 2 ; count <= sqrt_number ; count ++)
        {
            if ((number % count) == 0)
            {
                is_it_prime = 0;
                break;
            }
            
        }
        
    }
    printf("square_root number : %d\n",sqrt_number);
    if (is_it_prime)
        printf("Prime\n");    
    else
        printf("Not Prime\n");
    return 0; 
}
