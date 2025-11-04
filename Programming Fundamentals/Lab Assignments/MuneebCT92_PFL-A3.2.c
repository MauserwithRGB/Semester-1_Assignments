#include <stdio.h>
int main(void) 
  {
   float InitialSalary, TaxRate, TaxAmount, FinalSalary;
        printf("Enter Salary: ");
        scanf("%f", &InitialSalary); 
        
        printf("\nEnter Tax rate: "); 
        scanf("%f", &TaxRate); 
        
        TaxAmount = TaxRate * InitialSalary / 100; 
        FinalSalary = InitialSalary - TaxAmount; 
        
        printf("\nSalary after tax: %.3f\nSalary before tax: %.3f\nTax deducted: %.3f\n", FinalSalary, InitialSalary, TaxAmount); 
   return 0;
 } 