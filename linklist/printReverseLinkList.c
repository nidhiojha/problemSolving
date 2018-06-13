#include <stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
void insertNode(struct  Node **head, int new_data)
{
  struct Node *new_node = 
          (struct Node *)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = *head;
  *head = new_node;
}
void printList(struct Node *head)
{
  struct Node *temp = head;
  while(temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}
void printReverseList(struct Node *head)
{
  if(head == NULL)
  return;
  printReverseList(head->next);
  printf("%d ", head->data);
}
int main(void) 
{
  struct Node *head = NULL;
  insertNode(&head, 1);
  insertNode(&head, 2);
  insertNode(&head, 3);
  insertNode(&head, 4);
  printf("actual list--> ");
  printList(head);
  printf("\nprint reverse of link list--> ");
  printReverseList(head);
  return 0;
}