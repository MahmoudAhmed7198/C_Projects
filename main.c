  /*
 * main.c
 *
 *  Created on: Jan 31, 2024
 *      Author: Lenovo
 */
#include<stdio.h>
#include<stdlib.h>
#include"School_System.h"
typedef unsigned char uint8;
extern int counter;
int main(void)
{
	setbuf(stdout,NULL);
	uint8 count,arr[counter];
	uint8 id,year,courseid,grade;
	uint8 check;
	char validity;
	printf("Welcome To School System!\n");
	do{
	printf("Press '1' to check if student Database is full or not\n");
	printf("Press '2' to get the number of students in the school Database\n");
	printf("Press '3' to Add an Entry in the school Database\n");
	printf("Press '4' to Delete an Entry from the school Database\n");
	printf("Press '5' to Read an Entry from the school Database\n");
	printf("Press '6' to Get the id list in the school Database\n");
	printf("Press '7' to check if the entered id exist or not\n");
	scanf("%hhu",&check);
	switch(check)
	{
	case 1:
		SDB_ISFull();
		break;
	case 2:
		uint8 num_of_entries=SDB_GetUsedSize();
		printf("%d\n",num_of_entries);
		break;
	case 3:
		printf("Enter the student ID to add it:");
		scanf("%hhu",&id);
		printf("Enter the year:");
		scanf("%hhu",&year);
		printf("Enter the course id:");
		scanf("%hhu",&courseid);
		printf("Enter the grade:");
		scanf("%hhu",&grade);
		SDB_AddEntry(id, year, courseid, grade);
		break;
	case 4:
		printf("Enter the id of student to delete the data:");
		scanf("%hhu",&id);
		SDB_DeleteEntry(id);
		break;
	case 5:
		printf("Enter the student id to read the grade:");
		scanf("%hhu",&id);
		printf("Enter the course id:");
		scanf("%hhu",&courseid);
		SDB_ReadEntry(id, courseid, &grade);
		break;
	case 6:
		SDB_GetIDList(&count, arr);
		break;
	case 7:
		printf("Enter the student id:");
		scanf("%hhu",&id);
		SDB_ISIdExist(id);
		break;
	}
	printf("To handle another operation Press 'Y' to Exit Press 'N':");
	scanf(" %c",&validity);
	}while(validity == 'Y');
	printf("Thank you !");

	return 0;
}

