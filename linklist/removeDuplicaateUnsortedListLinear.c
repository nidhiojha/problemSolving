#include <stdio.h>
#include <stdlib.h>
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
  while(head)
  {
    printf("%d ", head->data);
    head = head->next;
  }
}
void removeDuplicate(struct Node *head)
{
  struct Node *ptr1 = head, *ptr2, *dup;
  while(ptr1 != NULL && ptr1->next != NULL)
  {
    ptr2 = ptr1;
    while(ptr2->next != NULL)
    {
      if(ptr1->data == ptr2->next->data)
      {
        dup = ptr2->next;
        ptr2->next = ptr2->next->next;
        free(dup);
      }
      else
        ptr2 = ptr2->next;
    }
    ptr1 = ptr1->next;
  }
}
int main() 
{
  struct Node *head = NULL;
  insertNode(&head, 10);
  insertNode(&head, 12);
  insertNode(&head, 11);
  insertNode(&head, 11);
  insertNode(&head, 12);
  insertNode(&head, 11);
  insertNode(&head, 10);
  printf("original link list--> ");
  printList(head);
  removeDuplicate(head);
  printf("\nlist after duplicate removal");
  printList(head);
  return 0;
}