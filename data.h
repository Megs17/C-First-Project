#include<stdio.h>
#include<stdlib.h>
typedef unsigned char uint8;
typedef enum
{
	false,
	true 
}bool;
typedef struct SimpleDb
{
	uint8 sID;
	uint8 sYear;
	uint8 c1ID;
	uint8 c1Gr;
	uint8 c2ID;
	uint8 c2Gr;
	uint8 c3ID;
	uint8 c3Gr;
	struct SimpleDb* next;
}entry;

bool SDB_ISFull();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry(uint8 id, uint8 year,uint8* subjects,uint8* grades);
void SDB_DElentry(uint8 id);
void printdata();
bool SDB_ReadEntry(uint8 id,uint8* year,uint8* subjects,uint8* grades);
void SDB_GetIdList(uint8* count , uint8* list );
bool Is_IDExists(uint8 id);
