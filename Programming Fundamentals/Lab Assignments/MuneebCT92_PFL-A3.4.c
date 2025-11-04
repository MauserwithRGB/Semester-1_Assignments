#include <stdio.h>
int main(void)  {
int testinteger=3000000000;  //this value is too large for int (its known as integer overflow), which causes the undefined behaviour in the output
printf("Number is: %d", testinteger); 
} 