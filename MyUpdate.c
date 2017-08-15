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
	printf("MySQL 클라이언트 버전 : %s\n", mysql_get_client_info());
	printf("##############################\n\n");
	printf("MyUpdate 프로그램에 오신 것을 환영합니다!\n");
	printf("목적에 맞는 숫자와 함께 Enter을 눌러 주세요.\n");
	printf("===============================\n\n");
	printf("<     1. MySQL 서버 연결      >\n\n");
	printf("<     2. MyUpdate 실행        >\n\n");
	printf("<     3. 도움말               >\n\n");
	printf("<     4. 제작자               >\n\n");
	printf("<     5. 프로그램 종료        >\n\n");
	printf("===============================\n\n");
	printf("##### 메뉴를 선택하세요. #####\n\n");
	printf("입력 → ");
	scanf("%d", &num);
	return num;
}

void Connect() {
	printf("서버 호스트를 입력하세요 : "); scanf("%s", host);
	printf("계정명을 입력하세요 : "); scanf("%s", account);
	printf("계정 비밀번호를 입력하세요 : "); scanf("%s", password);
	printf("DB명을 입력하세요 : "); scanf("%s", database);
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
		
	    printf("수정할 테이블을 입력하세요 : "); scanf("%s", table);
		printf("수정할 열을 입력하세요 : "); scanf("%s", yeol);
	    printf("수정할 값을 입력하세요 : "); scanf("%s", amount);
		printf("더할 것이라면 +, 뺄 것이라면 -, 바꿀 것이라면 = 을 입력하세요 : "); scanf("%s", howtochange);
	    
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
	if (cnt == 0) puts("입력 데이터가 없습니다!");
	else {
		printf("찾을 이름은? : ");
		scanf("%s", FindName);
		//for (i = 0; i < cnt; i++)
		//{
			//if (strcmp(DB[i].name, FindName) == 0)
			//	printf("%s\t%s\t%s\t%s\n", DB[i].name, DB[i].addr, DB[i].tel, DB[i].special);
			// else printf("찾는 이름이 없습니다.\n");
	//	}
	}
	system("pause");
}

void Save() {
	char FileName[10];
	FILE* fp;
	int i;
	if (cnt == 0) {
		printf("입력 데이터 없음\n");
		system("pause");
		return;
	}
	printf("저장할 파일명 입력 : ");
	scanf("%s", FileName);
	fp = fopen(FileName, "w");

	for (i = 0; i < cnt; i++)
		//fprintf(fp, "%s\t%s\t%s\t%s\n", DB[i].name, DB[i].addr, DB[i].tel, DB[i].special);
	printf("파일 저장 완료\n");
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
		case 5: printf("사요-나라!\n"); exit(0); break;
		default: printf("그런 메뉴는 존재하지 않는데수웅\n"); break;
		}
	}
}