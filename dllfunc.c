#include"functionheader.h"

dll* createnode(int x,int y)
{
	dll *t=calloc(1,sizeof(dll));
	t->fp_size=x;
	t->fp_position=y;
	return t;
}
void display(dll *head)
{
	if(head==NULL)
	{
		printf("\n\t\t\t\tEmpty list passed!!!\n");
		exit(-1);
	}

	dll *t=head;
	
	printf("\n\t\t\t\tThe new list is:>>>> ");
	while(t->next!=head)
	{
		printf("%d %d",t->fp_size,t->fp_position);
		t=t->next;
	}

	printf("<<<<\n");
}

int count(dll *head)
{
	if(head==NULL)
	{
		printf("\n\t\t\t\tEmpty list passed!!!\n");
		exit(-1);
	}
	dll *t=head;
	int i=0;
	while(t->next!=head)
	{
		t=t->next;
		i++;
	}
	return i;
}

dll* insert(dll *head,int x,int y)
{
	dll *t=createnode(x,y),*w=head;
	
	if (head==NULL)
		return t;
	while(w->next!=head)
		w=w->next;
	w->next=t;
	t->prev=w;
	t->next=head;
	head->prev=t;

	return head;
}


dll* returnfromend(dll *head)
{
	return head->prev;
}

void deletelist(dll *head)
{
	dll *t=head,*w;
	
	if(head==NULL)
		exit(-1);

	while(t!=NULL)
	{
		w=t->next;
		free(t);
		t=w;
	}
		
}

/*dll* findandreplace(dll *head, int i, int x)
{
	if(head==NULL)
		exit(-1);
	
	dll *t=head;
	int j=find(head,i);
	
	if (j!=-1)
	{
		for(int k=1;k<j;k++)
			t=t->next;
		t->data=x;
		return head;
	}

	printf("\n\t\t\t\tElement not found!!!!\n\t\t\t\t");
	
	return NULL;
}

void reverse(dll *head)
{
	if(head==NULL)
	{
		printf("\t\t\t\tEmpty list passed!!!\n");
		exit(-1);
	}

	dll *t=head;
	while(t->next!=NULL)
		t=t->next;
	

	printf("\n\t\t\t\tThe reversed list is:>>>> ");
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->prev;
	}
	printf("<<<<");

}


dll* findandelete(dll *head,int x)
{
	int i=find(head,x);
	return deletefrompos(head,i);
}

dll* selection(dll *head)
{
	int c;
	dll *min,*t=head,*w;

	for (t=head ; t!=NULL ; t=t->next)
	{	for (w=t->next ; w!=NULL ; w=w->next)
		if ((t->data)>(w->data))
		{	
			min=w;
			if ((t->data)!=(min->data))
			{
				c=t->data;
				t->data=min->data;
				min->data=c;
			}
		}	

	}
	return head;
}
dll* RemoveDuplicates(dll* head)
{
	if (head==NULL)
	{
		printf("\n\t\t\t\tEmpty List Passed!!!\n");
		exit(-1);
	}


	dll *t=head,*w=head,*p,*q;	// 'p' and 'q' are temporary pointers used for
					// keeping track of the node to be deleted, etc.
	w=w->next;
	while(t!=NULL)
	{
		w=t->next;
		while(w!=NULL)					// This piece of code checks
		{						// whether any repetitions
			if(t->data==w->data)			// are there or not!!!
			{
				goto here;	
			}
			w=w->next;
		}
		t=t->next;
	}
	if (t==NULL)
		if (w==NULL)					//This piece gives the sufficient
			goto herefinally;			// output if no repetitions
								// are found!!!

here:
	t=head;
	w=head;
	w=w->next;
	while(t!=NULL)
	{
		w=t->next;				// This piece of code checks
		p=t;					// and deletes the node
		while(w!=NULL)				// if it is a repeated character
		{				
			if(t->data==w->data)
			{	
				p->next=w->next;
				q=w;
				w=w->next;
				free(q);
			}
			else
			{
				p=w;
				w=w->next;
			}
		}
		t=t->next;
	}
	return head;

herefinally:							// output message if no
	printf("\n\t\t\t\tNo repeted characters found!!!");	// repetitions are found!!!
	return head;
}
*/
