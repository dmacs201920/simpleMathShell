
#include"functionheader.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Initialize_Stack(int *a)
{
	top=-1;
}
void Push (int *s, int x)
{
	top++;
	if (Isfull()==0)
		s[top]=x;
	else 
		Stackoverflow();
}

int Pop (int *s)
{
	if (Isempty()==0)
		return s[top--];
	else 
		Stackunderflow();
}


int Topvalue(int*s)
{
	if (Isempty()==1)
		return 0;
	else 
		return s[top];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Isfull()
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


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int power(int t1,int t2)
{
	int pow=1;
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
int precedence(char *option)
{
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
	int Rank=0,i=0,k=0;
	char **s,**polish,*temp,*current,c;
	char hash[]={'#'};
	char zero[]={'\0'};


	while(*(infix[i++])!='#');

	//s=(char**)malloc(25*(sizeof(char*)));
	if((s=(char**)calloc(25,(sizeof(char*))))==NULL)
	{
		printf("Not enough memory!!!");
		return NULL;
	}
	if((polish=(char**)malloc(i*(sizeof(char*))))==NULL)
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
			polish[k++]=temp;
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
		polish[k++]=temp;
		Rank=Rank+rank(temp);

		if(Rank<1)
		{
			printf("1.Invalid expression\n");
			exit(-1);
		}
	}
	
	free(s);	//Freeing the stack!!!
	
	if(Rank==1)
	{
		polish[k]=hash;
		return(polish);
	}
	else
	{
		printf("2.invalid expression\n");
		exit(-1);
	}
}
int Evaluate_Suffix_Expression(char **s)
{
	if (s==NULL)
		return 0;
	bool truevar=true, falsevar=false;
	register int i=0;
	char *temp;
	register int t1,t2,t3;
	int *stack;
	if((stack=(int*)malloc(50*sizeof(int)))==NULL)
	{
		printf("Not enough memory!!!\n");
		exit(-1);
	}
	Initialize_Stack(stack);

	while(*s[i]!='#')
	{
		temp=s[i];

		if (isdigit(*temp))
		{
			t3=strtof(temp,NULL);
			Push(stack,t3);
		}
		else
		{
			t1=Pop(stack);
			t2=Pop(stack);
			switch(*temp)
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
		i++;

	}
	register int result=stack[0];
	free(stack);
	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int check_function_call(char **s)
{
	char t[]={'+','-','*','/','%','(',')','>','<'};
	int i=check_for_inbuilt_commands(s[0]);
	if (i)
		return 1;
	if (strcmp(s[0],"dir")==0)
		return 2;
	if (strcmp(s[0],"all")==0)
		if (strcmp(s[2],"variables")==0)
			return 4;
	if (s[1]&&*s[1]=='=')
		if (48<=(*s[2])&&(*s[2])<=56)
			return 3;
	if (strcmp(s[0],"exit")==0||strcmp(s[0],"quit")==0)
		return 0;
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


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char** tokenizer(char *s)
{
	char **t;
	int i,l=strlen(s),k=1,j,word=0;

	for(j=0;j<l;j++)
	{
		if(s[j]==' ')
			word++;
	}
	word++;

	t=calloc(word,sizeof(char*));
	t[0]=s;

	for(i=0;i<l;i++)
	{
		if(s[i]==' ')
		{
			s[i]='\0';
			t[k++]=s+i+1;
		}
	}
	return t;
}

int check_for_inbuilt_commands(char *a)//function command "vi -O -y main.c functions.c"
{
	char s[][16]={"vi","dir","alias","mkdir","grep","cd","cp","cat","wc","gdb","gcc","rm","make","chmod","ls","./","quit","exit"};
	for (int i=0;i<16;i++)
		if (strncmp(s[i],a,strlen(s[i]))==0)
			return 1;
	return 0;
}


char** tokenizer_for_all(char *a)
{
	int l=strlen(a),k=0,count=0;

	if (check_for_inbuilt_commands(a))
		return tokenizer(a);

	for (int i=0;i<l;i++)
		if ((!isalnum(a[i])&&(a[i]!='.'))||a[i]==' '||a[i]=='\n'||a[i]=='\t')
			count++;

	char *s=malloc(l+(2*count+1)+2);

	for (int i=0;i<l;i++)
	{
		if ((!isalnum(a[i])&&(a[i]!='.'))||a[i]==' '||a[i]=='\n'||a[i]=='\t')
		{
			s[k++]='\0';
			s[k++]=a[i];
			s[k++]='\0';
		}
		else 
		{	
			s[k++]=a[i];
		}
	}

	s[k++]='\0';
	s[k++]='#';
	s[k++]='\0';

	char **t=(char**)calloc(2*count+2,sizeof(char*));
	k=1;
	t[0]=s;
	for(int i=0;k<(2*count+2);i++)
		if (s[i]=='\0')
			t[k++]=(s+i+1);

	int numb=0;

	for(int i=0;i<(2*count+2);i++)
	{
		if(*(t[i])=='\0')
		{
			numb++;
			char c=t[i+1][1];
			t[i+1][1]=t[i+1][0];
			t[i+1][0]=c;

			t[i+2]=&(t[i+1][1]);
			for(int j=0;(i+j)<2*count;j++)
				t[i+j]=t[i+j+2];

		}
	}

	char **w=calloc(((2*count+2)-(2*numb)),sizeof(char *));

	for (int i=0;i<(2*count+2)-(2*numb);i++)
	{
		w[i]=(char*)calloc(strlen(t[i]),sizeof(char));
		strcpy(w[i],t[i]);
	}
	return w;
}


void freeTokenizer(char **t)
{
	int i=0;
	while(t[i])
		free(t[i++]);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


;

dyna_var* dynamicallydeclare(dyna_var *head,char *x,char *value)
{
	dyna_var *t=head,*temp=(dyna_var *)calloc(1,sizeof(dyna_var));
	
	if (!((65<=*x&&*x<=90)||(97<=*x&&*x<=122)))
	{
		printf("Enter only characters for defining variables!\nVariable: %s not defined\n",x);
		exit(-1);
	}
	
	int l=strlen(x),m=strlen(value);

	temp->var=malloc(l);
	temp->value=malloc(m);
	strcpy(temp->var,x);
	strcpy(temp->value,value);
	
	temp->next=NULL;
	if (head==NULL)
		return temp;
	else 
	{
		temp->next=head;
		return temp;
	}


}

int operations(dyna_var *head,char **s)
{
	dyna_var *temp;
	register int t1,t2,t3;
	int *stack;
	bool truevar=true, falsevar=false;
	if((stack=(int*)malloc(15*sizeof(int)))==NULL)
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
				t3=strtof(temp->value,NULL);
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
	register int result=stack[0];
	free(stack);
	return result;
}


dyna_var* callDynaVariable(dyna_var*head,char *x)
{
	if (head==NULL)
	{
		printf("Undefined Variable\n");
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
	if (temp==NULL)
	{
		printf("Variable: %s not found\n",x);
		exit(-1);
	}
	else
		return temp;
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


