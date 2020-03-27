#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Calculate the sum of a set of integers

/* checkInput: given the result of scanf check if it 
 * 0 elements read or EOF. If so exit(1) with a warning.
 *
 */
//Problem: invalid write of size 4
//FIX#1:modify realloc. change numInts to sizeof(int)*numInts
//FIX#2: initialize bufferheap[i] to 0
//FIX#3: void retCheck so that there's no npath complexity error
void checkInput(int err) {
  if (!err || err == EOF) {
    printf("\nInvalid input!\n");
    exit(1);
  }
}
void retCheck(int ret){
  if (!ret) {
    printf("\nInvalid input!\n");
    exit(1);
  }
}
#define N 4
#define MAXINTS 65535

int main() {
  int * bufferHeap = calloc(N, sizeof(int));
  size_t  numInts = 0;
  printf("What is the maximum number of integers you will provide?\n");
  checkInput(scanf("%lu", &numInts));
  if (numInts > MAXINTS) {
    printf("I think that is too many!\n");
    exit(1);
  }
  if (numInts >= N) {
    bufferHeap = realloc(bufferHeap,sizeof(int)*numInts);
  }  
  for (size_t i = 0; i < numInts; i++) {
    bufferHeap[i] = 0;
  }

  printf("Provide your integers (CTRL-D to end):\n");

  for (size_t i = 0;  i < numInts; i++) {
    int newInt = 0;
    int ret = scanf("%d", &newInt);
    retCheck(ret);
    if (ret == EOF) {
      break;
    }
    bufferHeap[i] = newInt;
  }
  
  long long int sum = 0;

  for (size_t i = 0 ; i < numInts; i++) {
    sum += bufferHeap[i];
  }
  printf("Sum of integers is: %lld\n", sum);
  free(bufferHeap);
  return 0;
}
