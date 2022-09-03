#include"data.h"
entry* head=NULL;
bool SDB_ISFull()
{
	entry* ptr=head;
	uint8 c=0;
	while(ptr)
	{
		ptr=ptr->next;
		c++;
	}
	if(c==10)
		return true;
	else
		return false;	
}
uint8 SDB_GetUsedSize()
{
	
 entry* ptr=head;
   uint8 c=0;
	while(ptr)
	{
		ptr=ptr->next;
		c++;
	}
	return c;
}
bool SDB_AddEntry(uint8 id, uint8 year,uint8* subjects,uint8* grades)
{
	if(SDB_ISFull())
	{
		return 0;
	}
	entry* ptr=head;
	while(ptr)
	{
		if(ptr->sID==id)
			return 0;
		ptr=ptr->next;
	}
	for(int i=0;i<3;i++)
	{
		if(!(grades[i]>=0&&grades[i]<=100))
		{
			return 0;
		}
	}

		if(SDB_GetUsedSize()==0)
		{
			entry* ptr1=malloc(sizeof(entry));
			head=ptr1;
			ptr1->sID=id;
			ptr1->sYear=year;
			ptr1->c1ID=subjects[0];
			ptr1->c2ID=subjects[1];	
			ptr1->c3ID=subjects[2];
			ptr1->c1Gr=grades[0];
			ptr1->c2Gr=grades[1];
	        ptr1->c3Gr=grades[2];
			ptr1->next=NULL;
			return 1;
			
		}
		else
		{
			entry* ptr1=malloc(sizeof(entry));
			
			ptr1->sID=id;
			ptr1->sYear=year;
			ptr1->c1ID=subjects[0];
			ptr1->c2ID=subjects[1];	
			ptr1->c3ID=subjects[2];
			ptr1->c1Gr=grades[0];
			ptr1->c2Gr=grades[1];
	        ptr1->c3Gr=grades[2];
			ptr1->next=NULL;
			 entry* ptr2=head;
			 while(ptr2->next)
			 {
				 ptr2=ptr2->next;
			 }
			ptr2->next=ptr1;
			return 1;
		}
		

}
void printdata()
{
	entry* ptr=head;
	while(ptr)
	{
		printf(" ( %d) ( %d ) ( %d ) ( %d ) ",ptr->sID,ptr->sYear,ptr->c1ID,ptr->c1Gr);
		ptr=ptr->next;
	}
}
void SDB_DElentry(uint8 id)
{
	if(!(SDB_GetUsedSize()==0))
	{    
           if((SDB_GetUsedSize()==1)&&(head->sID==id))
		   {
			  
				   head=NULL;
		   }
		   else if(head->sID==id)
		   {
			   head=head->next;
		   }
		   else
		   {
			 entry* ptr1=head;
            entry* ptr2=head->next;
while(ptr2)
{
	if(ptr2->sID==id)
	{
	    ptr1->next=ptr2->next	;
		ptr2->next=NULL;
		break;
	}
	ptr1=ptr1->next;
	ptr2=ptr2->next;	
}	
}
}
		
}
bool SDB_ReadEntry(uint8 id,uint8* year,uint8* subjects,uint8* grades)
{
	entry* ptr=head;
	while(ptr)
	{  
          if(ptr->sID==id)
		{
			*year=ptr->sYear;
			subjects[0]=ptr->c1ID;
			subjects[1]=ptr->c2ID;
			subjects[2]=ptr->c3ID;
			grades[0]=ptr->c1Gr;
			grades[1]=ptr->c2Gr;
			grades[2]=ptr->c3Gr;
			return 1;
		}
		ptr=ptr->next;
		
	}
	return 0;
}
void SDB_GetIdList(uint8* count , uint8* list )
{
	int c=SDB_GetUsedSize();
	if(c!=0)
	{
		entry* ptr1=head;
		*count=c;

		for(int i=0;i<c;i++)
		{ 	
			list[i]=ptr1->sID;
			ptr1=ptr1->next;

			}
	}
		
	
	
}
bool Is_IDExists(uint8 id)
{
	entry* ptr1=head;
	while(ptr1)
	{
		if(ptr1->sID==id)
		return 1;
	ptr1=ptr1->next;
		
	}
	return 0;
}








