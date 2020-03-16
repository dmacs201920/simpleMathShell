

#include"functionheader.h"


dyna_var *head=NULL;
void main()
{	
	FILE *fp;
	char *input_string,**w,buf[1024],**t=NULL,*cwd;
	int j,status;


	printf("\f\t\t\t\t\t~Welcome to Hari and Chugh's Shell~\n\t\tUse at your own risk and don't even try division by 0, it will give the error message!!!\n\n");


	while(1)
	{	
		if (wait(&status))
		{
			cwd=getcwd(buf,sizeof(buf));
			input_string=readline("~/cherry_shell/:)/>>> ");
			add_history(input_string);	
			char *pipe_position=check_for_pipes(&input_string);
			/*if (pipe_position!=NULL)
			{
				t=tokenizer_for_pipes(s);
				goto here;
			}*/
		
			t=tokenizer_for_all(input_string);

			int i=0;
			i=check_function_call(t);
			
			switch(i)
			{
				case 1:
					j=fork();
					if (j==0)
					{
						execlp(t[0],t[0],t[1],t[2],t[3],t[4],t[5],NULL);
						perror("execlp");
					}
					break;
				case 2:
					chdir(t[1]);
					break;
				case 3:
					head=dynamicallydeclare(head,t[0],t[2]);
					break;
				case 4:
					if (head==NULL)
						printf("No variables declared\n");
					else
						display_dynamically_declared(head);
					break;
				case 5:
					j=fork();
					if (j==0)
					{	
						execlp("grep","grep",w,NULL);
						//perror("execlp");
					}
					break;
				case 6:
					if ((j=fork())==0)
					{
						w=Infix_to_Suffix(t);
						double exp=Evaluate_Suffix_Expression(w);
						printf("~/cherry_shell/:)/>>> %.3lf\n",exp);
						perror("Suffix Evaluation");
						exit(1);
					}
					break;
				case 7:
					printf("~/cherry_shell/:)/>>>  %s\n",cwd);
					break;
				case 8:
					if ((j=fork())==0)
					{
						w=Infix_to_Suffix(t);
						double result=operations(head,w);
						printf("~/cherry_shell/:)/>>> %.3lf\n",result);
						perror("Variable Suffix Evaluation");
						exit(1);
					}
					break;

				case 0:
					free_dyna_variables(head);
					//freeTokenizer(t);
					exit(1);
					break;
				default:
					printf("\nFunction not supported!!!\n");
					break;
			}
		//freeTokenizer(t);
	
		}
	}
}




