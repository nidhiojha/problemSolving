#include<stdio.h>
#include<stdlib.h>

struct Node 
{
  int data ;
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
  while(temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

void deleteNode(struct Node *head)
{
  struct Node *temp = head->next;
  head->data = temp->data;
  head->next = temp->next;
  free(temp);
} 
int main()
{
  struct Node *head = NULL;
  insertNode(&head, 1);
  insertNode(&head, 12);
  insertNode(&head, 1);
  insertNode(&head, 4);
  insertNode(&head, 1);
  printf("link list before deletion---> ");
  printList(head);

  deleteNode(head);
  printf("link list after deletion \t");
  printList(head);
}