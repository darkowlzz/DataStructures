#include<stdio.h>

#define MAX 5

int q[MAX], front=-1, rear=-1;

void insertfrnt();
void insertrear();
void delfrnt();
void delrear();
void print();

int main()
{
  char ch='y';
  int a;

  while(ch == 'y')
  {
    printf("\n1. Insert at front");
    printf("\n2. Insert at rear");
    printf("\n3. Delete at front");
    printf("\n4. Delete at rear");
    printf("\nEnter your choice: ");
    scanf("%d", &a);

    switch(a)
    {
      case 1: insertfrnt();
              break;
      case 2: insertrear();
              break;
      case 3: delfrnt();
              break;
      case 4: delrear();
              break;
      case 5: print();
    }

    printf("\nContinue (y/n)?:");
    scanf("%c", &ch);
    scanf("%c", &ch);
  } 

  return 0;
}


void print()
{
  int i;
  if(front == -1)
    printf("\nQueue empty");
  else
  {
    if(front<=rear)
    {
      for(i=front; i<=rear; i++)
        printf("%d ", q[i]);
    }
    else
    {
      for(i=0; i<=rear; i++)
      {
        printf("%d ", q[i]);
      }
      for(i=front; i<MAX; i++)
        printf("%d ", q[i]);
    }
  }

}

void insertfrnt()
{
  if((front == rear+1) || ((front == 0) && (rear == MAX-1)))
    printf("\nQueue Full");
  else
  {
    if(front == -1)
    {
      front++;
      rear++;
    }
    else
    {
      if(front == 0)
        front = MAX-1;
      else
        front--;
    }
  
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &q[front]);
  }
}

void insertrear()
{
 if((front == rear+1) || ((front == 0) && (rear == MAX-1)))
    printf("\nQueue Full");
 else
 {
   if(rear == -1)
   {
     rear++;
     front++;
   }
   else
   {
     if(rear == MAX-1)
       rear = 0;
     else
       rear++;
   }
   printf("\nEnter the element to be inserted: ");
   scanf("%d", &q[rear]);
}
    
   




}

void delfrnt()
{
  if(front == -1)
    printf("\nQueue Empty");
  else
  {
    printf("\nDeleted element is: %d", q[front]);
    if(front == rear)
    {
      front = -1;
      rear = -1;
    }
    else
    {
      if(front == MAX-1)
        front = 0;
      else
        front++;
    }
  } 
} 

void delrear()
{
  if(front == -1)
    printf("\nQueue Empty");
  else
  {
    printf("\nDeleted element is: %d", q[rear]);
    if(front == rear)
    {
      front = -1;
      rear = -1;
    }
    else
    {
      if(rear==0) 
        rear = MAX-1;
      else
        rear--;
    }
  }
}




