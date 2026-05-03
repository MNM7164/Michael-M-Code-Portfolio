#include <stdio.h>
#include <stdlib.h>

/*
* Author: Michael Masterton
*
* Parallel Resistor Calculator
*------------------------------------------
* This program computes equivalent resistance of 
* multiple resistors connected in parallel.
*
* The user specifies the number of resistors and 
* inputs their individual resistance values. The
* program applies the standard parallel resistance
* formula 
* 1/R_eq = sum(1/R_i) 
* and then computes 
* R_eq = 1/R_eq
*
* Purpose:
* - Demonstrate understanding of parallel resistors
* - Implement summation-based electrical relationships in code
* - Provide a simple interactive calculation tool
*/

int main(){
    int i;
    printf("Enter number of parallel resistors: ");
    scanf("%d",&i);
    float R=0.0;
    float EqR = 0.0;
    for(int j=0;j<i;j++){
        printf("Enter resistance value: ");
        scanf("%f",&R);
        EqR += (1.0/R);
    }
    float REq = (1.0/EqR);
    printf("The equivalent resistance is: %f", REq);
    return 0;
}