		/*
		 * MATH SHELL: Written by Hariharan and Abhiishek S Chugh
					   -173209	-171201		
					   -III B.Sc. Mathematics (Honours)
		*/

#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<string.h>
#include<unistd.h>
#include<math.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdbool.h>


int check_for_inbuilt_commands(char *);		//function command "vi -O -y main.c functions.c"
int check_function_call(char **);

void Initialize_Stack(double *);
void Push (double *, double );
double Pop (double* );
double Topvalue(double*);
int Isfull();
int Isempty();
void Stackoverflow();
void Stackunderflow();
void Initialize_Stack_c(char **);
void Push_c(char **, char *);
char* Pop_c(char **);
char* Topvalue_c(char **);
double Evaluate_Suffix_Expression(char **);
double power(double t1,double t2);
char** Infix_to_Suffix(char**);
int precedence(char *);
int rank(char *);
char** Paranthised_infix_to_Suffix(char**);
int rank_para(char*);
int stack_precedence(char *);
int input_precedence(char *);

char* check_for_pipes(char **);

char** tokenizer(char *);
char** tokenizer_for_all(char*);
void freeTokenizer(char **);

typedef struct dyna_var
{
	char *var;
	char *value;
	struct dyna_var *next;
	struct dyna_var *prev;
} dyna_var;
dyna_var* dynamicallydeclare(dyna_var *,char *,char *);
void free_dyna_variables(dyna_var *);
void display_dynamically_declared(dyna_var *);
dyna_var* findDynaVariable(dyna_var *,char *);
dyna_var* callDynaVariable(dyna_var *,char *);
double operations(dyna_var *,char **);



