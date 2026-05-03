#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* Author: Michael Masterton
*
*  RC Circuit Solver
*-----------------------------------------------------------------------
*  This program computes unknown electrical quantities in an RC circuit
*  using 3 user-provided inputs and standard circuit relationsips.
*
*  The implementation follows a decision-tree structure where the user
*  specifies which variables are known, and the program selects the 
*  appropriate equations to solve the remaining values.
*
*  Purpose;
*   - Demonstrate understanding of RC circuit behavior
*   - Translate physical equations into programing logic
*   - Handle mutliple configurations of known/unkown variables
*
*  Concepts used:
*   - Ohm's law (U = IR)
*   - Time constant (Tau = RC)
*   - Capacitor charge relationship (Q = CV)
*   - Energy Stored in a capacitor (E = 1/2 QU = 1/2 C(U^2))
*   - Power (P= UI)
*
*  Quantities solved:
*   - Voltage (U)
*   - Resistance (R)
*   - Current (I)
*   - Capacitance (C)
*   - Time constant (t)
*   - Charge (Q)
*   - Energy (E)
*   - Power (P)
*
*  Units:
*   - Voltage: Volts (V)
*   - Resistance: Ohms (Omega)
*   - Current: milliAmps (mA)
*   - Capacitance: microFarads (uF)
*   - Time constant: Seconds (s)
*   - Charge: microColoumbs (uC)
*   - Energy: milliJoules (mJ)
*   - Power: Watts (W)
*/

int main(){
    int option1;
    printf("Do you know the Voltage Source Value? (0=N, 1=Y): \n");
    scanf("%d",&option1);
    option1++;
    switch(option1){
        case 1:{
            // R,I,C,t,Q
            int option2;
            printf("Do you know the Resistance Value? (0=N, 1=Y): \n");
            scanf("%d",&option2);
            option2++;
            switch(option2){
                case 1:{
                    // I,C,t,Q
                    int option3;
                    printf("Do you know the Initial Current Value? (0=N, 1=Y): \n");
                    scanf("%d",&option3);
                    option3++;
                    switch(option3){
                        case 1:{
                            // C,t,Q
                            float C;
                            float t;
                            float Q;
                            printf("Please enter the Capacitcance (microFarads): \n");
                            scanf("%f",&C);
                            printf("Please enter the Time constant (seconds): \n");
                            scanf("%f",&t);
                            printf("Please enter the Final charge (microColoumbs): \n");
                            scanf("%f",&Q);
                            float R = (t/C)*(double)pow(10,6);
                            float U = Q/C;
                            float I = (U/R)*1000;
                            float E = (Q*(double)pow(10,-6))*U*500;
                            float P = U*I*(double)pow(10,-3);
                            printf("Your Resistance is %.3f Ohms\n",R);
                            printf("Your Voltage is %.3f Volts\n",U);
                            printf("Your Initial Current is %.3f milliAmps\n", I);
                            printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                            printf("The Max Power that can be delivered is %.3f Watts",P);
                            return 0;

                        }

                        case 2:{
                            // I,C,t,Q
                            int option4;
                            printf("Do you know the Capacitance? (0=N, 1=Y): \n");
                            scanf("%d",&option4);
                            option4++;
                            switch(option4){
                                case 1:{
                                    // I,t,Q
                                    printf("Not enough information to solve\n");
                                    return 0;
                                }

                                case 2:{
                                    // I,C,t,Q
                                    int option5;
                                    printf("Do you know the time constant? (0=N, 1=Y): \n");
                                    scanf("%d",&option5);
                                    option5++;
                                    switch(option5){
                                        case 1:{
                                            // I,C,Q
                                            float I;
                                            float C;
                                            float Q;
                                            printf("Please enter the initial current (milliAmps): \n");
                                            scanf("%f",&I);
                                            printf("Please enter the Capacitance (microFarads): \n");
                                            scanf("%f",&C);
                                            printf("Please enter the Final charge (microColoumbs): \n");
                                            scanf("%f",&Q);
                                            float U = Q/C;
                                            float R = (U/I)*1000;
                                            float t = (R*C)*(double)pow(10,-6);
                                            float E = (Q*(double)pow(10,-6))*U*500;
                                            float P = U*I*(double)pow(10,-3);
                                            printf("Your Voltage is %.3f Volts\n",U);
                                            printf("Your Resistance is %.3f Ohms\n",R);
                                            printf("Your Time constant is %.3f second\n", t);
                                            printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                            printf("The Max Power that can be delivered is %.3f Watts",P);
                                            return 0;

                                        }

                                        case 2:{
                                            // I,C,t
                                            float I;
                                            float C;
                                            float t;
                                            printf("Please enter the initial current (milliAmps): \n");
                                            scanf("%f",&I);
                                            printf("Please enter the Capacitance (microFarads): \n");
                                            scanf("%f",&C);
                                            printf("Please enter the time constant (second): \n");
                                            scanf("%f",&t);
                                            float R = t/(C*(double)pow(10,-6));
                                            float U = (I/1000)*R;
                                            float Q = U*C;
                                            float E = (Q*(double)pow(10,-6))*U*500;
                                            float P = U*I*(double)pow(10,-3);
                                            printf("Your Resistance is %.3f Ohms\n",R);
                                            printf("Your Voltage is %.3f Volts\n",U);
                                            printf("Your Final charge value is %.3f microColoumbs\n", Q);
                                            printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                            printf("The Max Power that can be delivered is %.3f Watts",P);
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                case 2:{
                    // R,I,C,t,Q
                    int option3;
                    printf("Do you know the Initial Current Value? (0=N, 1=Y): \n");
                    scanf("%d",&option3);
                    option3++;
                    switch(option3){
                        case 1:{
                            // R,C,t,Q
                            int option4;
                            printf("Do you know the Capacitance? (0=N, 1=Y): \n");
                            scanf("%d",&option4);
                            option4++;
                            switch(option4){
                                case 1:{
                                    // R,t,Q
                                        float R;
                                        float t;
                                        float Q;
                                        printf("Please enter the Resistance (Ohms): \n");
                                        scanf("%f",&R);
                                        printf("Please enter the time constant (second): \n");
                                        scanf("%f",&t);
                                        printf("Please enter the Final Charge (microColoumbs): \n");
                                        scanf("%f",&Q);
                                        float C = (t/R)*(double)pow(10,6);
                                        float U = Q/C;
                                        float I = (U/R)*1000;
                                        float E = (Q*(double)pow(10,-6))*U*500;
                                        float P = U*I*(double)pow(10,-3);
                                        printf("Your Capacitance is %.3f microFarads\n",C);
                                        printf("Your Voltage is %.3f Volts\n",U);
                                        printf("Your Initial Current is %.3f milliAmps\n", I);
                                        printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                        printf("The Max Power that can be delivered is %.3f Watts",P);
                                        return 0;
                                }

                                case 2:{
                                    // R,C,t,Q
                                        int option5;
                                        printf("Do you know the Time constant? (0=N, 1=Y): \n");
                                        scanf("%d",&option5);
                                        option5++;
                                        switch(option5){
                                            case 1:{
                                                // R,C,Q
                                                float R;
                                                float C;
                                                float Q;
                                                printf("Please enter the Resistance (Ohms): \n");
                                                scanf("%f",&R);
                                                printf("Please enter the Capacitance (microFarads): \n");
                                                scanf("%f",&C);
                                                printf("Please enter the Final Charge (microColoumbs): \n");
                                                scanf("%f",&Q);
                                                float t = (R)*(C*(double)pow(10,-6));
                                                float U = Q/C;
                                                float I = (U/R)*1000;
                                                float E = (Q*(double)pow(10,-6))*U*500;
                                                float P = U*I*(double)pow(10,-3);
                                                printf("Your Time constant is %.3f second\n", t);
                                                printf("Your Voltage is %.3f Volts\n",U);
                                                printf("Your Initial Current is %.3f milliAmps\n",I);
                                                printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                                printf("The Max Power that can be delivered is %.3f Watts",P);
                                                return 0;
                                            }

                                            case 2:{
                                                // R,C,t
                                                printf("Not enough information\n");
                                                return 0;
                                            }
                                        }
                                    
                                }
                            }
                        }

                        case 2:{
                            // R,I,C,t,Q
                            int option4;
                            printf("Do you know the Capacitance? (0=N, 1=Y): \n");
                            scanf("%d",&option4);
                            option4++;
                            switch(option4){
                                case 1:{
                                    // R,I,t,Q
                                    int option5;
                                    printf("Do you know the Time constant? (0=N, 1=Y): \n");
                                    scanf("%d",&option5);
                                    option5++;
                                    switch(option5){
                                        case 1:{
                                            // R,I,Q
                                            float R;
                                            float I;
                                            float Q;
                                            printf("Please enter the Resistance (Ohms): \n");
                                            scanf("%f",&R);
                                            printf("Please enter the Initial Voltage (milliAmps): \n");
                                            scanf("%f",&I);
                                            printf("Please enter the Final charge (microColoumbs): \n");
                                            scanf("%f",&Q);
                                            float U = (I/1000)*R;
                                            float C = Q/U;
                                            float t = R*(C*(double)pow(10,-6));
                                            float E = (Q*(double)pow(10,-6))*U*500;
                                            float P = U*I*(double)pow(10,-3);
                                            printf("Your Voltage is %.3f Volts\n",U);
                                            printf("Your Capicatance is %.3f microFarads\n",C);
                                            printf("Your Time constant is %.3f second\n", t); 
                                            printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                            printf("The Max Power that can be delivered is %.3f Watts",P);
                                            return 0;
                                        }

                                        case 2:{
                                            // R,I,t
                                            float R;
                                            float I;
                                            float t;
                                            printf("Please enter the Resistance (Ohms): \n");
                                            scanf("%f",&R);
                                            printf("Please enter the Initial Voltage (milliAmps): \n");
                                            scanf("%f",&I);
                                            printf("Please enter the Time constant (seconds): \n");
                                            scanf("%f",&t);
                                            float U = (I/1000)*R;
                                            float C = (t/R)*(double)pow(10,6);
                                            float Q = U*C;
                                            float E = (Q*(double)pow(10,-6))*U*500;
                                            float P = U*I*(double)pow(10,-3);
                                            printf("Your Voltage is %.3f Volts\n",U);
                                            printf("Your Capicatance is %.3f microFarads\n",C);
                                            printf("Your Final Charge is %.3f microColoumbs\n", Q); 
                                            printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                            printf("The Max Power that can be delivered is %.3f Watts",P);
                                            return 0;
                                        }
                                    }
                                }

                                case 2:{
                                    // R,I,C
                                    float R;
                                    float I;
                                    float C;
                                    printf("Please enter the Resistance (Ohms): \n");
                                    scanf("%f",&R);
                                    printf("Please enter the Initial Voltage (milliAmps): \n");
                                    scanf("%f",&I);
                                    printf("Please enter the Capacitance (microFarads): \n");
                                    scanf("%f",&C);
                                    float U = (I/1000)*R;
                                    float t = R*(C*(double)pow(10,-6));
                                    float Q = U*C;
                                    float E = (Q*(double)pow(10,-6))*U*500;
                                    float P = U*I*(double)pow(10,-3);
                                    printf("Your Voltage is %.3f Volts\n",U);
                                    printf("Your Time constant is %.3f second\n", t); 
                                    printf("Your Final Charge is %.3f microColoumbs\n",Q);
                                    printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                    printf("The Max Power that can be delivered is %.3f Watts",P);
                                    return 0;
                                }
                            }

                        }
                    }

                }
            }

        }

        case 2:{
            // U,R,I,C,t,Q
            int option2;
            printf("Do you know the Resistance Value? (0=N, 1=Y): \n");
            scanf("%d",&option2);
            option2++;
            switch(option2){
                case 1:{
                    // U,I,C,t,Q
                    int option3;
                    printf("Do you know the Initial Current? (0=N, 1=Y): \n");
                    scanf("%d",&option3);
                    option3++;
                    switch(option3){
                        case 1:{
                            // U,C,t,Q
                            int option4;
                            printf("Do you know the Capacitance? (0=N, 1=Y): \n");
                            scanf("%d",&option4);
                            option4++;
                            switch(option4){
                                case 1:{
                                    // U,t,Q
                                    float U;
                                    float t;
                                    float Q;
                                    printf("Please enter the Voltage Source Value (Volts): \n");
                                    scanf("%f",&U);
                                    printf("Please enter the Time constant (seconds): \n");
                                    scanf("%f",&t);
                                    printf("Please enter the Final Charge (microColoumbs): \n");
                                    scanf("%f",&Q);                                            
                                    float C=Q/U;
                                    float R=t/(C*(double)pow(10,-6));
                                    float I=(U/R)*1000;
                                    float E = (Q*(double)pow(10,-6))*U*500;
                                    float P = U*I*(double)pow(10,-3);
                                    printf("Your Capacitance is %.3f microFarads\n", C); 
                                    printf("Your Resistance is %.3f Ohms\n",R);
                                    printf("Your Initial Current is %.3f milliAmps\n",I);
                                    printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                    printf("The Max Power that can be delivered is %.3f Watts",P);
                                    return 0;

                                }

                                case 2:{
                                    // U,C,t,Q
                                    int option5;
                                    printf("Do you know the Time Constant? (0=N, 1=Y): \n");
                                    scanf("%d",&option5);
                                    option5++;
                                    switch(option5){
                                        case 1:{
                                            // U,C,Q
                                            printf("Not enough information");
                                            return 0;
                                        }

                                        case 2:{
                                            // U,C,t
                                            float U;
                                            float C;
                                            float t;
                                            printf("Please enter the Voltage Source Value (Volts): \n");
                                            scanf("%f",&U);
                                            printf("Please enter the Capacitance (microFarards): \n");
                                            scanf("%f",&C);
                                            printf("Please enter the Time constant (seconds): \n");
                                            scanf("%f",&t);
                                            float Q=U*C;
                                            float R=t/(C*(double)pow(10,-6));
                                            float I=(U/R)*1000;
                                            float E = (Q*(double)pow(10,-6))*U*500;
                                            float P = U*I*(double)pow(10,-3);
                                            printf("Your Final Charge is %.3f microColoumbs\n", Q); 
                                            printf("Your Resistance is %.3f Ohms\n",R);
                                            printf("Your Initial Current is %.3f milliAmps\n",I);
                                            printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                            printf("The Max Power that can be delivered is %.3f Watts",P);
                                            return 0;
                                        }
                                    }

                                }
                            }
                        }

                        case 2:{
                            // U,I,C,t,Q
                            int option4;
                            printf("Do you know the Capacitance? (0=N, 1=Y): \n");
                            scanf("%d",&option4);
                            option4++;
                            switch(option4){
                                case 1:{
                                    // U,I,t,Q
                                    int option5;
                                    printf("Do you know the Time Constant? (0=N, 1=Y): \n");
                                    scanf("%d",&option5);
                                    option5++;
                                    switch(option5){
                                        case 1:{
                                            // U,I,Q
                                            float U;
                                            float I;
                                            float Q;
                                            printf("Please enter the Voltage Source Value (Volts): \n");
                                            scanf("%f",&U);
                                            printf("Please enter the Initial current (milliAmps): \n");
                                            scanf("%f",&I);
                                            printf("Please enter the Final Charge (microColoumbs): \n");
                                            scanf("%f",&Q);
                                            float R=(U/(I*(double)pow(10,-3)));
                                            float C=Q/U;
                                            float t=R*(C*(double)pow(10,-6));
                                            float E = (Q*(double)pow(10,-6))*U*500;
                                            float P = U*I*(double)pow(10,-3);
                                            printf("Your Resistance is %.3f Ohms\n",R);
                                            printf("Your Capacitance is %.3f microFarads\n", C); 
                                            printf("Your Time Constant is %.3f seconds\n",t);
                                            printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                            printf("The Max Power that can be delivered is %.3f Watts",P);
                                            return 0;

                                        }

                                        case 2:{
                                            // U,I,t
                                            float U;
                                            float I;
                                            float t;
                                            printf("Please enter the Voltage Source Value (Volts): \n");
                                            scanf("%f",&U);
                                            printf("Please enter the Initial current (milliAmps): \n");
                                            scanf("%f",&I);
                                            printf("Please enter the Time Constant (seconds): \n");
                                            scanf("%f",&t);
                                            float R=(U/(I*(double)pow(10,-3)));
                                            float C=(t/R)*(double)pow(10,6);
                                            float Q=U*C;
                                            float E = (Q*(double)pow(10,-6))*U*500;
                                            float P = U*I*(double)pow(10,-3);
                                            printf("Your Resistance is %.3f Ohms\n",R);
                                            printf("Your Capacitance is %.3f microFarads\n", C); 
                                            printf("Your Final Charge is %.3f microColoumns\n",Q);
                                            printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                            printf("The Max Power that can be delivered is %.3f Watts",P);
                                            return 0;
                                        }
                                    }
                                }

                                case 2:{
                                    // U,I,C
                                    float U;
                                    float I;
                                    float C;
                                    printf("Please enter the Voltage Source Value (Volts): \n");
                                    scanf("%f",&U);
                                    printf("Please enter the Initial current (milliAmps): \n");
                                    scanf("%f",&I);
                                    printf("Please enter the Capacitance (microFarads): \n");
                                    scanf("%f",&C);
                                    float R=(U/(I*(double)pow(10,-3)));
                                    float Q=U*C;
                                    float t=R*(C*(double)pow(10,-6));
                                    float E = (Q*(double)pow(10,-6))*U*500;
                                    float P = U*I*(double)pow(10,-3);
                                    printf("Your Resistance is %.3f Ohms\n",R);
                                    printf("Your Final Charge is %.3f microColoumns\n",Q);
                                    printf("Your Time Constant is %.3f seconds\n", t); 
                                    printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                    printf("The Max Power that can be delivered is %.3f Watts",P);
                                    return 0;
                                }
                            }
                        }
                    }
                    
                }

                case 2:{
                    // U,R,I,C,t,Q
                    int option3;
                    printf("Do you know the Initial Current? (0=N, 1=Y): \n");
                    scanf("%d",&option3);
                    option3++;
                    switch(option3){
                        case 1:{
                            // U,R,C,t,Q
                            int option4;
                            printf("Do you know the Capacitance? (0=N, 1=Y): \n");
                            scanf("%d",&option4);
                            option4++;
                            switch(option4){
                                case 1:{
                                    // U,R,t,Q
                                    int option5;
                                    printf("Do you know the Time Constant? (0=N, 1=Y): \n");
                                    scanf("%d",&option5);
                                    option5++;
                                    switch(option5){
                                        case 1:{
                                            // U,R,Q
                                                float U;
                                                float R;
                                                float Q;
                                                printf("Please enter the Voltage Source Value (Volts): \n");
                                                scanf("%f",&U);
                                                printf("Please enter the Resistance (Ohms): \n");
                                                scanf("%f",&R);
                                                printf("Please enter the Final Charge (microColoumbs): \n");
                                                scanf("%f",&Q);
                                                float I=(U/R)*1000;
                                                float C= Q/U;
                                                float t=R*(C*(double)pow(10,-6));
                                                float E = (Q*(double)pow(10,-6))*U*500;
                                                float P = U*I*(double)pow(10,-3);
                                                printf("Your Initial current is %.3f milliAmps\n",I);
                                                printf("Your Capacitance is %.3f microFarads\n",C);
                                                printf("Your Time Constant is %.3f seconds\n", t); 
                                                printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                                printf("The Max Power that can be delivered is %.3f Watts",P);
                                                return 0;

                                        }

                                        case 2:{
                                            // U,R,t
                                            float U;
                                            float R;
                                            float t;
                                            printf("Please enter the Voltage Source Value (Volts): \n");
                                            scanf("%f",&U);
                                            printf("Please enter the Resistance (Ohms): \n");
                                            scanf("%f",&R);
                                            printf("Please enter the Time Constant (seconds): \n");
                                            scanf("%f",&t);
                                            float I=(U/R)*1000;
                                            float C=(t/R)*(double)pow(10,6);
                                            float Q=U*C;
                                            float E = (Q*(double)pow(10,-6))*U*500;
                                            float P = U*I*(double)pow(10,-3);
                                            printf("Your Initial current is %.3f milliAmps\n",I);
                                            printf("Your Capacitance is %.3f microFarads\n",C);
                                            printf("Your Final Charge is %.3f microColoumbs\n", Q); 
                                            printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                            printf("The Max Power that can be delivered is %.3f Watts",P);
                                            return 0;
                                            
                                        }
                                    }

                                }

                                case 2:{
                                    // U,R,C
                                    float U;
                                    float R;
                                    float C;
                                    printf("Please enter the Voltage Source Value (Volts): \n");
                                    scanf("%f",&U);
                                    printf("Please enter the Resistance (Ohms): \n");
                                    scanf("%f",&R);
                                    printf("Please enter the Capacitance (microFarads): \n");
                                    scanf("%f",&C);
                                    float t=R*(C*(double)pow(10,-6));
                                    float I=(U/R)*1000;
                                    float Q=U*C;
                                    float E = (Q*(double)pow(10,-6))*U*500;
                                    float P = U*I*(double)pow(10,-3);
                                    printf("Your time constant is %.3f seconds\n",t);
                                    printf("Your Initial current is %.3f milliAmps\n",I);
                                    printf("Your Final Charge is %.3f microColoumbs\n", Q); 
                                    printf("The maximum energy stored in the capacitor is %.3f milliJoules\n",E);
                                    printf("The Max Power that can be delivered is %.3f Watts",P);
                                    return 0;
                                }
                            }
                        }

                        case 2:{
                            // U,R,I
                            printf("Not enough information");
                            return 0;
                        }
                    }
                }
            }

        }
    }

}
