#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
}*head, *list, *temp;


void insert(int x)
{ 
  list = (struct node*)malloc(sizeof(struct node));
  list->data = x;
  list->next = NULL;

  temp = head;

  while(temp->next != NULL)
    temp = temp->next;


  temp->next = list;

  printf("\n%d added", x);
} 

void delete(int x)
{ 
  temp = head;
  int z=0;

  while(temp->next != NULL)
  {
    list = temp->next;
    if(list->data == x)
    {
      z=1;
      temp->next = list->next;
      printf("\n%d deleted", x);
      break;
    }
    temp = temp->next;
  }
  
  if(z==0)
  {
    printf("\nElement not found");
  }

  
}




void show()
{
  temp = head;
  
  if(temp->next == NULL)
    printf("\nlist empty");
  else
  { 
     temp = temp->next;
     while( temp->next != NULL)
     {
       printf("%d ", temp->data);
       temp = temp->next;
     }
     printf("%d ", temp->data);
  }
}


int main()
{ 
  char ch = 'y'; //to keep the loop on
  int a; //to store the user input

  head = (struct node*)malloc(sizeof(struct node));
  head->next = NULL;

  
  while(ch != 'n')
   {
    printf("\n1. Insert\n2. Delete\n3. Show\n"); //displaying options to user
    scanf("%d", &a);
    switch(a)
     {
      case 1: printf("\nEnter the element to be inserted: ");
              scanf("%d", &a);
              insert(a);
              break;
      case 2: printf("\nEnter the element to be deleted: ");
              scanf("%d", &a);
              delete(a);
              break;
      case 3: show();
              break;
    }
    
    printf("\ncontinue (y/n)?: ");
    scanf("%c", &ch);
    scanf("%c", &ch);
  }

  return 0;
}
