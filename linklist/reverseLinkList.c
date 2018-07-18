#include<stdio.h>
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
void printList(struct Node *head)
{
  struct Node *temp = head;
  while(temp)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}
static void reverseLinkList(struct Node **head)
{
  struct Node *prev = NULL;
  struct Node *current = *head;
  struct Node *next = NULL;
  while(current != NULL)
  {
    next = current->next;
    current->next = prev ;
    prev = current;
    current = next;
  }
  *head = prev;
}
int main()
{
  struct Node *head = NULL;
  insertNode(&head, 1);
  insertNode(&head, 12);
  insertNode(&head, 1);
  insertNode(&head, 4);
  insertNode(&head, 1);
  printf("given link list is---> ");
  printList(head);
  reverseLinkList(&head);
  printf("\nreversed link list---> ");
  printList(head);
  return 0;
}