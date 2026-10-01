#include<stdio.h>
#include"add.h"
#include"struct.h"
#include"print.h"
#include"remove.h"
#include"save.h"
#include"search.h"
#include"read.h"
#include"update.h"
#include"issue_book.h"
#include"print_issue.h"
#include"returnb.h"

int main(){
	st* head=NULL;
	bissue* issue_head=NULL;
	read(&head);
	int op;
	while(1){
		printf("\n\n------------**LIBRARY MANAGMENT SYSTEM**-------------\n");
		printf("\nEnter the Option:\n1.Add new book\n"
				"2.Update book details\n"
				"3.Remove book details\n"
				"4.Search book\n"
				"5.View all book\n"
				"6.Issue book\n"
				"7.Return book\n"
				"8.List Issued Book\n"
				"9.Save\n"
				"10.Exit\n"
				"Enter:");
		scanf("%d",&op);
		switch(op){
			case 1:
				add(&head);
				break;
			case 2:
				update(&head);
				break;
			case 3:
				bremove(&head);
				break;
			case 4:
				search(head);
				break;
			case 5:
				print(head);
				break;
			case 6:
				issue(&head,&issue_head);
				
				break;
			case 7:
				return_book(&head,&issue_head);
				break;
			case 8:
				print_issue(issue_head);
				break;
			case 9:
				save(head);
				break;
			case 10:
				return 0;
		}
	}
}
