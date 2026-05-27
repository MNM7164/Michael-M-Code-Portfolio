#include <stdio.h>
#include <stdlib.h>
/*
* Author: Michael Masterton
*
*  Hexadecimal Encoder/Decoder
* ----------------------------------------------------------------------------
*   This program converts text into ASCII and hexadecimal representations
*   and can also decode hexadecimal input back into readable English text.
*
*   This implementation demonstrates dynamic memory allocation, manual
*   character processing, and hexadecimal conversion using standard C
*   library functions.
*
*   Purpose:
*   - Demonstrate understanding of ASCII and hexadecimal encoding
*   - Practice dynamic memory management using malloc/realloc
*   - Process variable-length user input safely
*   - Convert between text and hexadecimal formats
*
*   Modes:
*   1) Encrypting
*    - Converts user text into:
*       + ASCII decimal values
*       + Hexadecimal byte valyes
*
*   2) Decrypting
*    - Converts hexadecimal input back into:
*       + ASCII decimal values
*       + Readable English text
*
*   Concepts used:
*    - Dynamic memory allocation (malloc/realloc/free)
*    - Pointer manipulation 
*    - Null-terminated strings
*    - ASCII encoding
*    - Hexadecimal conversion
*    - Character-by-character input handling
*    - strtol() base-16 converstion
*
*   Key features:
*    - Automatically expands memory capacity as needed
*    - Handles variable-length messages
*    - Converts characters to hexadecimal using %02X formatting
*    - Decodes hexadecimal pairs into characters
*
*   Limitations:
*    - Hexadecimal input encryption must not contain spaces
*    - Assumes valid hexadecimal input
*    - does not currently validate malformed hex characters
*
*   Memory handling:
*    - Initial buffer size starts at 8 characters
*    - Capacity doubles automatically when full
*    - Allocated memory is freed before program termination
*
*/

int main(){
    int option;
    printf("Are we encrypting or decrypting Hexadecimal?\n");
    printf("1.) Encrypting\n");
    printf("2.) Decrypting\n");
    scanf("%d",&option);
    // Read newline and exit
    getchar();

    // Declare pointer
    char *buffer = NULL;
    // Pointer initially can hold 8 chars
    int capacity = 8;
    // Pointer has nothing stored to start
    int length = 0;
    int ch;

    // Memory allocation "give me a block that can old 8 characters"
    buffer = (char *)malloc(capacity * sizeof(char));

    // Safety Check
    if(buffer == NULL){
        printf("Mem allocation failed\n");
        return 1;
    }

    printf("Enter message: ");

    // getchar reads character by character and assigns to ch
    // while also checking if loop condition is satisfied or not   
    while((ch=getchar()) != '\n' && ch != EOF){
        // Capacity check (7 chars + null terminator)
        if(length >= capacity -1){
            // double capacity if needed
            capacity *= 2;
            // reallocate
            char *temp = (char *)realloc(buffer, capacity * sizeof(char));
            // Safety check again
            if(buffer == NULL){
                printf("Mem allocation failed\n");
                return 1;
            }
            // Update pointer
            buffer = temp;
        }

        // Store the character
        buffer[length] = ch;
        // Continue
        length++;
        
    }
    // Adds null terminator
    buffer[length] = '\0';
    
    
    switch(option){
        case 1:{
            printf("\nASCII output:\n");
            for(int i =0;i<length;i++){
                printf("%d ", (unsigned char)buffer[i]);
            }
            printf("\nHexadecimal output:\n");
            for (int i =0;i<length;i++){
                printf("%02X ", (unsigned char)buffer[i]);
            }
            printf("\n");
            free(buffer);
            return 0;

        }

        case 2:{
            printf("\nASCII output:\n");
            for (int i =0;i<length;i+=2){
                char byte[3];
                byte[0] = buffer[i];
                byte[1] = buffer[i+1];
                byte[2] = '\0';
                printf("%d ",(unsigned char)strtol(byte,NULL,16));
            }
            printf("\nEnglish output:\n");
            for (int i =0;i<length;i+=2){
                char byte[3];
                byte[0] = buffer[i];
                byte[1] = buffer[i+1];
                byte[2] = '\0';
                printf("%c",(unsigned char)strtol(byte,NULL,16));
            }
            printf("\n");
            free(buffer);
            return 0;
        }
    }
}