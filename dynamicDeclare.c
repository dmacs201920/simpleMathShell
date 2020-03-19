		/*
		 * MATH SHELL: Written by Hariharan and Abhiishek S Chugh
					   -173209	-171201		
					   -III B.Sc. Mathematics (Honours)
		*/
#include"functionheader.h"

dyna_var* dynamicallydeclare(dyna_var *head,char *x,char *value)
{
	dyna_var *t=head,*temp=(dyna_var *)calloc(1,sizeof(dyna_var)),*temp1;
	int l=strlen(x),m=strlen(value);
	if (!((65<=*x&&*x<=90)||(97<=*x&&*x<=122)))
	{
		printf("Enter only characters for defining variables!\nVariable: %s not defined\n",x);
		exit(-1);
	}

	if ((temp1=findDynaVariable(head,x))!=NULL)
	{
		temp1->value=realloc(temp1->value,m);
		strcpy(temp1->value,value);
		return head;
	}
	else
	{
		temp->var=malloc(l);
		temp->value=malloc(m);
		strcpy(temp->var,x);
		strcpy(temp->value,value);
		temp->prev=NULL;
		temp->next=NULL;
		if (head==NULL)
			return temp;
		else 
		{
			temp->next=head;
			head->prev=temp;
			return temp;
		}
	}

}

double operations(dyna_var *head,char **s)
{
	dyna_var *temp;
	register double t1,t2,t3;
	double *stack;
	bool truevar=true, falsevar=false;
	if((stack=(double*)malloc(15*sizeof(double)))==NULL)
	{
		printf("Not enough memory!!!\n");
		exit(-1);
	}
	Initialize_Stack(stack);
	
	for (int i=0;*s[i]!='#';i++)
	{
		register char *x=s[i];
		if (isalpha(*x))
		{
			if ((temp=findDynaVariable(head,x))!=NULL)
			{
				t3=atof(temp->value);
				Push(stack,t3);
			}
		}
		else
		{
			t1=Pop(stack);
			t2=Pop(stack);
			switch(*x)
			{
				case '+':
					Push(stack,t1+t2);
					break;
				case '-':
					Push(stack,t2-t1);
					break;
				case '*':
					Push(stack,t1*t2);
					break;
				case '/':
					if (t1==0)
					{
						printf("Division by zero!!!\n");
						exit(-1);
					}
					else
						Push(stack,t2/t1);
					break;
				case '^':
					Push(stack,power(t2,t1));
					break;
				case '%':
					if (t1==0)
					{
						printf("Undefined operation!\n");
						exit(-1);
					}
					else
						Push(stack,(int)t2%(int)t1);
					break;
				case '=':
					if (t1==t2)
						Push(stack,truevar);
					else 
						Push(stack,falsevar);
					break;
				case '<':
					if (t1>t2)
						Push(stack,truevar);
					else 
						Push(stack,falsevar);
					break;
				case'>':
					if (t1<t2)
						Push(stack,truevar);
					else
						Push(stack,falsevar);
					break;
				default:
					printf("Variable: '%s' not supported .\nError 102\n",x);
					exit(-1);
					break;
			}
		}
	}
	register double result=stack[0];
	free(stack);
	return result;
}


dyna_var* callDynaVariable(dyna_var*head,char *x)
{
	if (head==NULL)
	{
		printf("No variables defined!!!\n");
		return NULL;
	}

	else 
		return findDynaVariable(head,x);
		
}

dyna_var* findDynaVariable(dyna_var *head,char *x)
{
	dyna_var *temp=head;
	while(temp && strcmp(temp->var,x)!=0)
		temp=temp->next;
	if (temp!=NULL)
		return temp;
	else
		return NULL;
	
}

void free_dyna_variables(dyna_var *head)
{
	dyna_var *t=head;
	while(head!=NULL)
	{
		head=head->next;
		free(t);
		t=head;
	}
		
}

void display_dynamically_declared(dyna_var *head)
{

	if (head==NULL)
		exit(-1);
	dyna_var *temp=head;

	while(temp!=NULL)
	{
		printf("%s=%s\n",temp->var,temp->value);	
		temp=temp->next;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
