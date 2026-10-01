#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct.h"

void uid(st** head){
	int id;
	printf("Enter the Book ID to Update:");
	scanf("%d",&id);
	st* t=*head;
	while(t!=NULL){
		if(t->bid==id){
			printf("\n %-10d | %-20s | %-20s",t->bid,t->bname,t->bauthor);
			break;
		}
		t=t->next;
	}
	if(t!=NULL){
		printf("\nEnter the new Book details(ID,Name,Author) to Update:");
		scanf("%d%s%s",&t->bid,t->bname,t->bauthor);
		return;
	}
	printf("Book ID Not Found....\n");

}

void uname(st** head){
	char id[30];
        printf("Enter the Book Name to Update:");
        scanf("%s",id);
        st* t=*head;
        while(t!=NULL){
                if(strcmp(t->bname,id)==0){
                        printf("\n %-10d | %-20s | %-20s",t->bid,t->bname,t->bauthor);
                        break;
                }
                t=t->next;
        }
    
	if(t!=NULL){
        	printf("\nEnter the new Book details(ID,Name,Author) to Update:");
	        scanf("%d%s%s",&t->bid,t->bname,t->bauthor);
		return;
	}
	printf("Book Name Not Found....\n");

}

int update(st** head){
	if(*head==NULL){
		printf("NO DATA...\n");
		return 0;
	}
	int op;
label:	printf("\n\nEnter the option to Update,\n1.Book ID\n2.Book Name\nEnter:");
	scanf("%d",&op);
	switch(op){
		case 1:
			uid(head);
			break;
		case 2:
			uname(head);
			break;
		default:
			printf("\nEnter the Correct Option..\n");
			goto label;
	}
}
