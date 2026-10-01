#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"struct.h"

void rid(st** head){
	int id;
	printf("Enter the Book ID:");
	scanf("%d",&id);
	st* temp=*head;
	if((*head)->bid==id){
		*head=temp->next;
		free(temp);
		return;
	}
	else{
		while(temp->next!=NULL){
			if(temp->next->bid==id){
				st* prev=temp->next;
				temp->next=temp->next->next;
				free(prev);
				return;
			}
			temp=temp->next;
		}
	}
	printf("\nBook ID Not Found....\n");
}

void rname(st** head){
  	char name[30];
        printf("Enter the Book Name:");
        scanf("%s",name);
        st* temp=*head;
        if(strcmp((*head)->bname,name)==0){
                *head=temp->next;
                free(temp);
                return;
        }
        else{
                while(temp->next!=NULL){
                        if(strcmp(temp->next->bname,name)==0){
                                st* prev=temp->next;
                                temp->next=prev->next;
                                free(prev);
                                return;
                        }
                        temp=temp->next;
                }
        }
        printf("\nBook Name Not Found....\n");

}

int bremove(st** head){
	if(*head==NULL){
		printf("NO RECORDS....\n");
		return 0;
	}
	int op;
label:	printf("\nEnter the Option\n1.By ID\n2.By Name\n3.Back to mainmenu\n");
	printf("Enter:");
	scanf("%d",&op);
	switch(op){
		case 1:
			rid(head);
			break;
		case 2:
			rname(head);
			break;
		case 3:
			return 0;
		default:
			printf("Enter the Valid Option\n");
			goto label;
	}
}
