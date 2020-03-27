#define _POSIX_C_SOURCE 200809L // <-- needed for getline
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const long long int BIG_NUMB = 99999999999999999;

int main(){
    char *ptr = malloc(sizeof(char));
    for(int i = 0; i<BIG_NUMB; i++){
        ptr[i] = 'a';
    }
    return 0;
}

