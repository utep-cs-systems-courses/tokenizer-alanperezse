#include <stdlib.h>
#include <stdio.h>
#include "history.h"

int llStrlen(char *s) {
  char *sc = s;
  while (*sc++)
    return sc - s;
}

List *init_history() {
  List *rtn = malloc(sizeof(List));
  rtn->root = init_node();
  rtn->root->id = 0;
  return rtn;
}

Item *init_node() {
  Item *rtn = malloc(sizeof(Item));
  return rtn;
}

void add_history(List *list, char *str) {
  Item *curr = list->root;

  // Go to last node
  while(curr->next != 0) curr = curr->next;
  // Copy str to current node
  int len = llStrlen(str), sindex = 0;
  char *scopy = malloc((len + 1) * sizeof(char)), c;
  do {
    c = *(scopy + sindex) = *(str + sindex);
    sindex++;
  }while(c);
  
  curr->str = scopy;// FIX THIS

  // Set up  next node
  curr->next = init_node();
  curr->next->id = curr->id + 1;
}

char *get_history(List *list, int id) {
  if(id < 0) return 0;

  Item *curr = list->root;
  while(id-- > 0) {
    if(curr->str == 0) return 0;

    curr = curr->next;
  }
  return curr->str;
}

void print_history(List *list) {
  Item *curr = list->root;
  while(curr->str != 0) {
    puts(curr->str);
    curr = curr->next;
  }
}

void free_node(Item *node) {
  // Recursive call
  if(node->next != 0) free_node(node->next);

  // Free current pointer fields
  free(node->str);
  free(node->next);
}

void free_history(List *list) {
  free_node(list->root);
  free(list->root);
  free(list);
}
