#include <stdio.h>
#include <stdlib.h>
// print in rows of 5, 99 to 0

//FIX#1: assigning first,..,fifth
//FIX#2: initialize myIntegers to 0

#define N (5*20)
#define BASE 5
int main() {
  int * myIntegers = malloc( N * sizeof(int*)+1);
  for(int j = 0; j < N; j++){
    myIntegers[j] = 0;
  }

  for (int i = N-1; i > 0; i--) {
    myIntegers[N-1-i] = i;
  }
  int * ints = myIntegers;
  for (int i = 0; i < N / BASE; i++) {
    int first = *ints++;
    int second = *ints++;
    int third = *ints++;
    int fourth = *ints++;
    int fifth = *ints++;
    printf("%d %d %d %d %d\n", first, second, third, fourth, fifth);
  }
  free(myIntegers);
}
