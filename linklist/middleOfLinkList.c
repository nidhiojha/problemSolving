#include<stdio.h>
#include<stdlib.h>
struct Node
{
  struct Node *next;
  int data;
};
 void insertNode(struct Node **head, int data)
 {
   struct Node *new_node = 
        (struct Node *)malloc(sizeof(struct Node));
   new_node->data = data;
   new_node->next = *head;
   *head = new_node;
 }
void getMiddleNode(struct Node *head)
{
  struct Node *slow_ptr = head;
  struct Node *fast_ptr = head;
  if(head != NULL)
  {
      while( fast_ptr != NULL && fast_ptr->next != NULL)
      {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
      }
      printf("%d", slow_ptr->data);
  }
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
 int main()
{
  struct Node *head = NULL;
  insertNode(&head, 1);
  insertNode(&head, 12);
  insertNode(&head, 2);
  insertNode(&head, 4);
  insertNode(&head, 1);
  insertNode(&head, 1);
  printf("given link list--> ");
  printList(head);

  printf("\nmiddle of the link list is ");
   getMiddleNode(head);
}