#include"header.h"

void main()
{
    int value,l,count1=0;
    char *input,**output,**output1;
    input=(char*)calloc(20,sizeof(char));

    gets(input);
    l=strlen(input);

    for(int i=0;i<l;i++)
	if(!isalnum(input[i]) ||input[i]==' ' ||input[i]=='\n'|| input[i]=='\t')
	    count1++;

    output=tokenizer_for_all(input);

    printf("Tokeneded:");
    for(int j=0;j<4;j++)
	printf("%s ",(output[j]));
    printf("\n");


    output1=Infix_to_Suffix(output);
    printf("\nsuffix:");
    for(int j=0;j<(2*(count1+1))-1;j++)
	printf("%s ",(output1[j]));
    printf("\n");

    value=Evaluate_Suffix_Expression(output1);

    printf("The value is :%d\n",value);



    free(input);


}
