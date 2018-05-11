#ifndef LISTH_H_
#define LISTH_H_
#include<stdbool.h>
#define MAX 20

typedef struct student
{
	int no;
	char name[20];
}STU;

typedef struct node
{
	STU stu;
	struct node*next;
	struct node*front;
}NODE;

typedef NODE * pNODE;

void make(pNODE *p);

void addEND(pNODE *p,STU stu);
void addPOS(pNODE *p, STU stu,int pos);

void deleteEND(pNODE *p);
void deletePOS(pNODE *p, int pos);

void saveFILE(pNODE*p,char*filename);
void loadFILE(pNODE*p, char*filename);

void findNUM(pNODE*p, int find);
void findNAME(pNODE*p, char *find);

int count(pNODE *p);
void func(pNODE *p,void(*pfun)(STU stu));
void endfunc(pNODE *p, void(*pfun)(STU stu));
void clear(pNODE *p);

#endif