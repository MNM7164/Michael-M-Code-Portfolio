# *RC Time Response Calculator (C)*
## *Overview*
This program computes the time dependent behavior of an RC (Resistor-Capacitor) circuit during both *charging* and *discharging*.

Given intital conditions and a specific time; the program evaluates:
- Charge: $Q(t)$
- Current: $I(t)$
- Capacitor Voltage: $U(t)$
- Energy Stored: $E(t)$
- Instanteous Power: $P(t)$

## *What is demonstrates*
This project demonstrates:
- Understanding of transient response in RC circuits
- Use of exponential decay and growth models
- Translation of time-dependent equations into code
- Handling of both *charging* and *discharging* cases

## *Model Description*
The user selects whether the capacitor is:
1. Charging
2. Discharging

The program then computes values at a specified time using standard RC equations.

## _Equations Used_
### Charging
$$Q(t) = Q_{final}(1-e^{-t/\tau})$$
$$I(t) = I_0(e^{-t/\tau})$$
$$U(t) = U_{source}(1-e^{-t/\tau})$$

### Discharging
$$Q(t) = Q_0(e^{-t/\tau})$$
$$I(t) = I_0(e^{-t/\tau})$$
$$U(t) = U_0(e^{-t/\tau})$$

### Energy and Power
$$E(t) = \frac{1}{2}Q(t)U(t)$$
$$P(t) = U(t)I(t)$$

## _Units_
* Charge: microColoumbs (uC)
* Current: milliAmps (mA)
* Voltage: Volts (V)
* Time: Seconds (s)
* Energy: milliJoules (mJ)
* Power: milliWatts (mW)
