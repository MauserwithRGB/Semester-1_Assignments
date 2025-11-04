#include <stdio.h>
int main(void) 
  {
    float time, d1, d2, d3, d4, d5, speed;
    printf("INSTRUCTIONS: Time must be between 1-5 hours.\nEnter zero for unused hours.\nDistance is in miles.\nInput cannot be negative.\n");
    printf("\nTime in hours: "); 
    scanf("%f", &time); 
    
    printf("\nDistance travelled in 1st hour: "); 
    scanf("%f", & d1);
    
    printf("\nDistance travelled in 2nd hour: ");
    scanf("%f", &d2); 
    
    printf("\nDistance travelled in 3rd hour: ");
    scanf("%f",&d3);
    
    printf("\nDistance travelled in 4th hour: ");
    scanf("%f", &d4);
    
    printf("\nDistance travelled in 5th hour: ");
    scanf("%f", & d5);
    
    speed = (d1 + d2 + d3 + d4 + d5) / time;
    printf("Average speed in mph: %.3f", speed);
  }