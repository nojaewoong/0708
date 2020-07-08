#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

void time_pass(time_t start);
void display_time(long nhour, long nmin, long nsecond);
void control_watch(void);

int main(void)
{
	display_time(0, 0, 0);
	getch();
	control_watch();
	return 0;
}
void control_watch(void)//키를 입력받아 stopwatch를 제 
{
   char key;
   time_t start;
   start=time(NULL);
   time_pass(start);
   do
   {
	key=getch();
	switch(key)
	{
	   case 10 ://엔터누르면 시작또는 정지 
		time_pass(start);
	   case 32 : //시작 시간을 0으로 맞춤 
		start=time(NULL);
		time_pass(start);
		break;
	   case 27 : //프로그램 종료 
		exit(0);
		break;
	}
   }while(key!=27);

}
void time_pass(time_t start)//시작시간과 현재시간 사이의 차이를 계산 
{
double hour, min, second;
long nhour, nmin, nsecond;
time_t now;
while(!kbhit())
{//현재시간 과의 차이계산 시간을 형식에 맞게 출력
	now=time(NULL);
	second=difftime(now, start);
	hour= (second/3600.);
	nhour= (long) hour;
	min= fmod(second, 3600.)/60;
	nmin= (long) min;
	second= fmod(second, 60);
	nsecond= (long) second;
	display_time(nhour, nmin, nsecond);
 }
}
void display_time(long nhour, long nmin, long nsecond)
{
	system("cls"); 
	printf("stopwatch\n\n");
	printf("%.2ld시 %.2ld분 %.2ld초 \n\n", nhour, nmin, nsecond);
	printf("Enter:(시작/정지), SPACE:재시작, Esc:종료\n");

}
