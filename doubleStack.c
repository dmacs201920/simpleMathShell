		/*
		 * MATH SHELL: Written by Hariharan and Abhiishek S Chugh
					   -173209	-171201		
					   -III B.Sc. Mathematics (Honours)
		*/


#include"functionheader.h"
int top,n;
void Initialize_Stack(double *a)
{
	top=-1;
}
void Push (double *s, double x)
{
	top++;
	if (Isfull()==0)
		s[top]=x;
	else 
		Stackoverflow();
}

double Pop (double *s)
{
	if (Isempty()==0)
		return s[top--];
	else 
		Stackunderflow();
}


double Topvalue(double*s)
{
	if (Isempty()==1)
		return 0;
	else 
		return s[top];
}


/*int Isfull()
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
}*/
