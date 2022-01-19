#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
using namespace std;
int main()
{
	time_t tt;
	time(&tt);
	struct tm *t=localtime(&tt);
	for(;;)
	{
		tt--;
		t=localtime(&tt);
		_setsystime(t,0);
		printf("当前时间：%02d:%02d:%02d\n",t->tm_hour,t->tm_min,t->tm_sec);
		Sleep(1000);
		system("cls");
	}
	return 0;
} 
