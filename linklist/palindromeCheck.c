#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
  char data;
  struct Node *next;
};
void insertChar(struct Node **head, char new_data)
{
  struct Node *new_node = 
        (struct Node *)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = *head;
  *head = new_node;
}
void printList(struct Node *head)
{
  while(head != NULL)
  {
    printf("%c->", head->data);
    head = head->next;
  }
  printf("NULL\n");
}
bool compareList(struct Node *head1, struct Node *head2)
{
  struct Node *temp1 = head1;
  struct Node *temp2 = head2;
  while(temp1 && temp2)
  {
    if(temp1->data == temp2->data)
    {
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
    else return 0;
  }
  if(temp1 == NULL && temp2 == NULL)
    return 1;
  return 0;
}
void reverse(struct Node **head)
{
  struct Node *prev = NULL;
  struct Node *current = *head;
  struct Node *next ;
  while(current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

bool isPalindrome(struct Node *head)
{
  struct Node *slow_ptr = head, *fast_ptr = head;
  struct Node *prev_of_slow_ptr = head, *mid_node = NULL,             *second_half;
  bool res = true;
  if(head != NULL && head->next != NULL)
  {
    while(fast_ptr != NULL && fast_ptr->next != NULL)
    {
      fast_ptr = fast_ptr->next->next;
      prev_of_slow_ptr = slow_ptr;
      slow_ptr = slow_ptr->next;
    }
    if(fast_ptr != NULL)
    {
      mid_node = slow_ptr;
      slow_ptr = slow_ptr->next;
    }
    second_half = slow_ptr;
    prev_of_slow_ptr->next = NULL;
    reverse(&second_half);
    res = compareList(head, second_half);
    if (mid_node != NULL)
    {
      prev_of_slow_ptr->next = mid_node;
      mid_node->next = second_half;
    }
    else prev_of_slow_ptr->next = second_half;
  }
  return res;
}
int main()
{
  struct Node *head = NULL;
  char str[] = "abacaba";
  int elem_i;
  for(elem_i = 0; str[elem_i] != '\0'; elem_i++)
  {
    insertChar(&head, str[elem_i]);
    printList(head);
    isPalindrome(head)? printf("string is palindrome\n\n "):
                        printf("string is not palindrome\n\n ");
  }
  return 0;
}