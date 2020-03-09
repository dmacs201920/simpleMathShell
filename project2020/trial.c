#include<stdio.h>
void  trim(char  *a)
{
    int i,l,L;

    l=strlen(a);

    for(i=0;i<l;i++)
    {
	if()


/*    for (i=0;a[i]==' ';i++);
    strcpy(a,a+i);

    l=strlen(a);

    for (i=l-1;a[i]==' ';--i);
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


	p=a+j+1;
	q=a+k;

	while(1)
	{
	    *p=*q;
	    if(*p=='\0')
		break;
	    ++p;
	    ++q;
	}
    }*/
   // printf("%s\n",a);
}
void main()
{
    char *p=(char*)calloc(10,sizeof(char));
    gets(p);
    trim(p);
}
