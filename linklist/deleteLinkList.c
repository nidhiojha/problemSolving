#include <stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
void insertNode(struct Node **head, int new_data)
{
  struct Node *new_node = 
          (struct Node *)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = *head;
  *head = new_node;
}
void deleteLinkList(struct Node **head)
{
  struct Node *current = *head;
  struct Node *next;
  while(current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }
  *head = NULL;
}
int main() 
{
  struct Node *head  = NULL;
  insertNode(&head, 1);
  insertNode(&head, 4);
  insertNode(&head, 1);
  insertNode(&head, 12);
  insertNode(&head, 1);
  deleteLinkList(&head);
  printf("link list deleted");
  return 0;
}