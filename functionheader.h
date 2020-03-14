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


int check_for_inbuilt_commands(char *);//function command "vi -O -y main.c functions.c"
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
int power(int t1,int t2);
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
} dyna_var;
dyna_var* dynamicallydeclare(dyna_var *,char *,char *);
void free_dyna_variables(dyna_var *);
void display_dynamically_declared(dyna_var *);
dyna_var* findDynaVariable(dyna_var *,char *);
dyna_var* callDynaVariable(dyna_var *,char *);
double operations(dyna_var *,char **);


typedef struct dll
{
	int fp_size;
	int fp_position;
	struct dll *prev;
	struct dll *next;
} dll;
dll* createnode(int,int);
void display(dll *);
int count(dll *);
dll* insert(dll *,int,int);
dll* returnfromend(dll *);
void deletelist(dll *);


