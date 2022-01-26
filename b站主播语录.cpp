#include<stdio.h>
#include<windows.h>
#include<string.h>
struct node
{
	char text[10][300];//内容 
	int speed[10];//移动的速度 
	int color[10];//字符串颜色 
	int in[10]; //每个字符串的初始位置 
};
struct node DM ={{"卢本伟牛逼","我裂开了","耗子胃汁","奥利给","关掉"},
{4,5,7,8,9,10,11,12,4,5},
{4,5,7,8,9,10,11,12,4,5}
};
//出现位置 
 
void gotoxy(int x, int y)
{
	HANDLE hout;
	COORD pos;
	pos.X = x;
	pos.Y = y;
	
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, pos);
}
 
/*隐藏光标*/
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
 
/*设置颜色*/
void set_color(int color)
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
 
int main()
{
	int i,a[10],b[10],x=9;
	show_cursor(0);//隐藏光标
	//求每个字符串长度，用于开始出现的地址 
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
			gotoxy(b[i],i);//让字符串从右到左移动，b[i]是自减的 
			set_color(DM.color[i]);
			printf("%s\n",DM.text[i]);
		}
		system("cls");
		Sleep(120);
	}
	return 0; 
}
