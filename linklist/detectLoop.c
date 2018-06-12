#include<stdlib.h>
#include<stdio.h>
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
int detectloop(struct Node *head)
{
  struct Node *fast_ptr = head;
  struct Node *slow_ptr = head;
  while(slow_ptr && fast_ptr && fast_ptr->next != NULL)
  {
    slow_ptr = slow_ptr->next;
    fast_ptr = fast_ptr->next->next;
    if(slow_ptr == fast_ptr)
    {
      printf("found loop and loop point is %d", slow_ptr->data);
      return 1;
    }
  }
  return 0;
}
int main()
{
  struct Node *head = NULL;
  insertNode(&head, 20);
  insertNode(&head, 4);
  insertNode(&head, 15);
  insertNode(&head, 10);
  head->next->next->next->next = head;
  detectloop(head);
}