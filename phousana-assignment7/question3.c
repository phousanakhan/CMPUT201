#include <stdio.h>
#include <stdlib.h>

// Read a string to the stack and the heap and print it out


/* checkInput: given the result of scanf check if it 
 * 0 elements read or EOF. If so exit(1) with a warning.
 *
 */

//FIX#1: +1 to bufferStack. Else will be writing size of 17 to 16. Thus overflow.
//FIX#2: sizeof(char) + 1
//FIX#3: free bufferheap when exit in checkInput

void checkInput(int err, char**ptr) {
  if (!err || err == EOF) {
    printf("\nInvalid input!\n");
    free(*ptr);
    exit(1);
  }
}

#define N 16

int main() {
  char bufferStack[N+1] = { '\0' };
  char * bufferHeap = calloc(N, sizeof(char)+1);
  char junk[N+1];
  printf("Enter a string no more than 16 chars long\n0123456789012345\n");
  checkInput(scanf("%16[^\n]", bufferStack), &bufferHeap);
  printf("BufferStack: %s\n", bufferStack);
  checkInput(scanf("%16[\n]", junk), &bufferHeap);
  checkInput(scanf("%16[^\n]", bufferHeap), &bufferHeap);
  printf("BufferHeap: %s\n", bufferHeap);
  free(bufferHeap);
  return 0;
}




