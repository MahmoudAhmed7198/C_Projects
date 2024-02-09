#include"School_System.h"
#include<stdio.h>

#define MAX_NUM_OF_ENTRIES 10 //maximum number of students
//initially the school has 4 students
Student_Info student[MAX_NUM_OF_ENTRIES]={{10,1,{1,2,3},{70,80,90}},//studentID=10,StudentYear=1,courseID(1,2,3),grades
										  {20,2,{4,5,6},{90,80,70}},//StudentID=20,StudentYear=2,courseID(4,5,6),grades
										  {30,3,{7,8,9},{60,70,80}},//StudentID=30,StudentYear=3,courseID(7,8,9),grades
										  {40,4,{10,11,12},{70,80,100}}//StudentID=40,StudentYear=4,courseID=(10,11,12)
																	  };

 int counter=4;//number of students exist in school(will increment when adding a new entry and decrement when delete entry)
void SDB_ISFull(void)
{
	if(counter==MAX_NUM_OF_ENTRIES)
	{
		printf("the student Database is Full!\n");
	}
	else
	{
		printf("the student Database is not full!\n");
	}
}
uint8 SDB_GetUsedSize(void)
{

	printf("the number of entries in Database = ");
	return counter;
}
void SDB_AddEntry(uint8 id,uint8 year,uint8 CourseID,uint8 grade)
{
	if(counter==MAX_NUM_OF_ENTRIES)
	{
		printf("Database is Full, cannot add an entry!\n");
		return;
	}
	else
	{
		int i;
		do{
		for(i=0;i<MAX_NUM_OF_ENTRIES;i++)
		{
			if(id==student[i].Student_ID)
			{
				printf("The ID is repeated!");
				break;
			}
		}
		}while(id==student[i].Student_ID);
		counter++;//in case the id is not repeated increment the number of students in DB
		student[counter].Student_ID=id;
		switch(year)
		{
		case 1:
			student[counter].year=year;
			if(CourseID==1)
			{
				student[counter].Course_ID[0]=CourseID;
				student[counter].Course_Grade[0]=grade;
			}
			else if(CourseID==2)
			{
				student[counter].Course_ID[1]=CourseID;
				student[counter].Course_Grade[1]=grade;
			}
			else if(CourseID==3)
			{
				student[counter].Course_ID[2]=CourseID;
				student[counter].Course_Grade[2]=grade;
			}
			else
			{
				printf("Wrong Course ID\n");
				return;
			}
			break;
		case 2:
			student[counter].year=year;
			if(CourseID==4)
			{
				student[counter].Course_ID[0]=CourseID;
				student[counter].Course_Grade[0]=grade;
			}
			else if(CourseID==5)
			{
				student[counter].Course_ID[1]=CourseID;
				student[counter].Course_Grade[1]=grade;
			}
			else if(CourseID==6)
			{
				student[counter].Course_ID[2]=CourseID;
				student[counter].Course_Grade[2]=grade;
			}
			else
			{
				printf("Wrong Course ID\n");
				return;
			}
			break;
		case 3:
			student[counter].year=year;
			if(CourseID==7)
			{
				student[counter].Course_ID[0]=CourseID;
				student[counter].Course_Grade[0]=grade;
			}
			else if(CourseID==8)
			{
				student[counter].Course_ID[1]=CourseID;
				student[counter].Course_Grade[1]=grade;
			}
			else if(CourseID==9)
			{
				student[counter].Course_ID[2]=CourseID;
				student[counter].Course_Grade[2]=grade;
			}
			else
			{
				printf("Wrong Course ID\n");
				return;
			}
			break;
		case 4:
			student[counter].year=year;
			if(CourseID==10)
			{
				student[counter].Course_ID[0]=CourseID;
				student[counter].Course_Grade[0]=grade;
			}
			else if(CourseID==11)
			{
				student[counter].Course_ID[1]=CourseID;
				student[counter].Course_Grade[1]=grade;
			}
			else if(CourseID==12)
			{
				student[counter].Course_ID[2]=CourseID;
				student[counter].Course_Grade[2]=grade;
			}
			else
			{
				printf("Wrong Course ID\n");
				return;
			}
			break;
		}
		printf("Entry added successfully!\n");
	}
}
void SDB_DeleteEntry(uint8 id)
{
	int i;
	if(counter==0)
	{
		printf("the Database is Empty!\n");
		return;
	}
	for(i=0;i<MAX_NUM_OF_ENTRIES;i++)
	{
		if(id==student[i].Student_ID)
		{
			student[i].Student_ID='\0';
			student[i].year='\0';
			for(int j=0;j<3;j++)
			{
				student[i].Course_ID[j]='\0';
				student[i].Course_Grade[j]='\0';
			}
			counter--;
			break;
		}
		if(i==MAX_NUM_OF_ENTRIES-1)
		{
			printf("This ID doesn't exist!\n");
			return;
		}
	}
	printf("Entry Deleted successfully\n");

}
void SDB_ReadEntry(uint8 id, uint8 CourseID, uint8* Grade)
{
	int i;
	for(i=0;i<MAX_NUM_OF_ENTRIES;i++)
	{
		if(id==student[i].Student_ID)
		{
			if(CourseID==student[i].Course_ID[0])
			{
				*Grade=student[i].Course_Grade[0];
			}
			else if(CourseID==student[i].Course_ID[1])
			{
				*Grade=student[i].Course_Grade[1];
			}
			else if(CourseID==student[i].Course_ID[2])
			{
				*Grade=student[i].Course_Grade[2];
			}
			else
			{
				printf("this course doesn't has a grade!\n");
				return;
			}
			printf("the grade of student id:%d = %d\n",id,*Grade);
			break;

		}
		if(i==MAX_NUM_OF_ENTRIES-1)
		{
			printf("The ID is deleted!\n");
			return;
		}


	}


}
void SDB_GetIDList(uint8* Count, uint8* List)
{
	int i;
	(*Count)=0;
	for(i=0;i<MAX_NUM_OF_ENTRIES;i++)
	{
		List[i]=student[i].Student_ID;
	}
	(*Count)=counter;
	printf("the number of IDs = %d\n",*Count);
	if(counter == 0)
	{
		printf("the IDs List is empty!\n");
		return;
	}
	printf("the IDs List :-\n");
	for(i=0;i<MAX_NUM_OF_ENTRIES;i++)
	{
		if(student[i].Student_ID=='\0'||student[i].Student_ID==0)
			continue;
		printf("%d\n",List[i]);
	}
}
void SDB_ISIdExist(uint8 ID)
{
	int i,flag=0;
	for(i=0;i<MAX_NUM_OF_ENTRIES;i++)
	{
		if(ID==student[i].Student_ID)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("ID exist\n");
	else
		printf("ID not exist\n");
}

