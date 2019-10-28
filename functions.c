#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// struct node {
//   int i;
//   struct node *next;
// };

void print_list(struct node *x){
  if (x == 0){
    printf("Printing empty list: [ ]\n");
  }
  else {
    printf("Printing list: \n");
    printf("[");
    while (x->next != 0){
      printf(" %d", x->i);
      x = x->next;
    }
    printf(" %d ]\n", x->i);
  }
}

struct node *insert_front(struct node *front, int i){
  struct node *newNode = malloc(sizeof(struct node));
  newNode -> i = i;
  newNode -> next = front;
  return newNode;
}

struct node *free_list(struct node *front){
  struct node *p;
  while (front -> next != NULL){
    printf("freeing node: %d\n", front->i);
    p = front->next;
    free(front);
    front = NULL;
    front = p;
  }
  printf("freeing node: %d\n", front->i);
  free(front);
  front = NULL;
  return front;
}

struct node *remove_node(struct node *front, int data){
  struct node *temp = front;
  if(front->i == data){
    free(temp);
    temp = NULL;
    front = front->next;
    return front;
  }

  while (temp->next != NULL){
    if ((temp->next)->i == data && (temp->next)->next != NULL){
      struct node *x; //temp value that holds the pointer to the next node after temp->next
      x = (temp->next)->next;
      free(temp->next);
      temp->next = NULL;
      temp->next = x;
      return front;
    }
    if ((temp->next)->i == data && (temp->next)->next == NULL){
      free(temp -> next);
      temp->next = NULL;
      return front;
    }
    temp = temp->next;
  }
  return front;

}
