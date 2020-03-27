#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int CONST_P = 4000;
const int MAX_ROUNDS = 32000;
const int MAX_ROW = 16000;
const int MAX_COL = 16000;
const int TEN = 10;

void modify_val(char CharP, int Int2, int Rows, int Cols, int **array, int **array0);
int check_top(const int *a0_top, const int *a0_Bval);
int check_bottom(const int *a0_bottom, const int *a0_Bval);
int check_left(const int *a0_left, const int *a0_Bval);
int check_right(const int *a0_right, const int *a0_Bval);
void FreeArray(int **array, int **array0, int Rows);
void arrayMalloc(int **array, int Rows, int Cols);
void array0Malloc(int **array0, int Rows, int Cols);
void invalidResult1(int result1);

int main(){
    void get_input();
    get_input();
    return 0;
}
void check_P2(const char *CharP, int Int2){
    if(*CharP != 'P'){
        printf("Invalid input!\n");
	    exit(1);       
    }
    if(Int2 != 2){
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
void check_10(int Int10){
    if(Int10 != TEN){
        printf("Invalid input!\n");
	    exit(1);
    }
}
void get_P2(char *CharP, int *Int2){
    char buffer1[CONST_P];
    if (fgets(buffer1, CONST_P, stdin) == NULL){
	    printf("Invalid input!\n");
        exit(1);
    }
    if (sscanf(buffer1, "%c%i",CharP, Int2) != 2){
        printf("Invalid input!\n");
        exit(1);
    }
}
void get_RowCol(int *Rows, int *Cols){
    char buffer1[CONST_P];
    if (fgets(buffer1, CONST_P, stdin) == NULL){
	printf("Invalid input!\n");
        exit(1);
    }
    if (sscanf(buffer1, "%i %i",Cols, Rows) != 2){
        printf("Invalid input!\n");
        exit(1);
    }
}
void get_10(int *Int10){
    char buffer1[CONST_P];
    if (fgets(buffer1, CONST_P, stdin) == NULL){
	printf("Invalid input!\n");
        exit(1);
    }
    if (sscanf(buffer1, "%i",Int10) != 1){
        printf("Invalid input!\n");
        exit(1);
    }
}
void arrayMalloc(int **array, int Rows, int Cols){
    for(int i=0; i<Rows+1; i++){
        array[i] = malloc(sizeof(int) * (Cols+1));
    }
}
void array0Malloc(int **array0, int Rows, int Cols){
    for(int i=0; i<Rows+1; i++){
        array0[i] = malloc(sizeof(int) * (Cols+1));
    }
}
void invalidResult1(int result1){
    if (result1 != 1){
        printf("Invalid input!\n");
        exit(1);
    }
}
void get_input(){
    char CharP;
    int Int2;
    int Int10;
    int Rows;
    int Cols;
    char buffer[CONST_P];
    get_P2(&CharP, &Int2);
    get_RowCol(&Rows, &Cols);
    get_10(&Int10);
    check_P2(&CharP, Int2);
    check_row(Rows);
    check_col(Cols);
    check_10(Int10);

    int **array = (int**)malloc(sizeof(int*)*(Cols+1)*(Rows+1));
    arrayMalloc(array, Rows, Cols);
    int **array0 = (int**)malloc(sizeof(int*)*(Cols+1)*(Rows+1));
    array0Malloc(array0, Rows, Cols);

    int read_current; 
    for(int i=0; i < Rows; i++){
        if (fgets(buffer, CONST_P, stdin) == NULL){
            printf("Invalid input!\n");
            exit(1);
        }
        int read = 0;  //Credit M Oehm on SO. Help resolve sscanf starting point. Refer README.
        for(int j=0; j <Cols; j++){
            int result1 = sscanf(buffer+read, "%i%n", &array[i][j], &read_current);
            invalidResult1(result1);

            read += read_current;
            array0[i][j] = array[i][j];
        }
    }
    modify_val(CharP, Int2, Rows, Cols, array, array0);
}

void FreeArray(int **array, int **array0, int Rows){
    for(int i=0; i<Rows; i++){
        free(array0[i]);
        free(array[i]);
    }
    free(array);
    free(array0);
}

typedef enum model{
    Grassland, //0
    River, //1
    NorthWestRiverBend, //2
    SouthWestRiverBend, //3
    NorthEastRiverBend, //4
    SouthEastRiverBend, //5
    NorthEastSouthFork, //6
    NorthWestSouthFork, //7
    WestNorthEastFork, //8
    WestSouthEastFork, //9
    FourWayFork //10
}model;

int check_top(const int *a0_top, const int *a0_Bval){
    if((a0_top >= a0_Bval) && (*a0_top==River)){
        return(1);
    }
    return 0;
}
int check_bottom(const int *a0_bottom, const int *a0_Bval){
    if((a0_bottom <= a0_Bval) && (*a0_bottom==River)){
        return(1);
    }
    return 0;
}
int check_left(const int *a0_left, const int *a0_Bval){
    if((a0_left >= a0_Bval) && (*a0_left == River)){
        return(1);
    }
    return 0;
}
int check_right(const int *a0_right, const int *a0_Bval){
    if((a0_right <= a0_Bval) && (*a0_right == River)){
        return(1);
    }
    return 0;
}
struct RiverPos{
    int self;
    int top;
    int bottom;
    int left;
    int right;
};
void PosMod(struct RiverPos position, int *array);

void check_NWRB(struct RiverPos position, int *array){
    if((position.self>=River) && (position.top==River) && (position.left==River)){
        *array = NorthWestRiverBend;
    }
}
void check_SWRB(struct RiverPos position, int *array){
    if((position.self>=River) && (position.left==River) && (position.bottom==River)){
        *array = SouthWestRiverBend;
    }
}
void check_NERB(struct RiverPos position, int *array){
    if((position.self>=River) && (position.top==River) && (position.right==River)){
        *array = NorthEastRiverBend;
    }
}
void check_SERB(struct RiverPos position, int *array){
    if((position.self>=River) && (position.bottom==River) && (position.right==River)){
        *array = SouthEastRiverBend;
    }
}
void check_NESF(struct RiverPos position, int *array){
    if((position.self>=River) && (position.bottom==River) && 
        (position.right==River) && (position.top==River)){
        *array = NorthEastSouthFork;
    }
}
void check_NWSF(struct RiverPos position, int *array){
    if((position.self>=River) && (position.bottom==River) && 
        (position.left==River) && (position.top==River)){
        *array = NorthWestSouthFork;
    }
}
void check_WNEF(struct RiverPos position, int *array){
    if((position.self>=River) && (position.right==River) && 
        (position.left==River) && (position.top==River)){
        *array = WestNorthEastFork;
    }
}
void check_WSEF(struct RiverPos position, int *array){
    if((position.self>=River) && (position.right==River) && 
        (position.left==River) && (position.bottom==River)){
        *array = WestSouthEastFork;
    }
}
void check_FWF(struct RiverPos position, int *array){
    if((position.self>=River) && (position.right==River) && (position.left==River) 
        && (position.bottom==River) && (position.top==River) ){
        *array = FourWayFork;
    }
}
void PosMod(struct RiverPos position, int *array){
    check_NWRB(position, array);
    check_SWRB(position, array);
    check_NERB(position, array);
    check_SERB(position, array);
    check_NESF(position, array);
    check_NWSF(position, array);
    check_WNEF(position, array);
    check_WSEF(position, array);
    check_FWF(position, array);
}
void modify_val(char CharP, int Int2, int Rows, int Cols, int**array, int**array0){
    for (int i=0; i < Rows; i++){
        for (int j=0; j< Cols; j++){
            int ReturnValSelf = 0;
            int ReturnValTop = 0;
            int ReturnValBottom = 0;
            int ReturnValLeft = 0;
            int ReturnValRight = 0;
            ReturnValSelf = array0[i][j];
            ReturnValTop = check_top(&array0[i-1][j], &array0[0][0]);
            ReturnValBottom = check_bottom(&array0[i+1][j], &array0[Rows-1][Cols-1]);
            ReturnValLeft = check_left(&array0[i][j-1], &array0[i][0]);
            ReturnValRight = check_right(&array0[i][j+1], &array0[i][Cols-1]);

            struct RiverPos Pos_check = {ReturnValSelf,ReturnValTop,
                                        ReturnValBottom,ReturnValLeft,ReturnValRight};
            PosMod(Pos_check, &array[i][j]);
        }

    }
    printf("%c%i\n", CharP, Int2);
    printf("%i %i\n", Cols, Rows);
    printf("%i\n", TEN);
    for (int i=0; i < Rows; i++){
        for (int j=0; j< Cols; j++){
            printf("%2d ", array[i][j]);
        }
    printf("\n");
    }
    FreeArray(array, array0, Rows);
} 
