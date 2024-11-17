#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"

int x=1 ;

void SDB_APP()
{
    uint8 op;
    while(x)
    {
        printf("1. add entry\n");
        printf("2. get used size in database\n");
        printf("3. read student data\n");
        printf("4. get the list of all student IDs\n");
        printf("5. check is ID is existed\n");
        printf("6. delete student data\N");
        printf("7. check is database is full\n");
        printf("8. exit\n");
        scanf("%d",&op);
        SDB_action(op);
    }
}


void SDB_action(uint8 op)
{
    int id;
    switch(op)
    {
    case 1 :
        SDB_AddEntry();
        break;
    case 2 :
        printf("THE NUMBER OF STUDENTS IS: %d\n\n",(int)SDB_GetUsedSize());
        break;
    case 3 :

        printf("ENTER STUDENT ID: ");
        scanf("%d",&id);
        SDB_ReadEntry((uint32)id);
        break;
    case 4 :
        SDB_GetList();
        break;
    case 5 :
        printf("ENTER STUDENT ID: ");
        scanf("%d",&id);
        (SDB_IsIdExist((uint32)id)) ? printf("STUDENT EXIST\n") : printf("STUDENT DOESN'T EXIST\n") ;
        break;
    case 6 :
        printf("ENTER STUDENT ID: ");
        scanf("%d",&id);
        SDB_DeletEntry ((uint32)id);
        break;
    case 7 :
        (SDB_IsFull()) ? printf("FULL!!\n\n") : printf("NOT FULL\n\n") ;
        break;
    case 8 :
        (SDB_GetUsedSize() > 3) ? x=0 : printf("ADD MORE STUDENTS\nDATABASE MIN IS THREE STUDENTS\n\n");
        break;
    }
}
