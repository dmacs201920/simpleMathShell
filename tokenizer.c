#include"functionheader.h"

char** tokenizer(char *s)
{
	char **t;
	int i,l=strlen(s),k=1,j,word=0;

	for(j=0;j<l;j++)
	{
		if(s[j]==' ')
		{
			s[j]='\0';
			word++;
		}
	}
	word++;

	t=calloc(word,sizeof(char*));
	t[0]=calloc(1,strlen(s));
	strcpy(t[0],s);
	if (word>1)
	{
		for(i=0;i<l;i++)
		{
			if(s[i]=='\0')
			{
				t[k]=calloc(1,strlen(&s[i+1]));
				strcpy(t[k++],&s[i+1]);
			}
		}
	}
	free(s);
	return t;
}

int check_for_inbuilt_commands(char *a)		//-> Takes input as a string and checks for commands that have been limited by us.
						//-> For eg. "vi -O -y main.c functions.c"
{
	char s[][19]={"vi","dir","alias","mkdir","grep","cd","cp","cat","wc","gdb","gcc","rm","make","chmod","ls","./","exit","quit","all"};
	for (int i=0;i<19;i++)
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
	
		t[0]=malloc(strlen(s));
		strcpy(t[0],s);
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
	free(t);
	free(s);
	free(a);
	return w;
}


void freeTokenizer(char **t)
{
	int i=0;
	while(t[i])
		free(t[i++]);
}



