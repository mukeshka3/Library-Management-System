#include <stdio.h>
#include "struct.h"

int print_issue(bissue *head)
{
    if (head == NULL)
    {
        printf("No Issue Records...\n");
        return 0;
    }

    bissue *temp = head;

    printf("\n------------------------------- Issue Records -------------------------------\n");

    printf("%-8s | %-8s | %-15s | %-12s | %-12s | %-12s | %-6s | %-10s",
           "Book ID",
           "User ID",
           "User Name",
           "Issue Date",
           "Due Date",
           "Return Date",
           "Fine",
           "Status");

    while (temp != NULL)
    {
        printf("\n%-8d | %-8d | %-15s | %02d/%02d/%-5d | %02d/%02d/%-5d | %02d/%02d/%-5d | %-6d | %-10s",
               temp->bookid,
               temp->userid,
               temp->name,

               temp->issue_date.day,
               temp->issue_date.month,
               temp->issue_date.year,

               temp->due_date.day,
               temp->due_date.month,
               temp->due_date.year,

               temp->return_date.day,
               temp->return_date.month,
               temp->return_date.year,

               temp->fine,

               temp->returned ? "Returned" : "Issued");

        temp = temp->next;
    }

    printf("\n");

    return 1;
}