// INFIX TO POSTFIX conversion with rank method

#include <stdio.h>
#include<string.h>
#include<ctype.h>  //for isdigit()

#define MAX 100
int top=-1;
char st[MAX];
char ch;
int k=0;

void push_back(char c);
char pop_back(void);
int empty_condition(void);
int full_condition(void);

int full_condition()
{
	if(top==MAX-1)
	{
    	return 1;
	}
	else
	{
    	return 0;
	}
}

int empty_condition()
{
	if(top==-1)
	{
    	return 1;
	}
	else
	{
    	return 0;
	}
}

void push(char ch)
{
	if(full_condition())
	{
    	printf("stack is full");
    	return;
	}
 
	top=top+1;
	st[top]=ch;
}

char pop()
{
	if(empty_condition())
	{
    	printf("stack is empty");
    	return 0;
	}
	ch=st[top];
	top=top-1;
	return ch;
}

int isoperator(char s)
{
	if(s=='^' || s=='*' || s=='/' || s=='+' || s=='-')
	return 1;
	else
	return 0;
}
int pre(char s)
{
	if(s=='^')
	return 3;
	else if(s=='*' || s=='/')
	return 2;
	else if(s=='+' || s=='-')
	return 1;
	else
	return 0;
}

int check(char a, char b)
{
	if(a=='^' && b=='^')
	return 1;
	else
	return 0;
}
int main()
{
	char in[MAX],post[MAX]="";
	printf("Enter Infix String\n");
	scanf("%s",in);
    
	int i,j;
	char ch,x;
	push('(');
	i=0;j=0;
	strcat(in,")");
	ch=in[i];
	while(ch!='\0')
	{
    	if(ch=='(')
    	push(ch);
    	else if( isdigit(ch) || isalpha(ch))
    	{
        	post[j]=ch;
        	j++;
    	}
    	else if( isoperator(ch)==1)
    	{
        	x=pop();
        	while(pre(ch)<=pre(x) && isoperator(x)==1 && check(x,ch)==0){
            	post[j]=x;
            	j++;
            	x=pop();
        	}
        	push(x);
        	push(ch);
    	}
    	else if(ch==')')
    	{
        	x=pop();
        	while(x!='(')
        	{
            	post[j]=x;
            	j++;
            	x=pop();
        	}
    	}
    	else
    	{  //if non of above codition occur//
   		 printf("\nInvalid infix Expression.\n");   	 
   		 getchar();
   		 break;
   	 }
   	 printf("%c  	%s  	%s\n",ch,st,post);
   	 
   	 i++;
   	 ch=in[i];
	}
   	  post[j] = '\0';
    
	printf("\nPostfix String is ");
	puts(post);
    
}