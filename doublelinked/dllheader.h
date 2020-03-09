typedef struct dll
{
	int data1;
	int data2;
	struct dll *prev;
	struct dll *next;
} dll;


dll* createnode(int,int);
void display(dll *);
int count(dll *);
dll* insert(dll *,int,int);
dll* deletefrompos(dll *,int );
dll* deletefromend(dll *);
void deletelist(dll *);

