#include<stdio.h>
#include<windows.h>
#include<string.h>
struct node
{
	char text[10][300];//���� 
	int speed[10];//�ƶ����ٶ� 
	int color[10];//�ַ�����ɫ 
	int in[10]; //ÿ���ַ����ĳ�ʼλ�� 
};
struct node DM ={{"¬��ΰţ��","���ѿ���","����θ֭","������","�ص�"},
{4,5,7,8,9,10,11,12,4,5},
{4,5,7,8,9,10,11,12,4,5}
};
//����λ�� 
 
void gotoxy(int x, int y)
{
	HANDLE hout;
	COORD pos;
	pos.X = x;
	pos.Y = y;
	
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, pos);
}
 
/*���ع��*/
void show_cursor(int hide)
{
	CONSOLE_CURSOR_INFO cciCursor;
	HANDLE hout;
 
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	if(GetConsoleCursorInfo(hout, &cciCursor))
	{
        cciCursor.bVisible = hide;
        SetConsoleCursorInfo(hout, &cciCursor);
    }
}
 
/*������ɫ*/
void set_color(int color)
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
 
int main()
{
	int i,a[10],b[10],x=9;
	show_cursor(0);//���ع��
	//��ÿ���ַ������ȣ����ڿ�ʼ���ֵĵ�ַ 
	for (i=0;i<10;i++)
	{
		DM.in[i] = 80-strlen(DM.text[i]);
	 }
	for (i=0;i<10;i++)
	 b[i]=DM.in[i]; 
	while (1)
	{
		for (i=0; i<10; i++)
		{ 
			b[i]<0 ? b[i]=DM.in[i] : b[i]=b[i]-DM.speed[i];
			gotoxy(b[i],i);//���ַ������ҵ����ƶ���b[i]���Լ��� 
			set_color(DM.color[i]);
			printf("%s\n",DM.text[i]);
		}
		system("cls");
		Sleep(120);
	}
	return 0; 
}
