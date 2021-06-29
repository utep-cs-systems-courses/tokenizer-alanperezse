#include <stdlib.h>
#include <stdio.h>
#include "history.h"

void free_node(Item *node);

int llStrlen(char *s) {
  char *e = s;
  while(*e != '\0') e++;
  
  return e - s;
}

List *init_history() {
  List *rtn = malloc(sizeof(List));
  rtn->root = 0;
  return rtn;
}

Item *init_node() {
  Item *rtn = malloc(sizeof(Item));
  rtn->next = 0;
  return rtn;
}

void add_history(List *list, char *str) {
  // Set up new node
  Item *newNode = init_node();
  int len = llStrlen(str), sindex = 0;
  char *scopy = malloc((len + 1) * sizeof(char)), c;
  do {
    c = *(scopy + sindex) = *(str + sindex);
    sindex++;
  }while(c);
  newNode->str = scopy;

  // Find insertion point
  if(list->root == 0) { // Empty list
    list->root = newNode;
    newNode->id = 1;
  } else {
    Item *curr = list->root;
    // Iterate until last node is found
    while(curr->next != 0) curr = curr->next;
    curr->next = newNode;
    newNode->id = curr->id + 1;
  }
}

char *get_history(List *list, int id) {
  // Invalid id
  if(id < 1) return 0;

  // Empty list
  if(list->root == 0) return 0;

  Item *curr = list->root;

  while(curr->id != id) {
    // No nodes left
    if(curr->next == 0) return 0;

    curr = curr->next;
  }

  return curr->str;
}

void print_history(List *list) {
  if(list->root == 0) {
    puts("No elements to display\n");
    return;
  }
  
  Item *curr = list->root;
  while(curr != 0) {
    printf("%d. %s\n", curr->id, curr->str);
    curr = curr->next;
  }
}

void free_node(Item *node) {  
  // Recursive call
  if(node->next != 0) free_node(node->next);

  free(node->str);
  free(node);
}

void free_history(List *list) {
  if(list->root != 0) free_node(list->root);
  free(list);
}
