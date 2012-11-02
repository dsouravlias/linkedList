/*Dimitris Souravlias - Implementation of a linked list. 
Each list node contains an integer.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int info;
	struct ListNode * next;
}NODE;

typedef  struct List {
	NODE * first;
}LIST;

void InsertToFront (LIST *,int);
void PrintList (LIST);
void Lookup (LIST,int);
void DeleteFromFront (LIST *);
void DeleteFromEnd (LIST *);
void Delete (LIST *,int n);


int main (void) {

	int choice,n;
	LIST MyList={NULL};
	LIST *lp=&MyList;
	
	while (1) {
		printf ("\n--------------------------------------\n");
		printf ("Choose a function for the linked list.\n\n");
		printf ("1. Insert a new node.\n");
		printf ("2. Print list.\n");
		printf ("3. Search for a specific node.\n");
		printf ("4. Delete the first node.\n");
		printf ("5. Delete the last node.\n");
		printf ("6. Delete a given node.\n");
		printf  ("7. Exit the program.\n");
		printf ("--------------------------------------\n\n");
		scanf ("%d",&choice);

		switch (choice) {
			case 1: printf ("Please give an integer to insert in the list.\n");
				scanf ("%d",&n);
				InsertToFront (lp,n);break;
			case 2: PrintList (MyList);break;
			case 3: printf ("Please give an integer to look up in the list.\n");
				scanf ("%d",&n);
				Lookup (MyList,n);break;
			case 4: DeleteFromFront (lp);break;
			case 5: DeleteFromEnd (lp);break;
			case 6: printf ("Please give an integer to delete from the list.\n");
				scanf ("%d",&n);
				Delete (lp,n);break;
			case 7: return 0;
			default:printf ("Error!\n");break;
		}
	}
	return 0;
}


int isEmptyList (LIST l) {

	NODE *p=l.first;
	int result;
	if (p==NULL) {
			printf  ("\nEmpty List.\n");
			return 0;
	}
	return 1;
}


void InsertToFront (LIST * lp,int n) {

	NODE *p=(NODE *)malloc(sizeof(NODE));
	if (p==NULL) {
			printf ("No memory.\n");
			exit(EXIT_FAILURE);
		}
	p->info=n;
	p->next=lp->first;
	lp->first=p;
	printf ("\nA node with integer %d was inserted.\n",n);

	return;
}


void PrintList (LIST l) {
	
	NODE *p;
	if (isEmptyList(l)==0) return;
	printf ("\n\nList:\n");
	for (p=l.first;p!=NULL;p=p->next)
		printf ("[%d]\n",p->info);
	return;
}


void Lookup(LIST l,int n) {

	NODE *p;
	int flag=0;
	for (p=l.first;p!=NULL;p=p->next)
		if (p->info==n)
			flag=1;
	if (flag==1) printf ("\nA node with integer %d exists in the list.\n",n);
	else printf ("\nA node with integer %d does not exist in the list.\n",n);

	return;
}


void DeleteFromFront (LIST *lp) {

	NODE *p;
	if (isEmptyList(*lp)==0) return;
	p=lp->first;
	lp->first=p->next;
	printf ("\nThe node with integer %d was deleted.\n",p->info);
	free (p);

	return;
}


void DeleteFromEnd (LIST *lp) {
	
	NODE *p=lp->first,*q;
	int result=0;
	if (isEmptyList(*lp)==0) return;
	if (p->next==NULL) { 
		DeleteFromFront (lp);
		return;
	}
	while (p!=NULL) {
		if (p->next==NULL) {
			result=p->info;
			q->next=NULL;
			break;
		}
		q=p;
		p=p->next;
	}
	printf ("\nThe node with integer %d deleted.\n",result);
	free(p);

	return;
}


void Delete (LIST * lp,int n) {

	NODE *p=lp->first,*q=NULL;
	if (isEmptyList(*lp)==0) return;
	if (p->info==n) DeleteFromFront(lp);
	else {
		while (p!=NULL) {
			q=p;
			p=p->next;
			if (p==NULL) {
				printf ("\nThe node with integer %d was not found.\n",n);
				return;
			}
			if (p->info==n) {
				printf ("\nThe node with integer %d was found and deleted\n",n);
				q->next=p->next;
				free (p);
				return;
			}
		}
	}

	return;

}