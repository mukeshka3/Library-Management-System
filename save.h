#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
      
int save(st* head)
{
    if(head == NULL)
    {
        printf("No Data...\n");
        return 0;
    }

    FILE *fp = fopen("Library_Records.txt", "w");
    fprintf(fp, "\n-----------------------Library Books---------------------------\n");
    fprintf(fp, "%-10s | %-20s | %-20s | %-15s\n",
            "Book ID", "Book Name", "Book Author","Quantity");

    st* temp = head;

    while(temp != NULL)
    {
        fprintf(fp, "%-10d | %-20s | %-20s | %-15d\n",temp->bid,temp->bname,temp->bauthor,temp->bq);
        temp = temp->next;
    }
    fclose(fp);
}
