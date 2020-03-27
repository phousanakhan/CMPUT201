#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <ctype.h>
#include <stdint.h>

#define N 1024

long long array_a[N] = {0};
float array_b[N] = {0};
double array_c[N] = {0};

int main() {
    long int input_int;
    unsigned long long int tribon();
    float tribon1();
    double tribon2();
    int space_check();


    char input[1024];
    int i;
    int num = 0;
    while(num == 0){
        int error = 0;
        printf("Tribonacci! Type in a positive tribonacci input: \n");
        fgets(input,1024, stdin); 
        input_int = atoi(input);

        for (i = 0; i < (int)strlen(input)-1; i++){
            if (isalpha(input[i]) != 0){ 
                error = 1;
                break;
            }
            else{
                error = 0;
            }
        }
        if ((error == 0) && (input_int>0) && (input_int<=1023)){
            num = 1;
        }

        else if((((int)strlen(input) == 0)) || ((int)strlen(input) == 36))  {
            num = 1;
        }
        
        else{
            printf("Invalid input!\n");
            exit(1);
        }
    }

    printf("16bit Tribonacci %hu\n", (unsigned short)tribon(input_int));
    printf("32bit Tribonacci %u\n", (unsigned int)tribon(input_int));
    printf("64bit Tribonacci %llu\n", (unsigned long long)tribon(input_int));
    printf("Float Tribonacci %e\n", tribon1(input_int));
    printf("Double Tribonacci %e\n", tribon2(input_int));
    return 0;

}
unsigned long long int tribon(int m) {

    if(array_a[m] != 0){
        return(array_a[m]);
    }
    else if (m == 0){
        array_a[m] = 0;
        return array_a[m];
    }
    else if (m == 1){
        array_a[m] = 0;
        return array_a[m];
    }
    else if (m == 2){
        array_a[m] = 1;
        return array_a[m];
    }
    else {
        array_a[m] = (tribon(m-1) + tribon(m-2) + tribon(m-3));
        return array_a[m];
    }
}

float tribon1(int m) {

    if(array_b[m] != 0){
        return (array_b[m]);
    }
    else if (m == 0){
        array_b[m] = 0;
        return array_b[m];
    }
    else if (m == 1){
        array_b[m] = 0;
        return array_b[m];
    }
    else if (m == 2){
        array_b[m] = 1;
        return array_b[m];
    }
    
    else {
        array_b[m] = (tribon1(m-1) + tribon1(m-2) + tribon1(m-3));
        return array_b[m];
    }
}

double tribon2(int m) {

    if(array_c[m] != 0){
        return (array_c[m]);
    }
    else if (m == 0){
        array_c[m] = 0;
        return array_c[m];
    }
    else if (m == 1){
        array_c[m] = 0;
        return array_c[m];
    }
    else if (m == 2){
        array_c[m] = 1;
        return array_c[m];
    }
    else {
        array_c[m] = (tribon2(m-1) + tribon2(m-2) + tribon2(m-3));
        return array_c[m];
    }
}




