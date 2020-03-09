#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int top=-1;
void push (float *s, float x)
{
	top++;
	if (isfull()==0)
		s[top]=x;
	else 
		stackoverflow();
}


float pop (float *s)
{
	if (isempty()==0)
		return s[top--];
	else 
		stackunderflow();
}

float topvalue(float *s)
{
	if (isempty()==1)
		return 0;
	else 
		return s[top];
}

int isfull()
{
	if(top==n-1)
		return 1;
	else 
		return 0;
}


int isempty()
{
	if (top==-1)
		return 1;
	else 
		return 0;
}


void stackoverflow()
{
	printf("Stack is overflowing!!!\n");
}


void stackunderflow()
{
	printf("Stack is empty!!!\n");
}
