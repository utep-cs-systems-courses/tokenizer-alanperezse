#include <stdio.h>
#include "tokenizer.h"
#include "history.h"


#define MAX_LIMIT 60
//void reverb();
int is_print(char *str);
int is_quit(char *str);
int is_id(char *str);
void tokenize_history(List *list, int idx);

int main() {
  char input[MAX_LIMIT];
  List *list = init_history();
  int idx;
  int len = 0;
  
  do {
    printf("\nPlease provide a sentence to tokenize.\n Press '!q' to quit, press '!p' to print a list of saved inputs, press '!n' to tokenize the string with id = n from the list.\n> "); 
    fgets(input, MAX_LIMIT, stdin);
    puts("");

    // Print previous strings
    if(is_print(input)) print_history(list);
    // Break while
    else if(is_quit(input)) break;
    // Print element
    else if(idx = is_id(input)) tokenize_history(list, idx);
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
  
  return (s[0] == '!' && s[1] == 'p' && (s[2] == '\n' || s[2] == ' ' || s[2] == 0));
}

int is_quit(char *str) {
  char *s = word_start(str);
  char *e = word_terminator(s);
  e = word_start(e);
  
  return (s[0] == '!' && s[1] == 'q' && (s[2] == '\n' || s[2] == ' ' || s[2] == 0));
}

int is_id(char *str) {
  char *s = word_start(str);
  s++;
  
  if('0' <= *s && *s <= '9') return *s - '0';
  else return 0;
}

/* First 'echo' method
void reverb() {
  char input[MAX_LIMIT];
  printf("Please provide a sentence.\n> ");
 
  fgets(input, MAX_LIMIT, stdin);
  
  printf("%s\n", input);
  }
*/
