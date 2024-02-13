typedef unsigned char uint8;

/*the student info for each student*/
typedef struct
{
	uint8 Student_ID;
	uint8 year;
	uint8 Course_ID[3];//array of 3 courses ID
	uint8 Course_Grade[3];//array of 3 grades for 3 courses
}Student_Info;

/*Prototypes of functions*/
void SDB_ISFull(void);
uint8 SDB_GetUsedSize(void);
void SDB_AddEntry(uint8 id , uint8 year,uint8 CourseID,uint8 grade);
void SDB_DeleteEntry(uint8 id);
void SDB_ReadEntry(uint8 id, uint8 CourseID, uint8* Grade);
void SDB_GetIDList(uint8* Count, uint8* List);
void SDB_ISIdExist(uint8 ID);
