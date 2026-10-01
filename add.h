#include<stdio.h>
#include<stdlib.h>
#include"struct.h"

int add(st** head){
	st* nn=(st*)malloc(sizeof(st));
	printf("Enter the Book id,name,Author:");
	nn->bq=1;
	scanf("%d%s%s",&nn->bid,nn->bname,nn->bauthor);
	nn->next=NULL;
	if(*head==NULL){
		*head=nn;
	}
	else{
		st* temp=*head;
		while(temp!=NULL){
			if(temp->bid==nn->bid){
				(temp->bq)++;
				free(nn);
				return 0;
			}
			temp=temp->next;
		}
		 temp=*head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=nn;
	}
}
