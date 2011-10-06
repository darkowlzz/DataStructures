#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 50

char infix[max], postfix[max];
int stack[max], top;



void push(char a)
{
  if(top > max)
  {
    printf("\nStack overflow");
    exit(0);
  }
  else
  {
    top+=1;
    stack[top] = a;
  }
}

int pop()
{
  if(top == -1)
  {
    printf("\nStack underflow");
    exit(0);
  }
  else
    return (stack[top--]);
}

int pre(char sym)
{
  switch(sym)
  {
    case '(': return 0;
              break;
    case '+':
    case '-': return 1;
              break;
    case '*':
    case '/':
    case '%': return 2;
              break;
    case '^': return 3;
  }
}


int white_space(char sym)
{
  if(sym == ' ' || sym == '\t' || sym == '\0')
    return 1;
  else
    return 0;
}

void infix2postfix()
{
  int i, len, precedence, p=0;
  char next;

  stack[top] = '#';
  len = strlen(infix);
  infix[len] = '#';
  for( i=0; infix[i]!='#'; i++)
  {
    if(!white_space(infix[i]))
    {
      switch(infix[i])
      {
        case '(': push(infix[i]);
                  break;
        case ')': while((next=pop())!='(')
                    postfix[p++] = next;
                  break;
        case '+': 
        case '-':
        case '*':
        case '/':
        case '%':
        case '^': precedence = pre(infix[i]);
                  while(stack[top]!='#' && precedence == pre(stack[top]))
                    postfix[p++] = pop();
                  push(infix[i]);
                  break;
        default: postfix[p++] = infix[i];
       }
    } 
  }

  while(stack[top]!='#')
    postfix[p++] = pop();
  postfix[p]='\0';

}

int main()
{
  top = 0;
  printf("\nEnter infix expression: ");
  fflush(stdin);
  gets(infix);

  infix2postfix();
  printf("\nPostfix: %s\n", postfix);

  return 0;
}

