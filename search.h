#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
#include<string.h>

void byid(st* temp){
	int id;
	printf("Enter the Book ID:");
	scanf("%d",&id);
        printf("\n-----------------------Library Books---------------------------\n");
        printf("%-10s  | %-20s  | %-20s","Book ID","Book Name","Book Author");
        while(temp!=NULL){
		if(temp->bid==id)
	                printf("\n %-10d | %-20s | %-20s",temp->bid,temp->bname,temp->bauthor);
		temp=temp->next;

	}
}

void byname(st* temp){
        char str[30];
        printf("Enter the Book Name:");
        scanf("%s",str);
        printf("\n-----------------------Library Books---------------------------\n");
        printf("%-10s  | %-20s  | %-20s","Book ID","Book Name","Book Author");
        while(temp!=NULL){
                if(strcmp(temp->bname,str)==0)
                        printf("\n %-10d | %-20s | %-20s",temp->bid,temp->bname,temp->bauthor);
                temp=temp->next;

        }
}

void byauthor(st* temp){
        char str[30];
        printf("Enter the Book Author:");
        scanf("%s",str);
        printf("\n-----------------------Library Books---------------------------\n");
        printf("%-10s  | %-20s  | %-20s","Book ID","Book Name","Book Author");
        while(temp!=NULL){
                if(strcmp(temp->bauthor,str)==0)
                        printf("\n %-10d | %-20s | %-20s",temp->bid,temp->bname,temp->bauthor);
                temp=temp->next;

        }
}

int search(st* head){
	if(head==NULL){
		printf("No Datas....");
		return 0;
	}
	int op;
label:	printf("Enter the Option Search By,\n1.By Id\n2.By Name\n3.By Author\nEnter:");
	scanf("%d",&op);
	switch(op){
		case 1:
			byid(head);
			break;
		case 2:
			byname(head);
			break;
		case 3:
			byauthor(head);
			break;
		default:
			printf("Enter the valid option..");
			goto label;
	}
}
