#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Make a strncpy ourselves 


// a strncpy clone (man strncpy)
// len is the maximum number of chars to copy including nul

//3 FIXES
//FIX#1 dest[len-1]='\0'. Add null terminator
//FIX#2 +1 to malloc to account for null terminator

void myStrncpy(char * dest, const char * src, const int len) {
  for (int i = 0 ; i < len-1 && src[i]; i++) {
    dest[i] = src[i];
  }
  dest[len-1] = '\0';
}

#define N 64
#define NLETTERS 26
#define THELETTERA 'A'
int main() {
  char * bufferHeap = malloc(N*sizeof(char)+1);
  memset(bufferHeap, THELETTERA, N*sizeof(char));
  char bufferStack[N] = { THELETTERA };

  // initialize 
  for (int i = 0 ; i < N - 1; i++) {
    char newLetter = (char)(THELETTERA + i % NLETTERS);
    bufferStack[i] = newLetter;
  }
  
  myStrncpy(bufferHeap, bufferStack, N);
  printf("BufferStack:\t %s\n", bufferStack);
  printf("BufferHeap:\t %s\n", bufferHeap);
  free(bufferHeap);
  return 0;
}
