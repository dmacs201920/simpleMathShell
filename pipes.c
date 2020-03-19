		/*
		 * MATH SHELL: Written by Hariharan and Abhiishek S Chugh
					   -173209	-171201		
					   -III B.Sc. Mathematics (Honours)
		*/


#include"functionheader.h"

int pipefd[2];
extern void lc(void),rc(void);

void main()
{
	int l_pid,r_pid;
	int ret;
	int status;


	if (pipe(pipefd)<0)
	{
		perror("pipe");
		exit(1);
	}


	if (l_pid=fork()<0)
	{
		perror("fork");
		exit(1);
	}
	else if (l_pid==0)
		lc();
//	ret=wait(&status);

	if (ret==l_pid&&(r_pid=fork())<0)
	{
		perror("fork");
		exit(1);
	}
	else if (ret==l_pid&&r_pid==0)
		rc();


	close(pipefd[0]);
	close(pipefd[1]);
	

	while((ret=wait(&status))>0)
	{
		if (ret==l_pid)
			printf("Left child terminated,status: %x",status);
		else if (ret==r_pid)
			printf("Left child terminated,status: %x",status);
		else
			printf("%d child terminated,status: %x",ret,status);
	}

}


void lc(void)
{
	close(pipefd[0]);
	close(1);
	dup(pipefd[1]);
	close(pipefd[1]);

	pipefd[1]=2;
	printf("The value is:%d",pipefd[1]);
}


void rc(void)
{
	close(pipefd[1]);
	close(0);
	dup(pipefd[0]);
	close(pipefd[0]);
	pipefd[0]=pipefd[1]+4;
	printf("The value is:%d",pipefd[0]);
}

}
