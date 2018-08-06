#include<stdio.h>
#include<stdlib.h>

typedef struct _Stack
{
 int op;
 struct _Stack *next;
}Stack;

typedef struct
{
 char op;
 int val;
}SymbolTable;

Stack *makeNode(char);
Stack *push(Stack*,char);
Stack *pop(Stack*);

int isOperator(char op);
int isHigh(char,Stack*);
char *postFix(char*);

int evaluate(char*); 

void main()
{
 char ifx[100];
 int p;

 printf("Enter the Expression : ");
 gets(ifx);

 p=evaluate(ifx);
 printf("Value of Expression  : %d",p);
 
}
Stack *makeNode(char n)
{
 Stack *nd;

 nd=(Stack*)malloc(sizeof(Stack));
 nd->op=n;
 nd->next='\0';
}

Stack *push(Stack *top,char c)
{
 Stack *nd=makeNode(c);

 nd->next=top;
 return nd;
}

int isOperator(char op)
{
 return op=='+'||op=='-'||op=='*'||op=='/'||op=='('||op==')';
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

int isHigh(char op,Stack *top)
{
 if(top=='\0'||op=='('||top->op=='(')
  return 1;

 if((op=='*'||op=='/')&&(top->op=='+'||top->op=='-'))
  return 1;

 return 0;
}

char *postFix(char *ifx)
{
 char *pfx,x;
 Stack *top='\0';
 int i;
 
 for(i=0;ifx[i];i++);
 pfx=(char*)malloc(i+1);

 i=0;
 while(*ifx)
 {
  x=*ifx++;
 
  if(!isOperator(x))
   pfx[i++]=x;
  else
  {
   if(isHigh(x,top))
    top=push(top,x);
   else
   {
    if(x==')')
    {
     while(top->op!='(')
     {
      pfx[i++]=top->op;
      top=pop(top);
     }
     top=pop(top);
    }
    else
    {
     while(top&&!isHigh(x,top))
     {
      pfx[i++]=top->op;
      top=pop(top);
     }
     top=push(top,x);
    }
   }
  }
 }

 while(top)
 {
  pfx[i++]=top->op;
  top=pop(top);
 }
 pfx[i]='\0';
 return pfx;
}

int evaluate(char *ifx)
{
 char *pfx;
 int i,j,n,right,left;
 SymbolTable st[10];
 Stack *top='\0';

 pfx=postFix(ifx);

 printf("\n");
 for(i=n=0;pfx[i];i++)
 {
  if(!isOperator(pfx[i]))
  {
   for(j=0;j<n&&st[j].op!=pfx[i];j++);
   if(j==n)
   {
    st[n].op=pfx[i];

    printf("Enter Value of %c     : ",pfx[i]);
    scanf("%d",&st[n++].val);
   }
  }
 }

 for(i=0;pfx[i];i++)
 {
  if(isOperator(pfx[i]))
  {
   right=top->op;
   top=pop(top);
   left=top->op;
   top=pop(top);

   switch(pfx[i])
   {
    case '+' : top=push(top,left+right);
               break; 
    case '-' : top=push(top,left-right);
               break;
    case '*' : top=push(top,left*right);
               break;
    case '/' : top=push(top,left/right);
   }
  }
  else
  {
   for(j=0;j<n&&st[j].op!=pfx[i];j++);

   top=push(top,st[j].val);
  }
 }
 return top->op;
}
