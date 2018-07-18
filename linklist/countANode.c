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
int count(struct Node *head, int element)
{
  int count =0;
  struct Node *temp = head;
  while(temp != NULL)
  {
    if(temp->data == element)
      count = count+1;
    temp = temp->next;
  }
  return count;
}
int main()
{
  struct Node *head = NULL;
  insertNode(&head, 1);
  insertNode(&head, 12);
  insertNode(&head, 1);
  insertNode(&head, 4);
  insertNode(&head, 1);
  printf("count of 1 is %d", count(head, 1));
}