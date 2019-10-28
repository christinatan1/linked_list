#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){

  //testing empty list
  struct node *linkedList;
  linkedList = NULL;
  print_list(linkedList);

  //testing adding numbers and full list
  printf("Adding #s 0-9 to list.\n");
  int num;
  struct node *test;
  for (int num = 0; num < 10; num++){
    linkedList = insert_front(linkedList, num);
  }
  print_list(linkedList);

  //testing remove_node
  printf("Removing -10: \n");
  linkedList = remove_node(linkedList, -10);
  print_list(linkedList);
  printf("Removing 0: \n");
  linkedList = remove_node(linkedList, 0);
  print_list(linkedList);
  // printf("Removing 9: \n");
  // linkedList = remove_node(linkedList, 9);
  // print_list(linkedList);
  // printf("Removing 5: \n");
  // linkedList = remove_node(linkedList, 5);
  // print_list(linkedList);

  //testing free_list
  printf("Freeing list. \n");
  linkedList = free_list(linkedList);
  print_list(linkedList);

}
