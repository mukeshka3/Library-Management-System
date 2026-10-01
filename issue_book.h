#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include <time.h>

Date get_date(void)
{
    Date d;

    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    d.day = today->tm_mday;
    d.month = today->tm_mon + 1;
    d.year = today->tm_year + 1900;

    return d;
}

Date get_due_date(void)
{
    Date d;
    time_t t = time(NULL);
    t = t + (7 * 24 * 60 * 60);
    struct tm *today = localtime(&t);

    d.day = today->tm_mday;
    d.month = today->tm_mon + 1;
    d.year = today->tm_year + 1900;

    return d;
}

int issue(st **head, bissue **issue_head)
{
    if (*head == NULL)
    {
        printf("NO BOOK...\n");
        return 0;
    }

    char name[30];

    printf("Enter the Book Name: ");
    scanf("%29s", name);

    st *temp = *head;

    while (temp != NULL)
    {
        if (strcmp(name, temp->bname) == 0)
        {
            if (temp->bq == 0)
            {
                printf("NO AVAILABLE...\n");
                return 0;
            }

            bissue *new = malloc(sizeof(bissue));
            if (new == NULL)
            {
                printf("Memory allocation failed...\n");
                return 0;
            }

            printf("Enter the User ID and Name: ");
            scanf("%d %29s", &new->userid, new->name);

            new->bookid = temp->bid;

            new->issue_date = get_date();
            new->due_date = get_due_date();

            new->return_date.day = 0;
            new->return_date.month = 0;
            new->return_date.year = 0;

            new->fine = 0;
            new->returned = 0;
            new->next = NULL;
            temp->bq--;
            if (*issue_head == NULL)
            {
                *issue_head = new;
            }
            else
            {
                bissue *t = *issue_head;

                while (t->next != NULL)
                {
                    t = t->next;
                }
                t->next = new;
            }
            printf("\nBOOK ISSUED SUCCESSFULLY...\n");
            return 1;
        }
        temp = temp->next;
    }

    printf("NO BOOK FOUND.....\n");

    return 0;
}