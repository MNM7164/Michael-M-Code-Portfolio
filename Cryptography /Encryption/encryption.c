#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*
*Portable Implementation of getline()
*------------------------------------
*Reads an entire line from a stream into a dynamically-allocated buffer.
*- *lineptr will point to the allocated buffer
*- *n is the current buffer size; grows as needed
*- Returns the number of characters read, or -1 on Error/EOF with no Data
*/
ssize_t getline(char **lineptr, size_t *n, FILE *stream){

    //If the buffer hasn't been allocated yet, start with 128 bytes
    if(*lineptr == NULL || *n == 0){
        *n = 128;
        *lineptr = malloc(*n);
        if(!*lineptr){
            return -1; //Memory allocation error
        }
    }

    size_t pos = 0; // Current write position
    int c; // character being read

    //Read characters one by one untile newline or EOF
    while((c=fgetc(stream)) != EOF){

        //If buffer is full, double it's size
        if(pos + 1 >= *n){
            size_t new_size = *n *2;
            char *new_ptr = realloc(*lineptr, new_size);
            if(!new_ptr){
                return -1;
            }
            *lineptr = new_ptr;
            *n = new_size;
        }

        (*lineptr)[pos++] = c; // Store the character

        if(c=='\n'){
            break; //Stop reading at newline
        }
    }

    // If nothing was read and stream ended, return Error
    if(pos == 0 && c == EOF){
        return -1;
    }

    (*lineptr)[pos] = '\0'; // Null-terminate the string
    return pos; // Return number of characters read
}

/*
*Function prototypes for: shift cipher, affine cipher, subsitution cipher, and hill cipher
*/
void choice(const char *input);
void shiftCipher(const char *str, int s);
void affineCipher(const char *str,int m, int s);
void substitutionCipher(const char *str, const char mapping[26]);
void hillCipher(const char *str, int **key, int n);

int main(){
    char *input = NULL; // Pointer for getline() to allocate
    size_t size = 0; // Inital buffer size (0 means getline allocates)
    
    printf("Enter your message: ");
    ssize_t len = getline(&input,&size,stdin);

    if(len == -1){
        printf("Error Getline Failed");
        return 1;
    }

    choice(input);

    free(input);
    return 0;
}

void choice(const char *input){
    int option;

    printf("Choose your encryption method:\n");
    printf("1) Shift Cipher\n");
    printf("2) Affine Cipher\n");
    printf("3) Substitution Cipher\n");
    printf("4) Hill Cipher\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    // Clear leftover newline
    int c;
    while((c=getchar()) != '\n' && c != EOF);

    switch(option){
        case 1:{
            int s;
            printf("Enter your shift: ");
            scanf("%d",&s);
            while((c=getchar()) != '\n' && c != EOF);
            shiftCipher(input, s);
            break;}
        case 2:{
            int m, s;
            printf("Enter your multiplier: ");
            scanf("%d", &m);
            while((c=getchar()) != '\n' && c != EOF);
            printf("Enter your shift: ");
            scanf("%d",&s);
            while((c=getchar()) != '\n' && c != EOF);
            affineCipher(input,m,s);
            break;}
        case 3:{
            char mapping[26];
            printf("Enter your custom mapping (A->?):\n");
            for(int i = 0;i<26;i++){
                char buf[10];
                scanf("%s",buf);
                mapping[i] = toupper(buf[0]);
            }
            int c;
            while((c=getchar()) !='\n' && c != EOF);
            substitutionCipher(input,mapping);
            break;
        }
        case 4:{
            int n;
            printf("Enter Matrix dimension n: ");
            scanf("%d",&n);

            int **matrix = malloc(n*sizeof(int *));
            for(int i =0;i<n;i++){
                matrix[i] = malloc(n*sizeof(int));
            }
            printf("Enter your %dx%d key matrix row by row with spaces between each value:\n",n,n);
            for(int j=0;j<n;j++){
                for(int i =0;i<n;i++){
                    scanf("%d",&matrix[i][j]);
                }
            }
            int let_count = 0;
            for(int i = 0;input[i] != '\0';i++){
                if(isalpha((unsigned char)input[i])){
                    let_count++;
                }
            }
            if(let_count % n != 0){
                printf("Error: message size not correct, please pad the message by %d letter(s)",let_count%n);
            }else{
                hillCipher(input,matrix,n);
            }
            for(int i =0;i<n;i++){
                free(matrix[i]);
            }
            free(matrix);
            break;
        }
        default:{
            printf("Invalid Choice\n");
        }
    }


}

void shiftCipher(const char *str, int s){
    for(int i = 0; str[i] != '\0';i++){
        char c = str[i];

        if(c== ' '){
            // Preserve exact spacing; printing two spaces keeps nice alignment
            printf("  ");
        }else{
            char up = toupper((unsigned char)c); // Capitalizes

            // Check if characters are A/a-Z/z
            if(up>='A' && up <= 'Z'){
                int num = (up - 'A' + s) % 26; // Converts to 0-25
                char enc = num + 'A';
                printf("%c",enc);
            }else{
                // Preserve non-letters
                printf("%c ",c);
            }
        }
    }
    printf("\n");   
}

void affineCipher(const char *str,int m, int s){
    if(m > 1 && 26%m == 0){
        printf("Invalid multiplier");
    }else if(m == 0){
        printf("Why are you multiplying by 0?");
    }else{
        for(int i = 0; str[i] != '\0';i++){
            char c = str[i];

            if(c== ' '){
                // Preserve exact spacing; printing two spaces keeps nice alignment
                printf("  ");
            }else{
                char up = toupper((unsigned char)c); // Capitalizes

                // Check if characters are A/a-Z/z
                if(up>='A' && up <= 'Z'){
                    int num = (m*(up - 'A') + s) % 26; // Converts to 0-25
                    char enc = num + 'A';
                    printf("%c",enc);
                }else{
                    // Preserve non-letters
                    printf("%c ",c);
                }
            }
            
        }
    }
    printf("\n");   
}

void substitutionCipher(const char *str, const char mapping[26]){
    for(int i =0;str[i] !='\0';i++){
        char c = str[i];

        if(c== ' '){
            printf(" ");
        }else{
            char up = toupper((unsigned char)c);

            if(up >= 'A' && up <= 'Z'){
                int index = up - 'A';
                char mapped = mapping[index];
                printf("%c",mapped);
            }else{
                printf("%c",c);
            }
        }
    }
    printf("\n");
}

void hillCipher(const char *str, int **key, int n){
    int let_count = 0;
    for(int i = 0;str[i] != '\0';i++){
        if(isalpha((unsigned char)str[i])){
            let_count++;
        }
    }

    int *let = malloc(let_count * sizeof(int));
    int idx = 0;

    for(int i = 0; str[i] != '\0';i++){
        if(isalpha((unsigned char)str[i])){
            let[idx++] = toupper(str[i])-'A';
        }
    }

    for(int i =0; i<let_count;i+=n){
        int result[10] = {0};
        for(int row = 0; row<n;row++){
            int sum = 0;
            for(int col = 0; col <n; col++){
                sum += key[row][col] * let[i + col];
            }
            result[row] = sum % 26;
        }
        int printed = 0;
        for(int j=i;printed < n; j++){
            while(str[j] && !isalpha((unsigned char)str[j])){
                printf("%c",str[j++]);
            }
            printf("%c",result[printed++] + 'A');
        }
    }
    printf("\n");
    free(let);
}