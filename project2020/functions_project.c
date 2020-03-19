#include"header.h"

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

char* Topvalue_c(char **s)
{
    if (Isempty()==1)
	return 0;
    else 
	return s[top];
}



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


int Topvalue(int *s)
{
    if (Isempty()==1)
	return 0;
    else 
	return s[top];
}

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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  trim(char  *a)
{
    int i,l,L;

    l=strlen(a);


    for(i=0;i<l;i++)
    {
	if(a[i]==' ')
	{
	    a[i]=a[i+1];
	    a[i+1]=' ';
	}

    }

    for (i=0;a[i]==' ';i++);  // Starting spaces //
    strcpy(a,a+i);

    l=strlen(a);

    for (i=l-1;a[i]==' ';--i);  // Ending spaces //
    a[(i+1)]='\0';

    l=strlen(a);

    char *q,*p;

    for(int j=1,k;j<l-1;j++)
    {
	if(a[j]==' ')
	{ 
	    for(k=j;a[k]==' ';k++);
	    if(k==1)
		continue;
	}
	else
	    continue;


	p=a+j;
	q=a+k;

	while(1)
	{
	    *p=*q;
	    if(*p=='\0')
		break;
	    ++p;
	    ++q;
	}
    }
    printf("trimed :%s\n",a);
}


/*
   char** tokenizer(char *s)//ls -l
   {
   int word1;
//char **temp;
int i,l=strlen(s),k=1,j;

for(j=0;j<l;j++)
{
if(s[j]==' ')
word1++;
}
word1++;

//temp=calloc(word1,sizeof(char*));
char **temp=(char**)calloc(word1,sizeof(char*));
temp[0]=s;

for(i=0;i<l;i++)
{
if(s[i]==' ')
{
s[i]='\0';
temp[k++]=s+i+1;
printf("%s",temp[k]);
}
}
return temp;

free(temp);


}
*//*
     char** tokenizer_for_all(char *a)
     {
     int l=strlen(a),k=0,count=0,flag=0;

     if(isdigit(a[0]))
     {
     for(int i=0;i<l;i++)
     {
     if(a[i]=='('||a[i]==')')
     {
     flag=1;
     break;
     }
     }
     if(flag==0)
     {
     a[l]='#';
     a[l+1]='\0';
     }
     if(flag==1)
     {
     a[l]=')';
     a[l+1]='\0';
     }
     }

     l=strlen(a);
     for(int i=0;i<l;i++)
     if(!isalnum(a[i]) ||a[i]==' ' ||a[i]=='\n'|| a[i]=='\t')
     count++;


     char *s=(char*)calloc((l+(2*count)),sizeof(char));
     int j=l+(2*count);
     int tok_cnt=0;
     int dig_cnt=0,max=0;


     for(int i=0;i<=l;i++)
     {
     if(!isalnum(a[i]) || a[i]==' '||a[i]=='\t'||a[i]=='\n'||a[i]!='\000')
     {
     s[k++]='\0';
     s[k++]=a[i];
     s[k++]='\0';
     tok_cnt+=2;
     }
     else
     {
     dig_cnt=0;
     s[k++]=a[i];
     dig_cnt++;
     if(dig_cnt>max)
     max=dig_cnt;
     }

     }

     char **tokened;
//   tokened=(char**)calloc((tok_cnt),sizeof(char*));


for(int o=0;o<(tok_cnt);o++)
{
//tokened[o]=calloc((dig_cnt),sizeof(char));
tokened[o]=s+(2*o);
}






k=0;
temp[0]=s;
for(int i=0;i<j;i++)
if(s[i]=='\0')
temp[++k]=(s+i+1);

return tokened;
}

    */
int match(char *A,char* B)
{	
    int L,l;

    L=strlen(A);
    l=strlen(B);

    for(int i=0,j;i<L;i++)
    {
	for(j=0;j<l;j++)
	    if(A[i+j]!=B[j])
		break;

	if (j==l)
	    return i+1;
    }
    return -1;	
}


void remove_word(char *str1, char *str2)
{
    int i,l,L;
    L=strlen(str1);
    l=strlen(str2);
    char *p,*q;

    while((i=match(str1,str2))!=-1)
    {
	p=str1+i-1;
	q=str1+i+l-1;
	while(1)
	{
	    *p=*q;
	    if (*p=='\0')
		break;
	    ++p;
	    ++q;
	}
    }
    printf("%s\n",str1);
}


int search(char *str1,char x)
{
    int i;

    for(i=0;str1[i]!='\0';i++)
    {
	if(str1[i]==x)
	    return i;
    }
    return -1;
}


char** tokenizer_for_all(char *a)
{

    int l=strlen(a),k=0,count=0,flag=0,coun=0,c,p=0,count1=0,count2=0,x;
    char *s,*a1,*open_brac,**tokened;

    open_brac=malloc(sizeof(char));
    open_brac[0]=')';



    //	if (check_for_inbuilt_commands(a))
    //		return tokenizer(a);
    //
    //

    trim(a);

    for(int w=0;w<l;w++)
    {
	if((a[w]=='(') || (a[w]==')'))
	{   flag=1;
	break;
	}
    }    

    for (int i=0;i<l;i++)
    {
	if (((!isalnum(a[i]))&&((a[i])!='.'))||a[i]==' '||a[i]=='\n'||a[i]=='\t')
	    count++;
	if((a[i]==')') || (a[i]=='('))
	    coun++;
    }

    if(flag==0)
    {
	s=malloc(l+(2*count+1)+2);

	for (int i=0;i<l;i++)
	{
	    if (((!isalnum(a[i]))&&((a[i])!='.')||((!isalnum(a[i])&&(a[i])!='('))||((!isalnum(a[i]))&&(a[i])!=')'))||a[i]==' '||a[i]=='\n'||a[i]=='\t')
	    {
		s[k++]='\0';
		s[k++]=a[i];
		s[k++]='\0';
	    }
	    else
		s[k++]=a[i];
	}

	s[k++]='\0';
	s[k++]='#';
	s[k++]='\0';

	tokened=(char**)calloc(2*count+2,sizeof(char*));
	k=1;
	if (s[0]=='\0')
	    tokened[0]=&s[1];
	else
	    tokened[0]=s;
	for(int i=0;k<(2*count+2);i++)
	    if (s[i]=='\0')
		tokened[k++]=(s+i+1);
    }







    if(flag==1)
    {
	s=malloc(l+(2*(count-coun))+coun+3);
	for (int i=0;i<l;i++)
	{
	    if (((!isalnum(a[i]))&&((a[i])!='.'))||a[i]==' '||a[i]=='\n'||a[i]=='\t')
		if ((!isalnum(a[i+1]))&&(a[i]+1!='.'))//(a[i+1]=='(')
		{
			s[k++]='\0';
			s[k++]=a[i];
			s[k++]='\0';
			i++;
			s[k++]=a[i];
			s[k++]='\0';
			continue;
		}
		else
		{
		    s[k++]='\0';
		    s[k++]=a[i];
		    s[k++]='\0';
		}
	    /*else if(a[i]=='(')
	    {
		s[k++]=a[i];
		s[k++]='\0';
	    }*/
	    else if(a[i]==')')
	    {
		s[k++]='\0';
		s[k++]=a[i];
	    }
	    else
		s[k++]=a[i];
	}
	s[k++]='\0';
	s[k++]='#';
	s[k++]='\0';

	tokened=(char**)calloc(((2*(count-coun))+coun+2),sizeof(char*));
	k=1;
	if (s[0]=='\0')
	    tokened[0]=&s[1];
	else
	    tokened[0]=s;
	for(int i=0;k<(2*count+2);i++)
	    if (s[i]=='\0')
		tokened[k++]=(s+i+1);

    }



    int numb=0;


    char **t=calloc((((2*(count-coun))+coun+2)-(2*numb)),sizeof(char *));

    for (int i=0;i<((((2*(count-coun))+coun+2))-(2*numb));i++)
    {
	t[i]=(char*)calloc((strlen(tokened[i])),sizeof(char));
	strcpy(t[i],tokened[i]);
    }


	size1=((2*(count-coun))+coun+2)-(2*numb);

    return t;
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// relation //




int precedence(char* option)
{
    if((option[0]=='-') && (isdigit(option[1])) )
	return 5;
    switch(*option)
    {
	case '=' :
	    return 1;
	    break;
	case '<' :
	    return 1;
	    break;
	case '>' :
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

int rank(char* value)
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
	case '>':
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
	case '^':
	    return -1;
	    break;
	case '%':
	    return -1;
	    break;
	case '/':
	    return -1;
	    break;
	default:
	    return 1;
	    break;
    }
}


char** Infix_to_Suffix(char** infix)
{
    int Rank=0,i=0,k=0,size;
    char *temp1,*current;
    char **st,c;
    char hash[]={'#'};
    char zero[]={'\0'};


    while(*(infix[i++])!='#');
    size=i;


    char **polish;
    if((polish=(char**)calloc(size,(sizeof(char*))))==NULL)
    {
	printf("Not enough memory!!!");
	exit(-1);
    }
    if((temp1=(char*)calloc(10,(sizeof(char))))==NULL)
    {
	printf("Not enough memory!!!");
	return NULL;
    }
    if((current=(char*)calloc(10,(sizeof(char))))==NULL)
    {
	printf("Not enough memory!!!");
	return NULL;
    }
    if((st=(char**)calloc(100,(sizeof(char*))))==NULL)
    {
	printf("Not enough memory!!!");
	return NULL;
    }
    i=0;

    Initialize_Stack_c(st);


    Push_c(st,hash);
    current=((infix[i++]));


    while(*current!=*hash)
    {
	if(st==NULL)
	{
	    printf("1.Invalid expression\n");
	    return NULL;
	}
	while(precedence(current)<=(precedence(Topvalue_c(st))))
	{
	    temp1=Pop_c(st);
	    polish[k++]=temp1;
	    Rank=Rank+rank(temp1);
	    if(Rank<1)
	    {
		printf("2.Invalid expression\n");
		return NULL;
	    }
	}
	Push_c(st,current);
	current=((infix[i++]));
    }
    while(*(Topvalue_c(st))!=*hash)
    {
	temp1=Pop_c(st);
	polish[k++]=temp1;
	Rank=Rank+rank(temp1);

	if(Rank<1)
	{
	    printf("3.Invalid expression\n");
	    return NULL;
	}
    }
    free(st);


    if(Rank==1)
    {
	polish[k]=zero;
	return(polish);
	free(polish);
    }
    else
    {
	printf("4.invalid expression\n");
	return NULL;
    }
    free(temp1);
    free(current);
    free(polish);
}






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int input_precedence(char* option1)
{
    //	if((option1[0]=='-') && (isdigit(option1[1])) )
    //	    return 9;
    switch(option1[0])
    {
	/*	    case '=' :
		    return 1;
		    break;
		    case '<' :
		    return 1;
		    break;
		    case '>' :
		    return 1;
		    break;*/
	case '+' :
	    return 1;
	    break;
	case '-':
	    return 1;
	    break;
	case '*':
	    return 3;
	    break;
	case '/':
	    return 3;
	    break;
	case '%':
	    return 3;
	    break;
	case'^':
	    return 6;
	    break;
	case '(':
	    return 9;
	    break;
	//case '#':
	//    return 9;
	//    break;
	case ')':
	    return 0;
	    break;
	default:
	    return 7;
	}
}

/*

   int precedence(char* option)
   {
   if((option[0]=='-') && (isdigit(option[1])) )
   return 5;
   switch(*option)
   {
   case '=' :
   return 1;
   break;
   case '<' :
   return 1;
   break;
   case '>' :
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

   int rank(char* value)
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
   case '>':
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
   case '^':
   return -1;
   break;
case '%':
return -1;
break;
case '/':
return -1;
break;
default:
return 1;
break;
}


    */
int stack_precedence(char* option)
{
    //    if((option[0]=='-') && (isdigit(option[1])) )
    //	return 10;
    switch(option[0])
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
	case '%':
	    return 4;
	    break;
	case '/':
	    return 4;
	    break;
	case'^':
	    return 5;
	    break;
	case '(':
	    return 0;
	    break;
	//case '#':
	//    return 0;
	//    break;
	default:
	    return 8;
	    break;

    }
}

int rank_para(char* value)
{
    switch(value[0])
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
	case '%':
	    return -1;
	    break;
	case'^':
	    return -1;
	    break;
	default:
	    return 1;
	    break;

    }
}

char** Paranthised_infix_to_Suffix(char** infix)
{
    int Rank=0,i=0,j=0,k=0,size;
    char *temp1,*current;
    char **st,c;
    char hash[]="#\0";
//    char zero[]={'\0'};
    char l_o_b[]="(\0";
    char r_o_b[]=")\0";


    while(*(infix[i++])!='#');
    i++;
    char **infix1=calloc(i,sizeof(char *));
    for (j=0; j<i-2 ;j++)
	{
		infix1[j]=malloc(strlen(infix[j]));
		strcpy(infix1[j],infix[j]);
	}
    infix1[j]=malloc(strlen(r_o_b));
    strcpy(infix1[j++],r_o_b);
    infix1[j]=malloc(strlen(hash));
    strcpy(infix1[j++],hash);
    if (j==i)
	{
	    printf("Infix copied successfully!!!\n");
	    for(int m=0;m<i;m++)
		free(infix[m]);
	}
    else 

	exit(-1);



    size=i;

    char **polish;
    if((polish=(char**)calloc(size1,(sizeof(char*))))==NULL)
    {
	printf("Not enough memory!!!\n");
	exit(-1);
    }
    if((st=(char**)calloc(25,(sizeof(char*))))==NULL)
    {
	printf("Not enough memory!!!\n");
	exit(-1) ;
    }
    i=0;

    Initialize_Stack_c(st);


    Push_c(st,l_o_b);
    current=((infix1[i++]));

    while(*current!=*hash)
    {
	if(st==NULL)
	{
	    printf("1.Invalid expression as stack popped off!!!\n");
	    exit(-1);
	}
	while(input_precedence(current)<(stack_precedence(Topvalue_c(st))))
	{
	    temp1=Pop_c(st);
	    polish[k]=malloc(strlen(temp1));
	    strcpy(polish[k++],temp1);
	    Rank=Rank+rank(temp1);
	    if(Rank<1)
	    {
		printf("2.Invalid expression as rank of the expression is invalid!!!\n");
		exit(1);
	    }
	}

	if((input_precedence(current))!=(stack_precedence(Topvalue_c(st))))
	    Push_c(st,current);
	else
	    Pop_c(st);


	current=((infix1[i++]));

    }

  if(Isempty()==0|| Rank!=1)
    {
	printf("3.invalid expression\n");
	exit(-1);
    }
    else
    {	
	for(int m=0;m<j;m++)
		free(infix1[m]);
	free(infix);
	return polish;
    }
}







/*
   char* Paranthised_infix_to_Suffix(char* infix)
   {

   int l=strlen(infix),Rank=0,i=0,j=0,garbage;
   char *s,*polish,*temp,current,c;


   infix[l]=')';
   infix[l+1]='\0';


   s=(char*)malloc(l);
   polish=(char*)malloc(l);
   temp=(char*)malloc(l);

   Initialize_Stack_c(s);

   Push_c(s,'(');

   current=((infix[i]));
   i++;

   while(current!='\0')
   {
   if(s==NULL)
   {
   printf("1.Invalid expression\n");
   exit(0);
   }
   while((input_precedence(current))<(stack_precedence(Topvalue_c(s))))
   {
   temp[0]=Pop_c(s);
   strcat(polish,temp);
   Rank=Rank+rank_para(temp);

   if(Rank<1)
   {
   printf("2.Invalid expression\n");
   exit(1);
   }
   }

   if((input_precedence(current))!=(stack_precedence(Topvalue_c(s))))
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
   return polish;
   }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

*/
int Evaluate_Suffix_Expression(char **s)
{
    if (s==NULL)
	return 0;
    bool truevar=true,falsevar=false;

    int i=0;
    char *temp;
    int t1,t2,t3;
    int *stack;
    if((stack=(int*)malloc(50*sizeof(int)))==NULL)
    {
	printf("Not enough memory!!!\n");
	return 0;
    }
    Initialize_Stack(stack);

    while(*s[i])
    {
	temp=s[i];

	if (isdigit(*temp)  ||( ((temp[0]=='-')) &&(isdigit(temp[1]))) )
	{
	    t3=atoi(temp);
	    Push(stack,t3);
	}
	else
	{
	    t1=Pop(stack);
	    t2=Pop(stack);
	    if((temp[0]=='-') && (isdigit(temp[1])) )
		Push(stack,t2-t1);
	    else
	    {
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
		    case'=':
			if(t1==t2)
			    Push(stack,truevar);
			else
			    Push(stack,falsevar);
			break;
		    case '<':
			if(t1>t2)
			    Push(stack,truevar);
			else
			    Push(stack,falsevar);
			break;
		    case'>':
			if(t1<t2)
			    Push(stack,truevar);
			else
			    Push(stack,falsevar);
			break;
		    case '/':
			if (t1==0)
			{
			    printf("Division by zero!!!\n");
			    return 0;
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
			    return 0;
			}
			else
			    Push(stack,t2%t1);
			break;
		    default:
			printf("Operation not supported.\n");
			break;
		}
	    }
	}
	i++;

    }
    int result=stack[0];
    free(stack);
    return result;
}

int power(int t1,int t2)
{
    int pow=1;
    for(int i=0;i<t2;i++)
	pow*=t1;
    return pow;
}

