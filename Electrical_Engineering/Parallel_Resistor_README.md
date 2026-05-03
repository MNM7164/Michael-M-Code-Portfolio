# *Parallel Resitor Calculator (C)*
## *Overview*
This is a simple interactive C program that calculates the equivalent resistance of resistors connected in parallel.

The program prompts the user to input the number of resistors in parallal and their individual resistance values, then computes the total equivalent resistance.

## *What it demonstrates*
The project demonstrates:
* Understanding of parallel resitor behavior
* Implementation of summation-based formulas
* Basic user input handling in C
* Translation of electrical engineering concepts into code

## _Formulas Used_
For resistors in parallel:

$$
\frac{1}{R_{eq}} = \sum_{i=1}^{n}\frac{1}{R_i}
$$

The program computes the reciprocal sum then inverts it to find the equivalent resistance.
