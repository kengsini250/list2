#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"listh.h"
 
void copy(NODE*p,STU stu);

void make(pNODE *p)
{
	*p = NULL;
}

void addEND(pNODE * p, STU stu)
{
	NODE *now;
	NODE *head = *p;
	now = (NODE*)malloc(sizeof(NODE));
	copy(now, stu);
	now->next = NULL;
	now->front = NULL;

	if (head == NULL)
		*p = now;
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = now; 
		now->front = head;
	}
}

void addPOS(pNODE * p, STU stu, int pos)
{
	NODE *head = *p;
	NODE *add ;
	NODE *now;
	int i = 1;

	if (pos > count(p))
	{
		printf("over ! No data. total %d\n", count(p));
		return;
	}

	now = (NODE*)malloc(sizeof(NODE));
	copy(now, stu);
	now->next = NULL;
	now->front = NULL;

	if (head == NULL)
		*p = now;
	else
	{
		while (head->next != NULL && i < pos)
		{
			add = head;
			head = head->next;
			i++;
		}
		add->next = now;
		now->front = add;
		now->next = head;
		head->front = now;
	}
}

void deleteEND(pNODE * p)
{
	NODE *head = *p;
	NODE *d;
	if (head == NULL)
	{
		printf("No data\n");
		return;
	}
	else
	{
		while (head->next != NULL)
		{
			d = head;
			head = head->next;
		}
		d->next = NULL;
		free(head);
		printf("delete\n");
	}

}

void deletePOS(pNODE * p, int pos)
{
	NODE *head = *p;
	NODE *del;
	int i = 1;

	if (pos > count(p))
	{
		printf("over ! No data. total %d\n", count(p));
		return;
	}
	if (head == NULL)
	{
		printf("No data.\n");
		return;
	}
	else
	{
		while (i < pos)
		{
			i++;
			del = head;
			head = head->next;
		}
		del->next = head->next;
		head->next->front = del;
		free(head);
		return;
	}

}

void saveFILE(pNODE * p, char * filename)
{
	FILE *out;
	NODE*head = *p;
	int end = 0;

	if ((out = fopen(filename, "w+")) == NULL)
	{
		printf("open false\n");
		return;
	}
	if (head == NULL)
		fprintf(out, "No Date\n");
	else
	{
		while (1)
		{
			fprintf(out, "%d\n", head->stu.no);
			fprintf(out, "%s\n", head->stu.name);		
			if (head->next == NULL) break;
			head = head->next;
		}
	}
	fprintf(out, "%d\n", end);
	fclose(out);
	printf("Finish\n");
}

void loadFILE(pNODE * p, char * filename)
{
	FILE *in;
	int input;
	char buf[MAX];
	if ((in = fopen(filename, "r")) != NULL)
	{
		while (1)
		{
			NODE *now;
			NODE *head = *p;

			fscanf(in, "%d", &input);
			if (input == 0) break;
			fscanf(in, "%s", &buf[0]);
			
			now = (NODE*)malloc(sizeof(NODE));
			now->stu.no = input;
			strncpy(now->stu.name, buf, 20);

			now->next = NULL;
			now->front = NULL;

			if (head == NULL)
				*p = now;
			else
			{
				while (head->next != NULL)
					head = head->next;
				head->next = now;
				now->front=head;
			}
		}
	}
	else
	{
		printf("open false\n");
		return;
	}
	printf("Finish.\n");
	fclose(in);
}

void findNUM(pNODE * p, int find)
{
	NODE *head = *p;
	int i = 1;
	while (head != NULL)
	{
		if (find == head->stu.no)
		{
			printf("Done! pos : %d\n", i);
			return;
		}
		i++;
	}
	printf("No Data.\n");
}

void findNAME(pNODE * p, char * find)
{
	NODE *head = *p;
	int i = 1;
	while (head != NULL)
	{
		if (strcmp(head->stu.name,find)==0)
		{
			printf("Done! pos : %d\n", i);
			return;
		}
		i++;
	}
	printf("No Data.\n");
}

int count(pNODE * p)
{
	NODE *head = *p;
	int i=1;
	if (head == NULL)
	{
		printf("No Data\n");
		return 0;
	}
	else
	{
		while (head->next != NULL)
		{
			head = head->next;
			i++;
		}
	}
	return i;
}

void func(pNODE *p, void(*pfun)(STU stu))
{
	NODE *head = *p;
	while (head != NULL)
	{
		(*pfun)(head->stu);
		head=head->next;
	}
}

void endfunc(pNODE * p, void(*pfun)(STU stu))
{
	NODE *head = *p;
	while (head->next != NULL)      //把head指针移动到
		head = head->next;             //最后一个数据上
	while (head != NULL)//从最后一个开始倒序输出
	{
		(*pfun)(head->stu);
		head = head->front;
	}
}

void clear(pNODE * p)
{
	NODE *head;
	while (*p != NULL)
	{
		head = (*p)->next;
		free(*p);
		*p = head;
	}
	system("cls");
}

void copy(NODE * p, STU stu)
{
	p->stu = stu;
}
