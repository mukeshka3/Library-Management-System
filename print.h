#include<stdlib.h>
#include<stdio.h>
#include"struct.h"

int print(st* head){
	if(head==NULL){
		printf("No Records...\n");
		return 0;
	}
	st* temp=head;
	printf("\n-----------------------Library Books---------------------------\n");
	printf("%-10s  | %-20s | %-20s | %-15s","Book ID","Book Name","Book Author","Quantity");
	while(temp!=NULL){
		printf("\n %-10d | %-20s | %-20s | %-15d",temp->bid,temp->bname,temp->bauthor,temp->bq);
		temp=temp->next;
	}
}
