#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void intro_game(void);
void horizontal_slide(int x, int y, char *c2);
void draw_rectangle(int r, int c);
void display_text(int count, int r_count);
void game_control(int* r_c, int rnd);
void gotoxy(int x, int y);

int main(void)
{
   int count=0, rnd;
   int r_count=0;
   char *target="□";
   srand(time(NULL));
   intro_game();	
   do
   {
      system("cls");
      draw_rectangle(20, 20);//게임화면 표시
      rnd=rand()%35+4;//난수발생
      gotoxy(rnd, 2);
      printf("%s", target);//목표물 표시
      count++;
      display_text(count, r_count);//현재 스코어 표시
      game_control(&r_count, rnd);
   }while(count<10);
   return 0;
}

void intro_game(void)//게임하는법 설
{
	printf("말타며 화살쏘기\n\n");
	printf("말을 타고 이동하면서 \n");
	printf("목표물(□)을 맞추는 게임입니다. \n");
	printf("화살은 스페이스키로 발사합니다. \n\n");
	printf("아무키나 누르면 시작합니다. ");
	getch();

}
void horizontal_slide(int x, int y, char *c2)//말의 위치를 좌우로 이동시키는 함수
{
		gotoxy(x, y);
		printf("%s", c2);
		Sleep(50);
		printf("\b ");
}
void draw_rectangle(int r, int c)//직사격형 그리기 함 
{
    int i, j;
    unsigned char a=0xa6;
    unsigned char b[7]; 
    for(i=1;i<7;i++)
   	b[i]=0xa0+i;

    printf("%c%c",a, b[3]);
    for(i=0;i<c;i++)
  	printf("%c%c", a, b[1]);
    printf("%c%c", a, b[4]);
    printf("\n");
    for(i=0;i<r;i++)
    {
	printf("%c%c", a, b[2]);
	for(j=0;j<c;j++)
		printf("  ");
	printf("%c%c",a, b[2]);
	printf("\n");
    }
    printf("%c%c", a, b[6]);
    for(i=0;i<c;i++)
	printf("%c%c", a, b[1]);
    printf("%c%c", a, b[5]);
    printf("\n");
}
void display_text(int count, int r_count)//시도한 횟수와 성공한 횟수를 화면에 출력하는 프로그램
{
	gotoxy(46, 2);
	printf("스페이스키를 누르면\n");
	gotoxy(46, 3);
	printf("화살이 발사됩니다.\n");
	gotoxy(46, 5);
	printf("횟수 : %d", count);
	gotoxy(46, 6);
	printf("성공 : %d", r_count);
}

void game_control(int* r_c, int rnd)//말타고 화살쏘기 게임제어함수 
{
	int i=1, k=1, y;
	char *horse="▲", chr;
	do
	{
		i+=k;
		if (i>39)
			k=-1;
		else if (i<3)
			k=+1;
		horizontal_slide(i+1, 21, horse);
	}while(!kbhit());
	chr=getch();
	y=21;
	if (chr==32)
	{
		while(y>2)
		{
			y-=1;
			gotoxy(i+1, y);
			printf("↑");//화살표시
			Sleep(50);//지연시간
			printf("\b  ");
		}
		if ((rnd<=i) && (i<=(rnd+1)))
		{
			gotoxy(rnd, 2);
			printf("☆");
			gotoxy(46, 8);
			printf("맞았습니다. ");
			Sleep(50);
			*r_c=*r_c+1;
		}
		gotoxy(1, 24);
		printf("아무키나 누르면 다음 진행...");
		getch();
	}

}
void gotoxy(int x, int y)//커서 제어함
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
