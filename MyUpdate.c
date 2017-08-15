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
	char plus[255];
	char minus[255];
	char equal[255];


	MYSQL *conn = mysql_init(NULL);
		if (conn == NULL)
		{
			fprintf(stderr,"%s\n", mysql_error(conn));
			exit(1);
		}
		if (mysql_real_connect(conn, host, account, password, database, 0, NULL, 0) == NULL)
		{
			fprintf(stderr, "%s\n", mysql_error(conn));
			mysql_close(conn);
			exit(1);
		}
		
	    printf("������ ���̺��� �Է��ϼ��� : "); scanf("%s", table);
		printf("������ ���� �Է��ϼ��� : "); scanf("%s", yeol);
	    printf("������ ���� �Է��ϼ��� : "); scanf("%s", amount);
		printf("���� ���̶�� +, �� ���̶�� -, �ٲ� ���̶�� = �� �Է��ϼ��� : "); scanf("%s", howtochange);
	    
		sprintf(plus, "UPDATE %s SET %s = %s + %s", table, yeol, yeol, amount);
		sprintf(minus, "UPDATE %s SET %s = %s - %s", table, yeol, yeol, amount);
		sprintf(equal, "UPDATE %s SET %s = %s", table, yeol, amount);

		if (strcmp(howtochange, "+") == 0)
		{
			if (mysql_query(conn, plus))
			{
				fprintf(stderr,"%s\n" , mysql_error(conn));
				mysql_close(conn);
				exit(1);
			}
			mysql_close(conn);
		}
		else if (strcmp(howtochange, "-") == 0)
		{
			if (mysql_query(conn, minus))
			{
				fprintf(stderr,"%s\n", mysql_error(conn));
				mysql_close(conn);
				exit(1);
			}
		}
		else if (strcmp(howtochange, "=") == 0)
		{
			if (mysql_query(conn, equal))
			{
				fprintf(stderr, "%s\n", mysql_error(conn));
				mysql_close(conn);
				exit(1);
			}
		}
}

void Help() {
	printf("MyUpdate Ver Beta.0.1 by SINOBUZ\n");
	printf("MySQL ��������, �ܺ� ���� ������ ȹ���ϼž� �մϴ�!\n");
	printf("GRANT ALL ~ ��ɾ ���ø� �˴ϴ�.\n");
	system("pause");
}

void Creator() {
	printf("���°���б� 2�г� 5�� ���ؿ�\n");
	printf("�����б� ��ǻ�����α׷��� II ���ǿ��� �н���\n");
	printf("e-mail : vegarian@overcast.kr\n");
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
		case 3: Help(); break;
		case 4: Creator(); break;
		case 5: printf("���-����!\n"); exit(0); break;
		default: printf("�׷� �޴��� �������� �ʴµ�����\n"); break;
		}
	}
}