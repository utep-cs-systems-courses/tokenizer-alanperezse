#include <stdlib.h>
#include <stdio.h>
#include "history.h"

List *init_history() {
  List *rtn = malloc(sizeof(List));
  rtn->root = init_node();
  return rtn;
}

Item *init_node() {
  Item *rtn = malloc(sizeof(Item));
  *(rtn->str) = 0;
  return rtn;
}

void add_history(List *list, char *str) {
  Item *curr = list->root;
  // Go to last node
  while(*(curr->str) != 0) curr = curr->next;

  // Set string and append new empty node
  curr->str = str;
  curr->next = init_node();
}

char *get_history(List *list, int id) {
  return 0;
}

void print_history(List *list) {
}

void free_history(List *list) {
  
}
