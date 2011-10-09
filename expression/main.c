#include<stdio.h>

struct node
{
  char item;
  struct node *lchild;
  struct node *rchild;
}*root;

struct node *stack[25];

int top=-1;

void push(struct node *root)
{
  stack[++top] = root;
}

struct node *pop()
{
  return stack[top--];
}

int checkEle(char ele)
{
  switch(ele)
  {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^': return 1;
    default : return 2;
  }
}
    
void varFunc(char ele)
{
  root = (struct node*)malloc(sizeof(struct node));
  root->item = ele;
  root->rchild = NULL;
  root->lchild = NULL;
  push(root);
}

void opFunc(char ele)
{
  root = (struct node*)malloc(sizeof(struct node));
  root->item = ele;
  root->rchild = pop();
  root->lchild = pop();
  push(root);
}

void infix(struct node *root)
{
  if(root->lchild != NULL)
    infix(root->lchild);
  printf("%c", root->item);
  if(root->rchild != NULL)
    infix(root->rchild);
}

void prefix(struct node *root)
{
  printf("%c", root->item);
  if(root->lchild != NULL)prefix(root->lchild);
  if(root->rchild != NULL)prefix(root->rchild);
}

void display()
{
  int x;
  printf("\n\n1. Infix\n2. Prefixi\nEnter your choice: ");
  scanf("%d", &x);

  switch(x)
  {
    case 1: infix(stack[0]);
            break;
    case 2: prefix(stack[0]);
            break;
  }
}

int main()
{ 
  char equ[25];

  printf("\nEnter the postfix equation: ");
  gets(equ);

  printf("\nThe entered equation is: %s", equ);

  int i;
  for(i=0; equ[i]!='\0'; i++)
  {
    switch(checkEle(equ[i]))
    {
      case 1: //printf("\nOperator");
              opFunc(equ[i]);
              break;
      case 2: //printf("\nOperand");
              varFunc(equ[i]);
              break;
      default: printf("\nunknown");
    }
  }

  display(equ);

  return 0;
}

