#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"listh.h"

#define filename "test.txt"

void display(STU stu);
void menu();

int main()
{
	pNODE list;
	STU stu;
	int pos, choose = -1;
	char buf[MAX];

	make(&list);
	menu();

	while (choose != 0)
	{
		printf("Input choose : ");
		scanf("%d", &choose);
		system("cls");
		switch (choose)
		{
		case 1:
			printf("input name : ");
			while (getchar() != '\n') continue;
			while (gets(stu.name) != NULL && stu.name[0] != '\0')
			{	
				printf("input No : ");
				scanf("%d", &stu.no);
				while (getchar() != '\n') continue;
				addEND(&list, stu);
				printf("input name : ");
			}
			break;
		case 2:
			printf("input name : ");
			while (getchar() != '\n') continue;
			while (gets(stu.name) != NULL && stu.name[0] != '\0')
			{
				printf("input No : ");
				scanf("%d", &stu.no);
				printf("input pos : ");
				scanf("%d", &pos);
				while (getchar() != '\n') continue;
				addPOS(&list, stu,pos);
				printf("input name : ");			
			}
			break;
		case 3:
			deleteEND(&list);
			break;
		case 4:
			printf("input pos : ");
			scanf("%d", &pos);
			deletePOS(&list, pos);
			break;
		case 5:
			printf("------------------------------\n");
			func(&list, display);
			printf("------------------------------\n");	
			break;
		case 6:
			printf("------------------------------\n");
			endfunc(&list, display);
			printf("------------------------------\n");
			break;
		case 7:
			saveFILE(&list, filename);
			break;
		case 8:
			loadFILE(&list, filename);
			break;
		case 9:
			printf("input num : ");
			scanf("%d", &pos);
			findNUM(&list, pos);
			break;
		case 10:
			printf("input name : ");
			scanf("%s", &buf[0]);
			findNAME(&list, &buf);
			break;
		}	
		menu();
	}	
	clear(&list);
	printf("END\n");
}

void display(STU stu)
{
	printf("No : %d    Name : %s\n", stu.no, stu.name);
}

void menu()
{
	printf("\n\t\v1 : add             \t\v2 : add pos\n");
	printf("\t\v3 :delete             \t\v4 : delete pos\n");
	printf("\t\v5 : display           \t\v6 : end display \n");
	printf("\t\v7 : save              \t\v8 : load\n");
	printf("\t\v9 : find number   \t\v10 : find name\n");
	printf("\t\v0 : end&clear\n\n");
}