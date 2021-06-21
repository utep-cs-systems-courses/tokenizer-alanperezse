#include <stdio.h>

#define MAX_LIMIT 100
void reverb();


int main() {
  reverb();
}

void reverb() {
  char input[MAX_LIMIT];
  printf("Please provide a sentence.\n> ");
 
  fgets(input, MAX_LIMIT, stdin);
  
  printf("%s\n", input);
}
