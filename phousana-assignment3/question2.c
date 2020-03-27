#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <ctype.h>
#include <stdint.h>

#define size 26
long long int alpha_array[size][2] = {{0}};

int main() {
    int scanner();
    int scanner_count();
    int i;
    int j;
    int alphabet = 97;
    int int_alpha;
    int count_var;
    int diff;
    printf("Welcome to variable counter! Please record your counts! Type X to end.\n");
    
    for (i = 0; i<26; i++){
        alpha_array[i][0] = alphabet + i;
        alpha_array[i][1] = alphabet + i;
    }

    do{
        int_alpha = scanner();
        if (int_alpha != -1){
            count_var = scanner_count();
        }
        if ((int_alpha == -1) || (count_var == -1)){
            for (j = 0; j<26; j++){
                if (alpha_array[j][1] - alpha_array[j][0] != 0){
                    diff = alpha_array[j][1] - alpha_array[j][0];
                    printf("%c - %i\n",(int)alpha_array[j][0], diff);
                }
            }
            break;
        }
        for (j = 0; j<26; j++){
            if (alpha_array[j][0] == int_alpha){
                alpha_array[j][1] = alpha_array[j][1] + count_var;
            }
        }
    }while(int_alpha != -1);
    
    return 0;
}

int scanner(){
    char char_alpha1;
    printf("Input character variable a-z: \n");
    scanf(" %c", &char_alpha1);
    if (char_alpha1 == 'X'){
        return -1;
    }
    else{
        return((int)char_alpha1);
    }
}

int scanner_count() {
    int int_alpha1;
    printf("Input count variable a-z: \n");
    if (scanf(" %i", &int_alpha1) == 0){
        return -1;
    }
    else{
        return(int_alpha1);
    }
}

