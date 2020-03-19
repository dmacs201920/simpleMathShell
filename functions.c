		/*
		 * MATH SHELL: Written by Hariharan and Abhiishek S Chugh
					   -173209	-171201		
					   -III B.Sc. Mathematics (Honours)
		*/
#include"functionheader.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double power(double t1,double t2)
{
	double pow=1;
	for(int i=0;i<t2;i++)
		pow*=t1;
	return pow;
}

char* check_for_pipes(char **s)
{
	char *t;
	t=strstr(*s,"|");
	return t;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double Evaluate_Suffix_Expression(char **s)
{
	if (s==NULL)
		return 0;
	bool truevar=true, falsevar=false;
	register int i=0;
	register double t1,t2,t3;
	double *stack;
	if((stack=(double*)malloc(50*sizeof(double)))==NULL)
	{
		printf("Not enough memory!!!\n");
		exit(-1);
	}
	Initialize_Stack(stack);

	for (int i=0;*s[i]!='#';i++)
	{

		if (isdigit(*s[i])||( (s[i][0]=='-') && (isdigit(s[i][1]) )))
		{
			t3=atof(s[i]);
			Push(stack,(double)t3);
		}
		else if (*s[i]=='+'||*s[i]=='-'||*s[i]=='*'||*s[i]=='/'||*s[i]=='<'||*s[i]=='>'||*s[i]=='%'||*s[i]=='=')
		{
			t1=Pop(stack);
			t2=Pop(stack);
			if((s[i][0]=='-') && (isdigit(s[i][1])) )
				Push(stack,t2-t1);
			else
			{
				switch(*s[i])
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
							Push(stack,(int)t2 %(int)t1);
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
						printf("Operation not supported.\n");
						exit(-1);
						break;
				}
			}
		}

	}
	register double result=stack[0];
	free(stack);
	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int check_function_call(char **s)
{
	char t[]={'+','-','*','/','%','(',')','>','<'};
	int i=check_for_inbuilt_commands(s[0]);
	if ((strcmp(s[0],"exit")==0)||(strcmp(s[0],"quit")==0))
		return 0;
	if (strcmp(s[0],"all")==0)
		if (strcmp(s[1],"variables")==0)
			return 4;
	if (i)
		return 1;
	if (strcmp(s[0],"dir")==0)
		return 2;
	
	if (s[1]&&*s[1]=='=')
		if (48<=(*s[2])&&(*s[2])<=56)
			return 3;
	
	if (48<=(*s[0])&&(*s[0])<=57)
		return 6;
	if ((95<=(*s[0])&&(*s[0]<=122))||(65<=(*s[0])&&(*s[0])<=90))
	{
		for(int i=0; i<9;i++)
			if (*s[1]==t[i])
				if ((95<=(*s[0])&&(*s[0]<=122))||(65<=(*s[0])&&(*s[0])<=90))
					return 8;
				
	}
	if (strcmp(s[0],"cwd")==0)
		return 7;
	return 1;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int input_precedence(char *option)
{
	switch(*option)
	{
		case '+' :
			return 2;
			break;
		case '-':
			return 2;
			break;
		case '*':
			return 4;
			break;
		case '/':
			return 4;
			break;
		case'^':
			return 7;
			break;
		case '(':
			return 10;
			break;
		case ')':
			return 1;
			break;

		default:
			return 8;
			break;
	}
}
int stack_precedence(char *option)
{
	switch(*option)
    {

	case '+' :
	    return 3;
	    break;
	case '-':
	    return 3;
	    break;
	case '*':
	    return 5;
	    break;
	case '/':
	    return 5;
	    break;
	case'^':
	    return 6;
	    break;
	case '(':
	    return 1;
	    break;
	case ')':
	    return 0;
	    break;
	default:
	    return 9;
	    break;

    }
}

int rank_para(char* value)
{
    switch(*value)
    {
	case '+' :
	    return -1;
	    break;
	case '-':
	    return -1;
	    break;
	case '*':
	    return -1;
	    break;
	case '/':
	    return -1;
	    break;
	case'^':
	    return -1;
	    break;
	case')':
	    return 0;
	    break;
	case'(':
	    return 0;
	    break;
	default:
	    return 1;
	    break;

    }
}


/*char** Paranthised_infix_to_Suffix(char** infix)
{

	int Rank=0,i=0,j=0,garbage,k=0;
	char *s,*polish,*temp,*current,c;
	char brac[]={'('};
	while(*(infix[i++])!='#');
	
	*infix[i-1]=')';
	*infix[i]='#';


	s=(char**)malloc(100*sizeof(char*));
	polish=(char*)malloc(i*sizeof(char*));
	

	Initialize_Stack_c(s);

	Push_c(s,brac);
	i=0;
	current=((infix[i]));
	i++;

	while(*current!='\0')
	{
		if(*s==NULL)
		{
			printf("1.Invalid expression\n");
			exit(0);
		}
		while((input_precedence(current))<(stack_precedence(Topvalue(s))))
		{
			temp=Pop_c(s);
			polish[++k]=temp;
			Rank=Rank+rank_para(temp);

			if(Rank<1)
			{
				printf("2.Invalid expression\n");
				exit(1);
			}
		}

		if((input_precedence(current))!=(stack_precedence(Topvalue(s))))
			Push_c(s,current);
		else
			Pop_c(s);


		current=((infix[i]));
		i++;
	}

	if(Isempty()==0|| Rank!=1)
	{
		printf("\n3.invalid expression\n");
		exit(3);
	}
	else
	{
		free(s);
		return polish;
	}
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*char* history_call(dll* head,FILE **fp)
{
	char *s;
	if((*s=(char*)malloc((head->prev->fp_size)*sizeof(char)))==NULL)
	{
		printf("Not enought memory available!!\n");
		return NULL;
	}
	FILE *fp_temp=*fp;
	fseek(fp_temp,head->prev->fp_position,0);
	fread(s,head->prev->fp_size,1,fp_temp);
	return s;
}*/


