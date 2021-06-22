#include <stdio.h>

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

char *word terminator(char *word) {
  while(*word != '\0' && space_char(*word)) word++;

  // Once a zero pointer or a pointer to a space is found, return the pointer previous to it.
  return --word;
}
