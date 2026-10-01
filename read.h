#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int read(st** head)
{
    FILE* fp = fopen("Library_Records.txt", "r");

    if(fp == NULL)
    {
        printf("File Not Exists\n");
        return 0;
    }

    char buf[200];

    st* temp = *head;

    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        st* nn = malloc(sizeof(st));

        // Try to extract book data from the line
        if(sscanf(buf, "%d | %s | %s | %d ",
                  &nn->bid,
                  nn->bname,
                  nn->bauthor,&nn->bq) == 4)
        {
            nn->next = NULL;

            if(*head == NULL)
            {
                *head = nn;
                temp = nn;
            }
            else
            {
                temp->next = nn;
                temp = nn;
            }
        }
        else
        {
            // Header / separator / empty line
            free(nn);
        }
    }

    fclose(fp);
}
