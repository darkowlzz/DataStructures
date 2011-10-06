#include<stdio.h>
#include<stdlib.h>

struct node
{
  int coeff, pow;
  struct node *link;
};

void create(struct node *p)
{
  char ch;
  do
  {
    printf("\nEnter coefficient: ");
    scanf("%d", &p->coeff);

    printf("\nEnter power: ");
    scanf("%d", &p->pow);

    p->link = (struct node*)malloc(sizeof(struct node));
    p = p->link;
    p->link = NULL;
    printf("\nContinue writing(y/n): ");
    scanf("%c",&ch);
    scanf("%c",&ch);
  }
  while(ch == 'y');
}

void show(struct node *p)
{
  while(p->link != NULL)
  {
    printf("%dx^%d ", p->coeff, p->pow);
    p = p->link;
    if(p->link != NULL)
      printf(" + ");
  }
}

void add(struct node *p1, struct node *p2, struct node *p3)
{
  while(p1->link || p2->link)
  {
    if(p1->pow > p2->pow)
    {
      p3->pow = p1->pow;
      p3->coeff = p1->coeff;
      p1 = p1->link;
    }
    else if(p1->pow < p2->pow)
    {
      p3->pow = p2->pow;
      p3->coeff = p2->coeff;
      p2 = p2->link;
    }
    else
    {
      p3->pow = p1->pow;
      p3->coeff = p1->coeff + p2->coeff;
      p1 = p1->link;
      p2 = p2->link;
    }
    p3->link = (struct node*)malloc(sizeof(struct node));
    p3 = p3->link;
    p3->link = NULL;
  }
}

int main()
{
  struct node *p1, *p2, *p3;
  p1 = (struct node*)malloc(sizeof(struct node));
  p2 = (struct node*)malloc(sizeof(struct node));
  p3 = (struct node*)malloc(sizeof(struct node));

  printf("\nEnter 1st polynomial: ");
  create(p1);
  show(p1);
  
  printf("\nEnter 2nd polynomial: ");
  create(p2);
  show(p2);

  printf("\nAfter addition: ");
  add(p1,p2,p3);
  show(p3);
  
  return 0;
}

