#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"

int return_book(st **book_head, bissue **issue_head)
{
    int bid, userid;

    printf("Enter Book ID: ");
    scanf("%d", &bid);

    printf("Enter User ID: ");
    scanf("%d", &userid);

    /* Find issue record */
    bissue *temp = *issue_head;

    while (temp != NULL)
    {
        if (temp->bookid == bid &&
            temp->userid == userid &&
            temp->returned == 0)
        {
            break;
        }

        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("ISSUE RECORD NOT FOUND...\n");
        return 0;
    }

    /* Generate return date */
    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    temp->return_date.day = today->tm_mday;
    temp->return_date.month = today->tm_mon + 1;
    temp->return_date.year = today->tm_year + 1900;

    /* Convert dates into time */
    struct tm due = {0};
    due.tm_mday = temp->due_date.day;
    due.tm_mon = temp->due_date.month - 1;
    due.tm_year = temp->due_date.year - 1900;

    struct tm ret = {0};
    ret.tm_mday = temp->return_date.day;
    ret.tm_mon = temp->return_date.month - 1;
    ret.tm_year = temp->return_date.year - 1900;

    time_t due_time = mktime(&due);
    time_t return_time = mktime(&ret);

    /* Calculate late days */
    int late_days = 0;

    if (return_time > due_time)
    {
        late_days = (return_time - due_time) / (24 * 60 * 60);
    }

    /* Fine = ₹10 per late day */
    temp->fine = late_days * 10;

    /* Mark returned */
    temp->returned = 1;

    /* Increase book quantity */
    st *book = *book_head;

    while (book != NULL)
    {
        if (book->bid == bid)
        {
            book->bq++;
            break;
        }

        book = book->next;
    }
    printf("Book Returned Successfully...\n");

    return 1;
}