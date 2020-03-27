#define _POSIX_C_SOURCE 200809L // <-- needed for getline
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int LARGE_INT = 1000000000;

int main(){
    int list[LARGE_INT][LARGE_INT];
    for(int i = 0; i<LARGE_INT; i++){
        list[i][i] = 0;
    }
    return 0;
}
