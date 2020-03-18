#include"functionheader.h"
int top,n;
void Initialize_Stack_c(char **a)
{
	top=-1;
}
void Push_c(char **s, char *x)
{
	top++;
	if (Isfull()==0)
		s[top]=x;
	else 
		Stackoverflow();
}

char* Pop_c(char **s)
{
	if (Isempty()==0)
		return s[top--];
	else 
		Stackunderflow();
}

char* Topvalue_c(char**s)
{
	if (Isempty()==1)
		return 0;
	else 
		return s[top];
}int Isfull()
{
	if(top==n-1)
		return 1;
	else 
		return 0;
}


int Isempty()
{
	if (top==-1)
		return 1;
	else 
		return 0;
}


void Stackoverflow()
{
	printf("Stack is overflowing!!!\n");
}


void Stackunderflow()
{
	printf("Stack is empty!!!\n");
}
