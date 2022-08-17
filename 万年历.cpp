#include <iostream>
#include <conio.h>
#include<cstdlib>
#include<string>
#include<iomanip>
using namespace std;
int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //定义全局数组
//函数声明
int leaptear(int n);//判断是否是闰年
int countyear_days(int year);//计算公元元年到公元（year-1）年的总天数
int countmonth_days(int month);//计算当年前（nonth-1）个月的天数
void menu();//显示系统菜单
void listmonth(int days, int t); //输出某年某月的日历
void search1();//输出指定年份全年12月的日历
void search2();//输出某年某月的日历
void search3();
void menu() {
	cout << endl;
	cout << "\t--------------------------------------------------------\n";
	cout << "\t*                                                      *\n";
	cout << "\t                  欢迎使用万年历系统                    \n";
	cout << "\t*                                                      *\n";
	cout << "\t--------------------------------------------------------\n";
	cout << "\n";
	cout << "\t请选择你要查询的内容：\n\n";
	cout << "\t1.显示某年的日历\n";
	cout << "\t2.显示某年某月的日历\n";
	cout << "\t3.显示某天是星期几\n";
	cout << "\t0.退出系统\n";
	cout << "\t请选择按键(0-3):" << endl ;
}
int leapyear(int n) {
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) return 1;
	else return 0;
}
int countyear_days(int year) {
	int i, days = 0;
	for (i = 1; i < year; ++i) {
		if (leapyear(i)) days += 366;
		else days += 365;
	}
	return days;
}
int countmonth_days(int month) {
	int days;
	for (int i = 0; i < month; ++i) {
		days += month_days[i];
	}
	return days;
}
void listmonth(int days, int t) { //days表示当月天数，t表示此月1号是星期几
	int i, j;
	cout << "星期日   星期一   星期二   星期三   星期四   星期五   星期六" << endl;
	for (i = 1; i < days; ++i) {
		if (i == 1) {
			for (j = 0; j < t; ++j)
				cout << "         ";
		}
		cout << setiosflags(ios::left) << setw(9) << i; //向左对齐
		if ((i + t) % 7 == 0)
			cout << endl;
	}
	cout << endl << endl;
}
void search1() {
	int year, t, k, flag, days;
	cout << "请输入年份：" << endl;
	cin >> year;
	flag = leapyear(year);
	t = (countyear_days(year) + 1) % 7;
	for (k = 1; k <= 12; ++k) {
		days = month_days[k];
		if (flag && k == 2) days = 29;
		cout << k << " 月:" << endl;
		listmonth(days, t);
		t = (t + days % 7) % 7; //计算k+1月的第一天shi星期几
		if (k % 3 == 0) {
			cout << "请按下任意键继续" << endl;
			getch();//函数功能是输入一个字符且不会显，定义在conio.h中
		}
	}
}
void search2() {
	int t, year, month, flag, days, ydays, mdays, alldays;
	cout << "请输入年月（如2020 5）" << endl;
	cin >> year >> month;
	ydays =	countyear_days(year); //计算前year-1的天数
	mdays = countmonth_days( month); // 计算前month-1的天数
	days = month_days[month];
	flag = leapyear(year);
	if (flag) {
		if (month > 2) ++mdays;
		else if (month == 2) days = 29;
	}
	alldays = ydays + mdays + 1; //计算总天数
	t = alldays % 7;
	cout << year << "年" << month << "月" << endl;
	listmonth(days, t);
	cout << endl;
}
void search3() {
	int t, year, month, flag, day, ydays, mdays, alldays;
	cout << "请输入年月日（如2020 5 20）" << endl;
	cin >> year >> month;
	ydays =	countyear_days(year); //计算前year-1的天数
	mdays = countmonth_days( month); // 计算前month-1的天数
	flag = leapyear(year);
	if (flag) {
		if (month > 2) ++mdays;
		else if (month == 2) day = 29;
	}
	alldays = ydays + mdays + day; //计算总天数
	t = alldays % 7;
	string weeks[7] = {"星期日", "星期一", "星期二", " 星期三 ", "  星期四", "星期五", "星期六"};//可以用字符二维数组，只写一维下标就好
	cout <<endl<< weeks[t] << endl<<endl;
 
}
int main() {
	int select;
	while (1) {
		menu();
		cin >> select;
		switch (select) {
			case 1:
				system("cls");
				search1();
				break;
			case 2:
				system("cls");
				search2();
				system("pause");
				break;
			case 3:
				system("cls");
				search3();
				system("pause");
				break;
			case 0:
				cout << "\n\t感谢使用，再见！\n";
				exit(0);
			default:
				cout << "\n\t按键错误，请重新选择！\n";
		}
		system("cls");
	}
	return 0;
}
