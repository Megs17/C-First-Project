#include"data.h"
int main()
{
uint8 arr1[3]={1,2,3};
uint8 arr2[3]={100,20,30};
SDB_AddEntry(1,2,arr1,arr2);
SDB_AddEntry(2,2,arr1,arr2);
uint8 co;
uint8 arr[10];
 SDB_GetIdList( &co , arr);
 for(int i=0;i<co;i++)
 {
	 printf(" %d ",arr[i]);
 }


	
}
