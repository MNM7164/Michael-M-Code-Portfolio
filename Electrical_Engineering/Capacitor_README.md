# **Interactive RC Circuit Solver (C)**
## Overview
This project is a command-line C program that models an RC (Resistor-Capacitor) circuit and computes unknown electrical quantities based on 3 user inputs.

The goal of this project is to demonstrate the ability to:
* Translate circuit theory into program logic
* Work with interdependent physical equations
* Handle multiple known/unkown variable configurations

## What it demonstrates
This program reflects a working understanding of:
* Ohm's law
* RC time constant behavior
* Charge, Current, and Voltage relationships in Capacitors
* Energy storage in electric fields
* Power Calculations in circuits

It also demonstrates building a decision-based computational system where different sets of known variables lead to different solution paths.

## Funcationality
The program interactively asks whether the user knows certain values:
1. Voltage (U)
2. Resistance (R)
3. Initial Current (I)
4. Capacitance (C)
5. Time constant ($\tau$)
6. Charge (Q)

Based on the responses, it computes the remaining unknowns including:
1. Voltage
2. Resistance
3. Initial Current
4. Capacitance
5. Time constant
6. Final Charge of the Capacitor
7. Maximum Energy Stored in the Capacitor
8. Maximum Power

## _Key Equations used_:
* $U = IR$
* $\tau = RC$
* $Q = UC$
* $E = \frac{1}{2} QU = \frac{1}{2} CU^2$
* $P = UI$

## _Units_
* Voltage: Volts
* Resistance: Ohms
* Current: milliAmps
* Capacitance: microFarads
* Time constant: Seconds
* Charge: microColoumbs
* Energy: milliJooules
* Power: Watts

## Related Work:
Additional companion programs (not inlcuded here) explore:
+ Parallel Resistance Calculations
+ Time-Dependent RC Behavior:
+ + $Q(t)$
  + $I(t)$
  + $U(t)$
