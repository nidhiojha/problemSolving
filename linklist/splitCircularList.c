#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
void insertNode(struct Node **head_ref, int data)
{
  struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
  struct Node *temp = *head_ref; 
  ptr1->data = data;  
  ptr1->next = *head_ref; 
  if(*head_ref != NULL)
  {
    while(temp->next != *head_ref)
      temp = temp->next;        
    temp->next = ptr1; 
  }
  else
     ptr1->next = ptr1; /*For the first node */
 
  *head_ref = ptr1;
}
 void printList(struct Node *head)
 {
  struct Node *temp = head; 
  if(head != NULL)
  {
    printf("\n");
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
  }
 }
 void splitList(struct Node *head, struct Node **head1, 
                                   struct Node **head2)
  {
    struct Node *fast_ptr = head;
    struct Node *slow_ptr = head;
    if(head == NULL)
      return ;
    while (fast_ptr->next != head && fast_ptr->next->next != head)
    {
      fast_ptr = fast_ptr->next->next;
      slow_ptr = slow_ptr->next;
    }
    if(fast_ptr->next->next == head)
    {
      fast_ptr = fast_ptr->next;
    }
    *head1 = head;
    if(head->next != head)
    {
      *head2 = slow_ptr->next;
    }
    fast_ptr->next = slow_ptr->next;
    slow_ptr->next = head;
  }
 int main()
 {
   struct Node *head = NULL;
   struct Node *head1 = NULL;
   struct Node *head2 = NULL;
   insertNode(&head, 1);
   insertNode(&head, 2);
   insertNode(&head, 3);
   insertNode(&head, 4);
   printf("original link list--> ");
   printList(head);
   splitList(head, &head1, &head2);
   printf("\nfirst list after split--> ");
   printList(head1);
   printf("\nsecond list after split");
   printList(head2);
   return 0;

 }