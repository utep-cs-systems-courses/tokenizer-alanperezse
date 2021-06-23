#include <stdio.h>
#include "tokenizer.h"
#include "stdlib.h"

int space_char(char c) {
  return (c == '\t' || c == ' ');
}

int non_space_char(char c) {
  return !space_char(c);
}

char *word_start(char *str) {
  while(1) {
    if(space_char(*str)) str++;

    else return str;
  }
}

char *word_terminator(char *word) {
  while(*word != '\0' && non_space_char(*word)) word++;

  return word;
}

int count_words(char *s) {
  int rtn = 0;

  while(*(s = word_start(s)) != '\0') {
    rtn++;
    s = word_terminator(s);
  }

  return rtn;
}

char *copy_str(char *inStr, short len) {
  // Extra memory allocation is for zero char
  char *rtn = malloc((len + 1) * sizeof(char));

  // Copy
  for(int i = 0; i < len; i++) {
    *(rtn + i) = *(inStr + i);

    // If len(inStr) < len;
    if(*rtn == 0) break;
  }

  // Terminator char
  rtn[len] = 0;
  return rtn;
}



char **tokenize(char *s) {
  int num_tokens = count_words(s);

  char **tokens = malloc((num_tokens + 1) * sizeof(char *));

  char *e = 0; // End of word
  for(int i = 0; i < num_tokens; i++) {
    // Locate start and end indices of next word
    s = word_start(s);
    e = word_terminator(s);

    // Copy string to pointer
    *(tokens + i) = copy_str(s, e - s + 1);

    // Update s for next iteration
    s = e;
  }

  // Last pointer is a pointer to a pointer to zero
  char *end = malloc(sizeof(char));
  *end = 0;
  *(tokens + num_tokens) = end;
  
  return tokens;
}

void print_tokens(char **tokens) {
  while(**tokens != 0) {
    puts(*tokens);
    tokens++;
  }
}

void free_tokens(char **tokens) {
  printf("FIX ME");
}
