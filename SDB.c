#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"

struct listNode *head, *tail;

bool SDB_IsFull()
{
    if(SDB_IsEmpty())
        return false;
    else
    {
        if(SDB_GetUsedSize() < 10)
            return false;
        else
            return true;
    }

}

bool SDB_IsEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}


bool SDB_AddEntry()
{
    if(!SDB_IsFull())
    {
        struct listNode *n = malloc(sizeof(struct listNode));

        if(SDB_IsEmpty())
        {
            n->next = NULL;
            head = n;
            tail = n;
        }
        else
        {
            n->next = tail;
            tail = n;
        }
        printf("ENTER STUDENT ID: ");
        scanf("%d",&n->std.Student_ID);
        printf("ENTER STUDENT YEAR: ");
        scanf("%d",&n->std.Student_year);
        if( n->std.Student_year < 1 || n->std.Student_year >12 )
        {
            printf("\nINVALID YEAR \n1->9\n");
            if(n == head)
            {
                head = NULL;
                tail= NULL;
            }
            free(n);
            SDB_AddEntry();
            return;
        }
        printf("ENTER COURSE 1 ID: ");
        scanf("%d",&n->std.Course1_ID);
        printf("ENTER COURSE 1 GRADE: ");
        scanf("%d",&n->std.Course1_grade);
        if( n->std.Course1_grade < 1 || n->std.Course1_grade > 9 )
        {
            printf("\nINVALID GRADE \n1->9\n");
            if(n == head)
            {
                head = NULL;
                tail= NULL;
            }
            free(n);
            SDB_AddEntry();
            return;
        }
        printf("ENTER COURSE 2 ID: ");
        scanf("%d",&n->std.Course2_ID);
        printf("ENTER COURSE 2 GRADE: ");
        scanf("%d",&n->std.Course2_grade);
        if( n->std.Course2_grade < 1 || n->std.Course2_grade > 9 )
        {
            printf("\nINVALID GRADE \n1->9\n");
            if(n == head)
            {
                head = NULL;
                tail= NULL;
            }
            free(n);
            SDB_AddEntry();
            return;
        }
        printf("ENTER COURSE 3 ID: ");
        scanf("%d",&n->std.Course3_ID);
        printf("ENTER COURSE 3 GRADE: ");
        scanf("%d",&n->std.Course3_grade);
        if( n->std.Course2_grade < 1 || n->std.Course2_grade > 9 )
        {
            printf("\nINVALID GRADE \n1->9\n");
            if(n == head)
            {
                head = NULL;
                tail= NULL;
            }
            free(n);
            SDB_AddEntry();
            return;
        }
        return true;
    }
    else
        return false;

}

uint8 SDB_GetUsedSize()
{
    if(SDB_IsEmpty())
        return 0;
    else
    {
        int i=1;

        struct listNode *n = tail;
        n=n->next;
        while(n != NULL)
        {
            i++;
            n=n->next;
        }
        return (uint8)i;
    }

}

void SDB_DeletEntry (uint32 id)
{
    if(SDB_GetUsedSize() > 3)
    {
        struct listNode *n = tail ;
        if(id == tail-> std.Student_ID)
        {
            tail=tail->next;
            free(n);
        }
        else
        {
            while(n->next->std.Student_ID != id)
                n=n->next;
            struct listNode *t = n->next;
            n->next=n->next->next;
            free(t);
        }
    }
    else
    {
        printf("UNABLE TO DELETE\nDATABASE CANNOT CONTAIN < 3 STUDENTS");
    }
}

void printData(struct SimpleDb x)
{
    printf("STUDENT ID: %d\n",x.Student_ID);
    printf("COURSE 1 ID: %d\n",x.Course1_ID);
    printf("COURSE 1 GRADE: %d\n",x.Course1_grade);
    printf("COURSE 2 ID: %d\n",x.Course2_ID);
    printf("COURSE 2 GRADE: %d\n",x.Course2_grade);
    printf("COURSE 3 ID: %d\n",x.Course3_ID);
    printf("COURSE 3 GRADE: %d\n",x.Course3_grade);
}

bool SDB_ReadEntry (uint32 id)
{
    struct listNode *n = tail ;
    while(n->std.Student_ID != id)
    {
        n=n->next;
    }
    printData(n->std);
}

void SDB_GetList()
{
    struct listNode *n = tail ;
    while(n != NULL)
    {
        printData(n->std);
        n=n->next;
    }
}

bool SDB_IsIdExist (uint32 id)
{
    struct listNode *n = tail ;
    while(n != NULL)
    {
        if(n->std.Student_ID == id)
            return true;
    }
    return false;
}
