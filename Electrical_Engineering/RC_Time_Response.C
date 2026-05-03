#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* Author: Michael Masterton
*
* RC Time Response Calculator
*----------------------------------------------------------------------
* This program evaluates the time-dependent behavior of an RC circuit
* for both charging and discharing conditions.
*
* Given circuit parameters and a specific time time (t), the program compites:
*   - Charge: Q(t)
*   - Current: I(t)
*   - Capacitor Voltage: U(t)
*   - Energy Stored in the capacitor: E(t)
*   - Instantaneous Power: P(t)
*
* The user selects whether the capacitor is charging or discharging,
* and the program applies the corresponding exponential models:
*
* Charging Equations:
*   Q(t) = Q_final(1-e^(-t/tau))
*   I(t) = I0(e^(-t/tau))
*   U(t) = U_source(1-e^(-t/tau))
*
* Discharging Equations:
*   Q(t) = Q0(e^(-t/tau))
*   I(t) = I0(e^(-t/tau))
*   U(t) = U0(e^(-t/tau))
*
* Additional Calculations:
*   E(t) = (1/2)Q(t)U(t)
*   P(t) = U(t)I(t)
*
* Purpose:
*   - Demonstrate understanding of RC transient response
*   - Apply exponential decay/growth models in code
*   - Model time-dependent electrical behavior
*
* Units:
*   Charge: microColoumbs (uC)
*   Current: milliAmps (mA)
*   Voltage: Volts (V)
*   Time: Seconds (s)
*   Energy: milliJoules (mJ)
*   Power: milliWatts (mW)
*/

int main(){
    int option;
    printf("Are you charging or discharing the Capacitor?\n");
    printf("1) Charging\n");
    printf("2) Discharing\n");
    scanf("%d",&option);
    switch(option){
        case 1:{
            float Q;
            float I;
            float U;
            float t;
            float T;
            printf("Please enter the Final charge (microColoumbs): \n");
            scanf("%f",&Q);
            printf("Please enter the Intial Current (milliAmps): \n");
            scanf("%f",&I);
            printf("Please enter the Voltage Source Value (Volts): \n");
            scanf("%f",&U);
            printf("Please enter the Time constant (Seconds): \n");
            scanf("%f",&t);
            printf("Please enter the Exact point in time (Seconds): \n");
            scanf("%f",&T);
            //Q(t) = Q(1-e^(-T/t))
            float Q1 = Q*(1-(double)exp(-T/t));
            //I(t) = I(e^(-T/t))
            float I1 = I*(double)exp(-T/t);
            //U(t) = U(1-e^(-T/t))
            float U1 = U*(1-(double)exp(-T/t));
            //E = 1/2 Q(t)U(t)
            float E = Q1*(double)pow(10,-6)*U1*500;
            //P = U(t)I(t)
            float P = U1*I1*(double)pow(10,-3);
            printf("The Capacitor contains %.3f microColoumbs of charge at %.3f seconds\n",Q1,T);
            printf("The current in the circuit at %.3f seconds is %.3f milliAmps\n",T,I1);
            printf("The capacitor is holding %.3f Volts at %.3f seconds\n",U1,T);
            printf("The total stored energy in the circuit at %.3f seconds is %.3f milliJoules\n",T,E);
            printf("The Wattage at %.3f seconds is %.3f milliWatts\n",T,P);
            return 0;
        }

        case 2:{
            float Q;
            float I;
            float U;
            float t;
            float T;
            printf("Please enter the Final charge (microColoumbs): \n");
            scanf("%f",&Q);
            printf("Please enter the Intial Current (milliAmps): \n");
            scanf("%f",&I);
            printf("Please enter the Voltage Source Value (Volts): \n");
            scanf("%f",&U);
            printf("Please enter the Time constant (Seconds): \n");
            scanf("%f",&t);
            printf("Please enter the Exact point in time (Seconds): \n");
            scanf("%f",&T);
            //Q(t) = Q(e^(-T/t))
            float Q1 = Q*(double)exp(-T/t);
            //I(t) = I(e^(-T/t))
            float I1 = I*(double)exp(-T/t);
            //U(t) = U(e^(-T/t))
            float U1 = U*(double)exp(-T/t);
            //E = 1/2 Q(t)U(t)
            float E = Q1*(double)pow(10,-6)*U1*500;
            //P = U(t)I(t)
            float P = U1*I1*(double)pow(10,-3);
            printf("The Capacitor contains %.3f microColoumbs of charge at %.3f seconds\n",Q1,T);
            printf("The current in the circuit at %.3f seconds is %.3f milliAmps\n",T,I1);
            printf("The capacitor is holding %.3f Volts at %.3f seconds\n",U1,T);
            printf("The total stored energy in the circuit at %.3f seconds is %.3f milliJoules\n",T,E);
            printf("The Wattage at %.3f seconds is %.3f milliWatts\n",T,P);
            return 0;

        }
    }

}