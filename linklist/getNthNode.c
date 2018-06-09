#include<stdio.h>
#include<stdlib.h>
struct node
{ 
  int data;
  struct node *next;
};
void insertNode(struct node **head, int data)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}
int getNthNode(struct node *head, int index)
{
  struct node *current = head;
  int count =0;
  while(current != NULL)
  {
    if(count == index)
      return current->data;
    count++;
      current = current->next;
  }
  return 0;
}
int main()
{
  struct node *head = NULL;
  insertNode(&head,1);
  insertNode(&head,4);
  insertNode(&head,1);
  insertNode(&head,12);
  insertNode(&head,1);
  insertNode(&head,8);
  insertNode(&head,10);
  printf("element at index 3 is %d",getNthNode(head,3));
}