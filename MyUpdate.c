#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <conio.h>
#include <windows.h>

struct Person {
	char host;
	char account;
	char password;
	char database;
	char table;
};
struct Person DB; // �ִ� 10�� ����
int cnt = 0;

int Menu()
{
	int num;
	system("cls");
	printf("##############################\n");
	printf("MySQL Ŭ���̾�Ʈ ���� : %s\n", mysql_get_client_info());
	printf("##############################\n\n");
	printf("MyUpdate ���α׷��� ���� ���� ȯ���մϴ�!\n");
	printf("������ �´� ���ڿ� �Բ� Enter�� ���� �ּ���.\n");
	printf("===============================\n\n");
	printf("<     1. MySQL ���� ����      >\n\n");
	printf("<     2. MyUpdate ����        >\n\n");
	printf("<     3. ����               >\n\n");
	printf("<     4. ������               >\n\n");
	printf("<     5. ���α׷� ����        >\n\n");
	printf("===============================\n\n");
	printf("##### �޴��� �����ϼ���. #####\n\n");
	printf("�Է� �� ");
	scanf("%d", &num);
	return num;
}

void Connect() {
	printf("���� ȣ��Ʈ�� �Է��ϼ��� : "); scanf("%s", DB.host);
	printf("�������� �Է��ϼ��� : "); scanf("%s", DB.account);
	printf("���� ��й�ȣ�� �Է��ϼ��� : "); scanf("%s", DB.password);
	printf("DB���� �Է��ϼ��� : "); scanf("%s", DB.database);
}

void MyUpdate() {
	int i;
	printf("�̸�\t�ּ�\t��ȭ��ȣ\tƯ�̻���\t\n");
	for (i = 0; i < cnt; i++)
		//printf("%s\t%s\t%s\t%s\n", DB[i].name, DB[i].addr, DB[i].tel, DB[i].special);
	system("pause");
}

void Search() {
	char FindName[20];
	int i;
	if (cnt == 0) puts("�Է� �����Ͱ� �����ϴ�!");
	else {
		printf("ã�� �̸���? : ");
		scanf("%s", FindName);
		//for (i = 0; i < cnt; i++)
		//{
			//if (strcmp(DB[i].name, FindName) == 0)
			//	printf("%s\t%s\t%s\t%s\n", DB[i].name, DB[i].addr, DB[i].tel, DB[i].special);
			// else printf("ã�� �̸��� �����ϴ�.\n");
	//	}
	}
	system("pause");
}

void Save() {
	char FileName[10];
	FILE* fp;
	int i;
	if (cnt == 0) {
		printf("�Է� ������ ����\n");
		system("pause");
		return;
	}
	printf("������ ���ϸ� �Է� : ");
	scanf("%s", FileName);
	fp = fopen(FileName, "w");

	for (i = 0; i < cnt; i++)
		//fprintf(fp, "%s\t%s\t%s\t%s\n", DB[i].name, DB[i].addr, DB[i].tel, DB[i].special);
	printf("���� ���� �Ϸ�\n");
	system("pause");

}

void main()
{
	while (1)
	{
		switch (Menu())
		{
		case 1: Connect(); break;
		case 2: MyUpdate(); break;
		case 3: Search(); break;
		case 4: Save(); break;
		case 5: printf("���-����!\n"); exit(0); break;
		default: printf("�׷� �޴��� �������� �ʴµ�����\n"); break;
		}
	}
}