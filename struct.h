#ifndef STRUCT_H
#define STRUCT_H

typedef struct node{
	int bid;
	char bname[30];
	char bauthor[30];
	int bq;
	struct node* next;
}st;
typedef struct Date
{
    int day;
    int month;
    int year;
} Date;
typedef struct user
{
    int userid;
    char name[30];
} user;
typedef struct issue{
	int userid;//
	int bookid;//
	char name[30];//
	Date issue_date;
	Date due_date;
	Date return_date;
	int fine;
    int returned;
	struct issue* next;
}bissue;
int id;
#endif
