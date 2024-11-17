#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8;
typedef  char int8;
typedef unsigned short uint16;
typedef  short int16;
typedef unsigned int uint32;
typedef  int int32;
typedef enum {false, true} bool;
struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
};

struct listNode
{
    struct listNode *next ;
    struct SimpleDb std;
};

bool SDB_IsEmpty();
bool SDB_IsFull();
bool SDB_AddEntry();
uint8 SDB_GetUsedSize();
void SDB_DeletEntry(uint32 id);
void printData(struct SimpleDb x);
bool SDB_ReadEntry (uint32 id);
void SDB_GetList();
bool SDB_IsIdExist(uint32 id);
void SDB_APP();
void SDB_action(uint8 choice);

