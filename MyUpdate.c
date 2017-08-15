#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <conio.h>
#include <windows.h>

char host[16];
char account[100];
char password[100];
char database[100];

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
	printf("���� ȣ��Ʈ�� �Է��ϼ��� : "); scanf("%s", host);
	printf("�������� �Է��ϼ��� : "); scanf("%s", account);
	printf("���� ��й�ȣ�� �Է��ϼ��� : "); scanf("%s", password);
	printf("DB���� �Է��ϼ��� : "); scanf("%s", database);
}

void MyUpdate() {
	char pm[10];
	char table[100];
	char howtochange[2];
	char yeol[100];
	char amount[100];

	MYSQL *conn = mysql_init(NULL);
		if (conn == NULL)
		{
			fprintf(stderr,"%s\n", mysql_error(conn));
			exit(1);
		}
		if (mysql_real_connect(conn, host, account, password, NULL, 0, NULL, 0) == NULL)
		{
			fprintf(stderr, "%s\n", mysql_error(conn));
			mysql_close(conn);
			exit(1);
		}
		
	    printf("������ ���̺��� �Է��ϼ��� : "); scanf("%s", table);
		printf("������ ���� �Է��ϼ��� : "); scanf("%s", yeol);
	    printf("������ ���� �Է��ϼ��� : "); scanf("%s", amount);
		printf("���� ���̶�� +, �� ���̶�� -, �ٲ� ���̶�� = �� �Է��ϼ��� : "); scanf("%s", howtochange);
	    
		if (strcmp(howtochange, "+") == 0)
		{
			if (mysql_query(conn, "UPDATE ", table, " SET ", yeol, " = ", yeol, " + ", amount))
			{
				fprintf(stderr,"%s\n" , mysql_error(conn));
				mysql_close(conn);
				exit(1);
			}
			mysql_close(conn);
		}
		else if (strcmp(howtochange, "-") == 0)
		{
			if (mysql_query(conn, "UPDATE", table, "SET", yeol, "=", yeol, "-", amount))
			{
				fprintf(stderr,"%s\n", mysql_error(conn));
				mysql_close(conn);
				exit(1);
			}
		}
		else if (strcmp(howtochange, "=") == 0)
		{
			if (mysql_query(conn, "UPDATE", table, "SET", yeol, "=", amount))
			{
				fprintf(stderr, "%s\n", mysql_error(conn));
				mysql_close(conn);
				exit(1);
			}
		}
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