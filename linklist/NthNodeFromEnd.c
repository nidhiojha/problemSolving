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
void printNthFromLast(struct Node *head, int position)
{
  int len = 0, elem_i;
  struct Node *temp = head;
  while(temp != NULL)
  {
    temp = temp->next;
    len++;
  }
  if(len < position)
    return;
  temp = head;
  for(elem_i = 1; elem_i < len-position+1; elem_i++)
    temp = temp->next;
  printf("%d", temp->data);
}
int main()
{
  struct Node *head = NULL;
  insertNode(&head, 20);
  insertNode(&head, 4);
  insertNode(&head , 15);
  insertNode(&head, 35);
//insertNode(&head , 1);
  printNthFromLast(head, 4);
  return 0;
}
