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
void printList(struct Node *node)
{
   while (node!=NULL)
    {
       printf("%d ", node->data);
       node = node->next;
    }
}
void removeDuplicate(struct Node *head)
{
  struct Node *temp = head;
  struct Node *next_next;
  if(temp ==  NULL)
    return;
  while(temp->next != NULL)
  {
    if(temp->data ==  temp->next->data)
    {
      next_next = temp->next->next;
      free(temp->next);
      temp->next = next_next;
    }
    else
    {
      temp = temp->next;
    }
  }
}
int main()
{
  struct Node *head = NULL;
  insertNode(&head, 20);
  insertNode(&head, 13);
  insertNode(&head, 13);
  insertNode(&head, 11);
  insertNode(&head, 11);
  insertNode(&head, 11);
  printf("original link list--> ");
  printList(head);
  removeDuplicate(head);
  printf("link list after duplicate deletion--> ");
  printList(head);
  return 0;
}