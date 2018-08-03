#include<stdio.h>
#include<stdlib.h>

typedef struct _Stack
{
 char bkt;
 struct _Stack *next;
}Stack;

Stack *push(Stack *top,char bkt)
{
 Stack *nd=(Stack*)malloc(sizeof(Stack));
 nd->bkt=bkt;
 nd->next=top;
 return nd;
}

Stack *pop(Stack *top)
{
 if(top)
 {
  Stack *tmp=top;
  top=top->next;
  free(tmp);
 }
 return top;
}

int isBkt(char bkt)
{
 if(bkt=='('||bkt=='['||bkt=='{')
  return 1;
 
 if(bkt==')'||bkt==']'||bkt=='}')
  return 2;

 return 0;
}

int chkbal(char *exp)
{
 Stack *top='\0';
 int i,x;

 for(i=0;exp[i];i++)
 {
  switch(isBkt(exp[i]))
  {
   case 1 : top=push(top,exp[i]);
            break;
   case 2 : if(!top||!(exp[i]-top->bkt==1||exp[i]-top->bkt==2))
             return 0;
            top=pop(top);
  }
 }
 
 if(top||exp[i])
  return 0;

 return 1;
}

void main()
{
 char str[200];
 
 printf("\nEnter an Expression : ");
 gets(str);

 if(chkbal(str))
  printf("\nExpression is Balanced..\n");
 else
  printf("\nExpression Not Balanced..\n");
}

