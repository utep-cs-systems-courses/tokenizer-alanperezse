#include <stdio.h>
#include "tokenizer.h"
#include "history.h"


#define MAX_LIMIT 60
//void reverb();
int is_print(char *str);
int is_quit(char *str);
int is_id(char *str);
int input_to_id(char *str);
void tokenize_history(List *list, int idx);
void format_input(char *str);

int main() {
  char input[MAX_LIMIT];
  List *list = init_history();
  int idx;
  int len = 0;
  
  do {
    printf("\nPlease provide a sentence to tokenize.\n Press '!q' to quit, press '!p' to print a list of saved inputs, press '!n' to tokenize the string with id = n from the list.\n> "); 
    fgets(input, MAX_LIMIT, stdin);
    format_input(input);
    puts("");

    // Print previous strings
    if(is_print(input)) print_history(list);
    // Break while
    else if(is_quit(input)) break;
    // Print element
    else if(is_id(input)) tokenize_history(list, input_to_id(input));
    // Add and then pring last element
    else {
      add_history(list, input);
      len++;
      tokenize_history(list, len);
    }
    
  } while(1);

  free_history(list);
  return 0;
}

void tokenize_history(List *list, int idx) { 
  char *str = get_history(list, idx);
  if(str == 0) {
    puts("Invalid id. You may see the valid id's by pressing !p.\n");
    return;
  }

  puts("Tokenizing string...");
  
  char **tokens = tokenize(str);
  print_tokens(tokens);
  free_tokens(tokens);
}


int is_print(char *str) {
  char *s = word_start(str);
  char *e = word_terminator(s);
  e = word_start(e);
  
  return (s[0] == '!' && s[1] == 'p' && (s[2] == ' ' || s[2] == 0));
}

int is_quit(char *str) {
  char *s = word_start(str);
  char *e = word_terminator(s);
  e = word_start(e);
  
  return (s[0] == '!' && s[1] == 'q' && (s[2] == ' ' || s[2] == 0));
}

int is_id(char *str) {
  char *s = word_start(str);

  if(*s == '!') s++;
  else return 0;

  // Must have at least one integer after '!'
  if(*s < '0' || '9' < *s) return 0;
  
  while(1) {
    // Valid char
    if('0' <= *s && *s <= '9') {
      s++;
      continue;
    }
    // End of file. Return true
    else if(*s == 0) return 1;
    // Invalid char
    else return 0;
  }
}

int input_to_id(char *str) {
  char *s = word_start(str);
  char *e = word_terminator(s);
  s++;

  int rtn = 0;
  while(s < e) {
    rtn *= 10;
    rtn += *s - '0';
    s++;
  }

  return rtn;
}

void format_input(char *str) {
  while(1) {
    // If end of string
    if(*str == 0) return;
    // Replace newline with end of string
    if(*str == '\n') {
      *str = 0;
      return;
    }  
    str++;
  }  
}

/* First 'echo' method
void reverb() {
  char input[MAX_LIMIT];
  printf("Please provide a sentence.\n> ");
 
  fgets(input, MAX_LIMIT, stdin);
  
  printf("%s\n", input);
  }
*/
