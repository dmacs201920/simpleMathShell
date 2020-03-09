
char** tokenizer_for_all(char *a)
{
	int l=strlen(a),k=0,count=0;
	
	if (check_for_inbuilt_commands(a))
		return tokenizer(a);

	if (isdigit(a[0]))
	{
		a[l]='#';
		a[l+1]='\0';
	}
	l=strlen(a);
	for (int i=0;i<l;i++)
		if (!isalnum(a[i])||a[i]==' '||a[i]=='\n'||a[i]=='\t')
			count++;
	char *s=malloc(l+(2*count));
	int j=l+(2*count);
	for (int i=0;i<=l;i++)
	{
		if (!isalnum(a[i])||a[i]==' '||a[i]=='\n'||a[i]=='\t')
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

	char **t=(char**)calloc(2*count+1,sizeof(char*));
	k=0;
	t[0]=s;
	for(int i=0;i<j;i++)
		if (s[i]=='\0')
			t[++k]=(s+i+1);

	return t;
}


char** Infix_to_Suffix(char** infix)
{
	int Rank=0,i=0,k=0;
	char **s,**polish,*temp,*current,c;
	char hash[]={'#'};
	char zero[]={'\0'};


	while(*(infix[i++])!='#');

	if((s=(char**)malloc(100*(sizeof(char*))))==NULL)
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
			return NULL;
		}
		while(precedence(current)<(precedence(Topvalue_c(s))))
		{
			temp=Pop_c(s);
			polish[k++]=temp;
			Rank=Rank+rank(temp);
			if(Rank<1)
			{
				printf("Invalid expression\n");
				return NULL;
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
			return NULL;
		}
	}
	if(Rank==1)
	{
		polish[k]=zero;
		free(s);
		return(polish);
	}
	else
	{
		printf("2.invalid expression\n");
		return NULL;
	}
}



