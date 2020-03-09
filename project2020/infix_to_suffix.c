
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
    /*	
	if((polish=(char**)calloc(i,(sizeof(char*))))==NULL)
	{
	printf("Not enough memory!!!");
	exit(-1);
	}*/
    i=0;

    Initialize_Stack_c(st);


    Push_c(st,hash);
    current=((infix[i++]));


    while(*current!=*hash)
