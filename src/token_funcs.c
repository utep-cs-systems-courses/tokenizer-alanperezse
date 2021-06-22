#include <stdio.h>

int space_char(char c) {
  return (c == '\t' || c == ' ');
}

int non_space_char(char c) {
  return !space_char(c);
}

char *word_start(char *str) {
  int idx = 0;
  while(1) {
    if(space_char(*(str + idx))) idx++;

    else return str + idx;
  }
}

char *word_terminator(char *word) {
  int idx = 0;
  while(*(word + idx) != '\0' && non_space_char(*(word + idx))) idx++;

  return word + idx;
}

int count_words(char *s) {
  // Dinamically changing pointer
  char *pointer = s;
  // Return variable
  int rtn = 0;

  while(*(pointer = word_start(pointer)) != '\0') {
    rtn++;
    pointer = word_terminator(pointer);
  }

  return rtn;
}
