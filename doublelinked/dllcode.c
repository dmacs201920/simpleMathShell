#include"dllheader.h"


void main()
{
	char c;
	int i,pos,x;
	dll *head=NULL;

	printf("\f");
switch1:
	printf("\n*****************************************************************************************************************************************************\n*****************************************************************************************************************************************************\n\t\t\t\tEnter\n\t\t\t\t'a' for making a newlist;\n\t\t\t\t'b' to display the list;\n\t\t\t\t'c' to insert at the beginning of the list;\n\t\t\t\t'd' to insert at the end of the list;\n\t\t\t\t'e' to insert after a particular position in the list;\n\t\t\t\t'f' to insert the next element in the list in the ascending order;\n\t\t\t\t'g' to delete from a partiular position in a list;\n\t\t\t\t'h' to delete an element from the end of the list\n\t\t\t\t'i' to find and delete an element from the list\n\t\t\t\t'j' to delete an element from the front of the list\n\t\t\t\t'k' to find a particular element in the list\n\t\t\t\t'l' to find-and-replace an element in the list\n\t\t\t\t'm' to reverse the list\n\t\t\t\t'n' to sort the list in ascending order\n\t\t\t\t'x' for exiting...\n*****************************************************************************************************************************************************\n\t\t\t\tYour choice: ");
	scanf("%c",&c);
	getchar();

	switch(c)
	{
		case 'a':	//This case creates a new list!!!
			if(head!=NULL)
				deletelist(head);
			printf("\n\t\t\t\tEnter a number to create a new list with: ");
			scanf("%d",&i);
			getchar();
			if(isalpha(i))
			{
				printf("\n\t\t\t\tEnter a number!!!\n\t\t\t\tList not created!!!\n");
				goto switch1;
			}
			head=createnode(i);
			display(head);
			goto switch1;
			break;
		case 'b':	//This case displays the list!!!
			if (head==NULL)
			{
				printf("\n\n\t\t\t\tFirst define a list to display it!!!\n\t\t\t\tNice try!!!\n");
				goto switch1;
			}
			display(head);
			goto switch1;
			break;
		case 'c':	//This case inserts an element in the beginning!!!
			printf("\n\n\t\t\t\tEnter the element to be inserted at the beginning: ");
			scanf("%d",&i);
			getchar();
			head=insertatbeg(head,i);
			display(head);
			goto switch1;
			break;
		case 'd':	//This inserts an element to the list from the end!!!
			printf("\n\n\t\t\t\tEnter the element to be inserted at the end of the list: ");
			scanf("%d",&i);
			getchar();
			head=insertatend(head,i);
			display(head);
			goto switch1;
			break;
		case 'e':	//This inserts an element after the desired position asked by the user!!!
			printf("\n\n\t\t\t\tEnter the element to be inserted: ");
			scanf("%d",&i);
			getchar();
			printf("\t\t\t\tEnter the position after which you want to insert this element: ");
			scanf("%d",&pos);
			getchar();
			head=insertatpos(head,i,pos-1);
			display(head);
			goto switch1;
			break;
		case 'f':	//This case inserts the next element in the ascending order in the list!!!
			printf("\n\n\t\t\t\tEnter the element to be inserted: ");
			scanf("%d",&i);
			getchar();
			head=insertascend(head,i);
			display(head);
			goto switch1;
			break;
		case 'g':	//This deletes an element from the list specified by the user!!!
			printf("\n\t\t\t\tThe list is:>>> ");
			display(head);
			printf("\n\n\t\t\t\tEnter the position of the element you want to be deleted: ");
			scanf("%d",&pos);
			getchar();
			head=deletefrompos(head,pos);
			display(head);
			goto switch1;
			break;
		case 'h':
			//head=deletefromend(head);
			display(deletefromend(head));
			goto switch1;
			break;
		case 'i':
			printf("\n\t\t\t\tEnter the element to be deleted from the list: ");
			scanf("%d",&i);
			getchar();
			head=findandelete(head,i);
			display(head);
			goto switch1;
			break;
		case 'j':
			head=deletefrompos(head,1);
			display(head);
			goto switch1;
			break;
		case 'k':
			x=0;
			printf("\n\t\t\t\tEnter the number to be found: ");
			scanf("%d",&x);
			getchar();
			i=find(head,x);
			if (i!=-1)
				printf("\n\t\t\t\tThe element %d is in the %d position in the list!!!\n",x,i);
			goto switch1;
			break;
		case 'l':	//This finds the element in the list and replaces it with another element input by the user!!!
			printf("\n\t\t\t\tEnter the element to be found: ");
			scanf("%d",&i);
			getchar();
			printf("\n\t\t\t\tEnter the element to be replaced with: ");
			scanf("%d",&x);
			getchar();
			head=findandreplace(head,i,x);
			display(head);
			goto switch1;
			break;
		case 'm':
			reverse(head);
			goto switch1;
			break;
		case 'n':
			//display(link_bubbley(head));
			display(selection(head));
			goto switch1;
			break;
		case 'x':	//This case frees the memory and exits the program
			deletelist(head);
			exit(-1);
			break;
		default:
			printf("Not a choice!\n\n");
			goto switch1;
			break;

	}
}

