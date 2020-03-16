#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<math.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdbool.h>
int top,n;



void Initialize_Stack_c(char **a);
void Push_c(char **s, char *x);
char* Pop_c(char **s);
char* Topvalue_c(char **s);

void Initialize_Stack(int *s);
void Push(int *s,int x);
int Pop(int *s);
int Topvalue(int *s);
int  Isfull();
int Isempty();
void Stackoverflow();
void Stackunderflow();

char** tokenizer(char *s);
char** tokenizer_for_all(char *a);
void  trim(char  *a);

int precedence(char* option);
int rank(char* value);
char** Infix_to_Suffix(char** infix);

int input_precedence(char* option);
int stack_precedence(char* option);
int rank_para(char* value);
char** Paranthised_infix_to_Suffix(char** infix);

int Evaluate_Suffix_Expression(char **s);
int power(int t1,int t2);
