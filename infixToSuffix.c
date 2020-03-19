		/*
		 * MATH SHELL: Written by Hariharan and Abhiishek S Chugh
					   -173209	-171201		
					   -III B.Sc. Mathematics (Honours)
		*/
#include"functionheader.h"


int precedence(char *option)
{
	if((option[0]=='-') && (isdigit(option[1])) )
		return 5;
	switch(*option)
	{
		case '=':
			return 1;
			break;
		case '<':
			return 1;
			break;
		case '>':
			return 1;
			break;
		case '+' :
			return 2;
			break;
		case '-':
			return 2;
			break;
		case '*':
			return 3;
			break;
		case '%':
			return 3;
			break;
		case '/':
			return 3;
			break;
		case '^':
			return 4;
			break;
		case '#':
			return 0;
			break;
		default:
			return 5;
			break;
	}
}

int rank(char *value)
{
	if((value[0]=='-') && (isdigit(value[1])) )
	return 1;
	switch(*value)
	{
		case '=':
			return -1;
			break;
		case '<':
			return -1;
			break;
		case'>':
			return -1;
			break;
		case '+':
			return -1;
			break;
		case '-':
			return -1;
			break;
		case '*':
			return -1;
			break;
		case '%':
			return -1;
			break;
		case '/':
			return -1;
			break;
		case '^':
			return -1;
			break;
		default:
			return 1;
			break;
	}
}
char** Infix_to_Suffix(char** infix)
{
	int Rank=0,i=0,k=0,j=0;
	char **s,**polish,*temp,*current,c;
	char hash[]="#\0";
	char zero[]={'\0'};


	while(*(infix[j++])!='#');

	if((s=(char**)calloc(25,(sizeof(char*))))==NULL)
	{
		printf("Not enough memory!!!");
		return NULL;
	}
	if((polish=(char**)malloc(j*(sizeof(char*))))==NULL)
	{
		printf("Not enough memory!!!");
		exit(-1);
	}
	i=0;

	Initialize_Stack_c(s);


	Push_c(s,hash);
	current=((infix[i++]));


	while(*current!=*hash)
	{
		if(s==NULL)
		{
			printf("Invalid expression\n");
			exit(-1);
		}
		while(precedence(current)<(precedence(Topvalue_c(s))))
		{
			temp=Pop_c(s);
			polish[k]=malloc(strlen(temp));
			strcpy(polish[k++],temp);
			Rank=Rank+rank(temp);
			if(Rank<1)
			{
				printf("Invalid expression\n");
				exit(-1);
			}
		}
		Push_c(s,current);
		current=((infix[i++]));
	}

	while(*(Topvalue_c(s))!=*hash)
	{
		temp=Pop_c(s);
		polish[k]=malloc(strlen(temp));
		strcpy(polish[k++],temp);
		Rank=Rank+rank(temp);

		if(Rank<1)
		{
			printf("1.Invalid expression\n");
			exit(-1);
		}
	}
	
	free(s);
	for (i=0;i<j;i++)
		free(infix[i]);//Freeing the stack!!!
	
	if(Rank==1)
	{
		polish[k]=malloc(strlen(hash));
		strcpy(polish[k],hash);
		return(polish);
		
	}
	else
	{
		printf("2.invalid expression\n");
		exit(-1);
	}
}

