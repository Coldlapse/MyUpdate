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
		
	    printf("수정할 테이블을 입력하세요 : "); scanf("%s", table);
		printf("수정할 열을 입력하세요 : "); scanf("%s", yeol);
	    printf("수정할 값을 입력하세요 : "); scanf("%s", amount);
		printf("더할 것이라면 +, 뺄 것이라면 -, 바꿀 것이라면 = 을 입력하세요 : "); scanf("%s", howtochange);
	    
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
	printf("MySQL 설정에서, 외부 접속 권한을 획득하셔야 합니다!\n");
	printf("GRANT ALL ~ 명령어를 쓰시면 됩니다.\n");
	system("pause");
}

void Creator() {
	printf("가온고등학교 2학년 5반 서준원\n");
	printf("계절학기 컴퓨터프로그래밍 II 교실에서 학습함\n");
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
		case 5: printf("사요-나라!\n"); exit(0); break;
		default: printf("그런 메뉴는 존재하지 않는데수웅\n"); break;
		}
	}
}