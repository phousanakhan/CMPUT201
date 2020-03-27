#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int CONST_P = 1024;
const int MAX_ROUNDS = 32000;
const int MAX_ROW = 16000;
const int MAX_COL = 16000;
const int TEN = 10;

int main(){
    void get_input();
    get_input();
    return 0;
}
void check_round(int round){
    if(round>MAX_ROUNDS){
        printf("Invalid input!\n");
	    exit(1);
    }
}
void check_row(int row){
    if(row>MAX_ROW){
        printf("Invalid input!\n");
	    exit(1);
    }
}
void check_col(int col){
    if(col>MAX_COL){
        printf("Invalid input!\n");
	    exit(1);
    }
}
void get_input(){
    void modify_val(int Rounds, int Rows, int Cols, int array[Rows][Cols], int array0[Rows][Cols]);
    int Rounds;
    int Rows;
    int Cols;
    char buffer[CONST_P];
    if (fgets(buffer, CONST_P, stdin) == NULL){
	    printf("Invalid input!\n");
        exit(1);
    }
    if (sscanf(buffer, "%i",&Rounds) != 1){
        printf("Invalid input!\n");
        exit(1);
    }
    if (fgets(buffer, CONST_P, stdin) == NULL){
	printf("Invalid input!\n");
        exit(1);
    }
    if (sscanf(buffer, "%i %i",&Rows, &Cols) != 2){
        printf("Invalid input!\n");
        exit(1);
    }
    check_round(Rounds);
    check_row(Rows);
    check_col(Cols);

    int read_current; 
    int array[Rows][Cols];
    int array0[Rows][Cols];
    for(int i=0; i < Rows; i++){
        if (fgets(buffer, CONST_P, stdin) == NULL){
            printf("Invalid input!\n");
            exit(1);
        }
        int read = 0;  //Credit user M Oehm on SO. Help resolve sscanf starting point. Refer to 1st link on README.
        for(int j=0; j <Cols; j++){
            int result1 = sscanf(buffer+read, "%i%n", &array[i][j], &read_current);
            if (result1 != 1){
                printf("Invalid input!\n");
                exit(1);
            }
            read += read_current;
            array0[i][j] = array[i][j];
        }
    }
    modify_val(Rounds, Rows, Cols, array, array0);
}
void modify_val(int Rounds, int Rows,int Cols, int(*array)[Cols], int(*array0)[Cols]){
    int top = 0;
    int bottom = 0;
    int left = 0;
    int right = 0;
    int array_f;
    int round = 0;
    printf("%i\n",Rounds);
    printf("%i %i\n",Rows, Cols);
    for (int i=0; i < Rows; i++){
        for (int j=0; j< Cols; j++){
            printf("%i ", array[i][j]);
        }
        printf("\n");
    }
    while (round < Rounds){
        round += 1;
        for(int k=0; k < Rows; k++){
            for(int m=0; m <Cols; m++){
                array0[k][m] = array[k][m];
            }
        }
        for (int i=0; i < Rows; i++){
            for (int j=0; j< Cols; j++){
                array_f = array0[i][j];
                top = array0[i-1][j];
                bottom = array0[i+1][j];
                left = array0[i][j-1];
                right = array0[i][j+1];
                if ( (i==0) && (j==0) ){
                    array[i][j] =(array_f +  right + bottom) % TEN;
                }
                else if ( (i==0) && (j!= Cols-1) &&(j>0) ){
                    array[i][j] =(array_f + left + right + bottom) % TEN;
                }
                else if ( (i==0) && (j==Cols-1) ){
                    array[i][j] =(array_f + left + bottom) % TEN;
                }
                else if ( (i>0) && (i != Rows-1) && (j == 0) ){
                    array[i][j] =(array_f + top + bottom + right) % TEN;
                }
                else if ( (i==Rows-1) && (j==0) ){
                    array[i][j] =(array_f + top + right) % TEN;
                }
                else if ( (i==Rows-1) && (j!=Cols-1) && (j>0) ){
                    array[i][j] =(array_f + left + right + top) % TEN;
                }
                else if ( (i==Rows-1) && (j==Cols-1) ){
                    array[i][j] =(array_f + top + left) % TEN;
                }
                else if ( (i>0) && (i!=Rows-1) && (j==Cols-1)){
                    array[i][j] =  (array_f + top + bottom + left) % TEN;
                }
                else{
                    array[i][j] = (array_f + top + bottom + left + right) % TEN;

                }
            }
        }
        printf("Round %i!\n", round);
        for (int i=0; i < Rows; i++){
            for (int j=0; j< Cols; j++){
                printf("%i ", array[i][j]);
            }
            printf("\n");
        }
    }
} 
