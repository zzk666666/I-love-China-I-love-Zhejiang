#include<bits/stdc++.h>
#include<windows.h>
#define HEADER1 "-------------------STUDENT-----------------------------------------------------------------------------------------------------------------\n"//学生 
#define HEADER4 "|学号	|姓名|语文|数学|英语|WEB前端开发|综合网络布线     |数据库| \n"
#define HEADER2 "|number|name|Chinese|Math|English|HTML|Integrated_Network_cabling|SQLSEVER|topnum|total|sum|ave|mici| \n"//变量（宏定义） 
#define HEADER3 "|------|----|-------|----|-------|----|--------------------------|---------|----|--------------------------|--------|------|------------|---|-------|--------|" //宏定义制表 
#define FORMAT"|%-10s|%-15s|%4d|%4d|%4d|%4d|%4d|%4d|\n"//格式化数据类型 
#define DATA p->data.num,p->data.name,p->data.Chinese,p->data.Math,p->data.English,p->data.HTML,p->data.Integrated_Network_cabling,p->data.SQLSEVER//指针指向数据 
#define END "-----------------------------------------------------------------------------------------------------------------------------------------------\n"
using namespace std;
int saveflag=0;//检测  
typedef struct student//成绩数据结构体 
{
	char num[10],name[10];
	int Chinese,Math,English,HTML,Integrated_Network_cabling,SQLSEVER,topnum;
	long long total;
	float ave;
}student;
typedef struct node{
	struct student data;//数据域 
	struct node *next;//指针域 
}Node,*Link;
int gotoxy(int x,int y)
{ 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(hout,pos);
} 
//文本颜色 
void textcolor()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | BACKGROUND_BLUE);
} 
//菜单 
void menu()
{
	system("cls");
	srand(time(NULL));
	textcolor();//随机颜色 
	//显示时间 
	time_t timep;
	struct tm *p;
	time(&timep);
	p=gmtime(&timep);
	gotoxy(10,0);   
	printf("                         康申学生成绩管理系统 \n");
	printf("                          %d-",1900+p->tm_year);      
    printf("%d-",1+p->tm_mon);          
    printf("%d ",p->tm_mday);           
    printf("%d:",8+p->tm_hour);
    printf("%d:",p->tm_min);            
    printf("%d\n",p->tm_sec); 
    //呈现菜单 
	gotoxy(10,1);
	printf("*********************************菜单******************************************\n");
	gotoxy(10,2);
	printf("*              1 添加学生成绩                       2 删除学生成绩            *\n");
	gotoxy(10,3);
	printf("*              3 查询                               4 修改                    *\n");
	gotoxy(10,4);
	printf("*              5 插入                               6 统计                    *\n");
	gotoxy(10,5);
	printf("*              7 排序（注意：排序后可能丢失数据）   8 保存                    *\n");
	gotoxy(10,6);
	printf("*              9 显示成绩                           0 退出                    *\n");
	gotoxy(10,7);
	printf("*******************************************************************************\n");
	
}
//输出统计数据函数 
void printdata(Node *pp)
{
	Node *p;
	p=pp; 
	printf(FORMAT,DATA);	
} 
//错误函数
void Wrong()
{
	printf("\n\n\n\n\n\n********输入有误，请重新输入。**********\n");
	getchar();
}
//未找到该学生函数 
void Nofind()
{
	printf("\n==========>未找到该学生\n");
}
void Disp(Link l)
{
	int select; 
	Node *p;
	p=l->next;
	if(!p)
	{
		printf("\n========>未找到该学生\n");
		getchar();
		return;
	}
	printf("\n\n");
	//printheader();
	if(p||select==9)
	{
		printf(HEADER4);
		select=NULL; 
	}
	while(p)
	{
		printdata(p);
		p=p->next;
		printf(HEADER3);
	}
	Sleep(5000);
	getchar(); 
}
//输入学号 
void stringinput(char *t,int lens,char *notice)
{
	char n[255];
	do{
		printf(notice);
		scanf("%s",n);
		if(strlen(n)>lens)printf("\n 字符过长！    \n");
	}while(strlen(n)>lens);
	strcpy(t,n);
}
//输入成绩 
int numberinput(char *notice)
{
	int t=0;
	srand(time(NULL));
	do{
		printf(notice);
		scanf("%d",&t);
		if(t>100||t<0)
		{
			t=rand()%41+60;
			printf("\n 成绩必须在0~100之间%d",t);
			printf("\n");
		}
	}while(t>100||t<0);
	return t;
}
//指向学生成绩 
Node* Locate(Link l,char findmess[],char nameornum[])
{
	Node *r;
	if(strcmp(nameornum,"num")==0)
	{
		r=l->next;
		while(r)
		{
			if(strcmp(r->data.num,findmess)==0)
			return r;
			r=r->next;
		}
	}
	else if(strcmp(nameornum,"name")==0)
	{
		r=l->next;
		while(r)
		{
			if(strcmp(r->data.name,findmess)==0)
			return r;
			r=r->next;
		}
	}
	return 0;
} 
//添加学生 
void Add(Link l)
{
	Node *p,*r,*s;
	char ch,flag=0,num[10];
	r=l;
	s=l->next;
	system("cls");
	Disp(l);
	while(r->next!=NULL)
	r=r->next;
	while(1)
	{
		while(1)
		{
			stringinput(num,10,"输入学号(按0返回):");
			flag=0;
			if(strcmp(num,"0")==0)
			{return;}
			s=l->next;
			while(s)
			{
				if(strcmp(s->data.num,num)==0)
				{
					flag=1;
					break;
				}
				s=s->next; 
			} 
			if(flag==1)
			{
				getchar();
				printf("=====>此学号 %s 已有，重新输入？(y/n):",num);
				scanf("%c",&ch);
				if(ch=='y'||ch=='Y')
				continue;
				else
					return;
			}
			else
			{break;}
		}
		p=(Node *)malloc(sizeof(Node));//分配 
		if(!p)
		{
			printf("\n 分配内存故障");
			return ;
		}
		strcpy(p->data.num,num);
		stringinput(p->data.name,15,"姓名:");
		p->data.Chinese=numberinput("语文成绩[0-100]");//语文成绩 
		p->data.Math=numberinput("数学成绩[0-100]");//数学成绩 
		p->data.English=numberinput("英语成绩[0-100]");//英语成绩 
		p->data.HTML=numberinput("WEB前端开发成绩[0-100]");//网页制作成绩 
		p->data.Integrated_Network_cabling=numberinput("综合网络布线成绩[0-100]");//综合网络布线成绩 
		p->data.SQLSEVER=numberinput("数据库成绩[0-100]");//综合网络布线成绩 
		p->data.total=p->data.Chinese+p->data.Math+p->data.English+p->data.HTML+p->data.Integrated_Network_cabling+p->data.SQLSEVER;//该生总分 
		p->data.ave=(float)(p->data.total/6);//平均成绩 
		p->next=NULL;//空指针 
		r->next=p;
		r=p;//迭代 
		saveflag=1; 
	}
	return; 
}
//修改学生成绩 
void Qur(Link l)
{
	int select;
	char searchinput[20];
	Node *p;
	if(!l->next)
	{
		system("cls");
		printf("\n=====>未找到该学生\n");
		getchar();
		return;
	}
	system("cls");
	printf("\n    =====>l 学号查找 =====>2 姓名查找\n");//输入学号或姓名 
	scanf("%d",&select);
	if(select==1)
	{
		stringinput(searchinput,10,"输入现有学生学号:");
		p=Locate(l,searchinput,"num");
		printf(HEADER4);
		if(p)
		{
			//printheader();
			printdata(p);
			printf(END);
			printf("按任意键返回");
			getchar();
		}
		else
		Nofind();
		getchar();
	}
	else if(select==2)
	{
		stringinput(searchinput,15,"输入已有学生姓名:");
		p=Locate(l,searchinput,"name");
		printf(HEADER4);
		if(p)
		{
			//printheader();
			printdata(p);
			printf(END);
			printf("按任意键返回");
			getchar();
		}
		else
			Nofind();
			getchar();
	}
	else
		Wrong();
		getchar();
}
void Del(Link l)
{
	int sel;
	Node *p,*r;
	char findmess[20];
	if(!l->next)
	{
		system("cls");
		printf("\n=====>未找到该学生\n");
		getchar();
		return;
	} 
	system("cls");
	Disp(l);
	printf("\n =====>1 以学号删除 =====>2 以姓名删除\n");
	printf("     请选择[1,2]:");
	scanf("%d",&sel);
	if(sel==1)
	{
		stringinput(findmess,10,"输入现有学生学号:");
		p=Locate(l,findmess,"num");
		if(p)
		{
			r=l;
			while(r->next!=p)
			r=r->next;
			r->next=p->next;
			free(p);
			printf("\n=====>删除成功！\n");
			getchar();
			saveflag=1;
		}
		else
			Nofind();
			getchar();
	}
	else if(sel==2)
	{
		stringinput(findmess,15,"输入现有学生姓名");
		p=Locate(l,findmess,"name");
		if(p)
		{
			r=l;
			while(r->next!=p)
			r=r->next;
			r->next=p->next;
			free(p);
			printf("\n=====>删除成功！\n");
			getchar();
			saveflag=1;
		}
		else
			Nofind();
			getchar();
	}
	else
		Wrong();
		getchar();
}
//修改学生信息 
void Modify(Link l)
{
	Node *p;
	char findness[20];
	if(!l->next)
	{
		system("cls");
		printf("\n=====>未找到该学生！\n");
		getchar();
		return;
	}
	system("cls");
	printf("修改学生记录");
	Disp(l);//显示统计结果 
	stringinput(findness,10,"输入现有学生学号");//输入现有的学生学号 
	p=Locate(l,findness,"num");
	//依次修改以往该生成绩 
	if(p)
	{
		printf("学号:%s,\n",p->data.num); 
		printf("姓名:%s,",p->data.name);
		stringinput(p->data.name,15,"输入新成绩：");
		printf("旧成绩（语文）：%d",p->data.Chinese);
		p->data.Chinese=numberinput("新成绩:[0-100]:");
		printf("旧成绩（数学）：%d,",p->data.Math);
		p->data.Math=numberinput("新成绩：[0-100]");
		printf("旧成绩（英语）：%d,",p->data.English);
		p->data.English=numberinput("英语：[0-100]");
		printf("旧成绩（WEB前端开发）%d,",p->data.HTML);
		p->data.HTML=numberinput("新成绩：[0-100]");
		printf("旧成绩（综合网络布线）%d,",p->data.Integrated_Network_cabling);
		p->data.Integrated_Network_cabling=numberinput("新成绩:[0-100]");
		printf("旧成绩（数据库）%d,",p->data.SQLSEVER);
		p->data.SQLSEVER=numberinput("新成绩:[0-100]");
		p->data.total=p->data.Chinese+p->data.Math+p->data.English+p->data.HTML+p->data.Integrated_Network_cabling+p->data.SQLSEVER;
		p->data.ave=(float)(p->data.total/6);
		p->data.topnum=0;
		printf("\n=====>modify success!\n");
		Disp(l);
		saveflag=1;
	}
	//未找到该生 
	else{
		Nofind();
		getchar();
	}
}
//插入已有学生信息 
void Insert(Link l)
{
	Link p,v,newinfo;
	char ch,num[10],s[10];
	int flag=0;
	v=l->next;
	system("cls");
	Disp(l);
	while(1)
	{
		stringinput(s,10,"请在号码后面输入插入位置");
		flag=0;
		v=l->next;
		while(v)
		{
			if(strcmp(v->data.num,s)==0)
			{
				flag=1;
				break;
			}
			v=v->next;
		}
		if(flag==1)
			break;
		else
		{
			getchar();
			printf("\n=====>学号 %s 不存在，请重试？(y/n):",s);
			scanf("%c",&ch);
			if(ch=='y'||ch=='Y')
			{continue;}
			else
				{return;} 
		}		
	}
	stringinput(num,10,"输入新学号");
	v=l->next;
	while(v)
	{
		if(strcmp(v->data.num,num)==0)
		{
			printf("=====>抱歉,新学号'%s' 已存在！\n",num);
			//printheader();
			printdata(v);
			printf("\n");
			getchar();
			return;
		}	
		v=v->next;
	}
	newinfo=(Node *)malloc(sizeof(Node));
	if(!newinfo)
	{
		printf("\n 分配内存故障");
		return ;
	} 
	//修改学生信息 
	strcpy(newinfo->data.num,num);
	stringinput(newinfo->data.name,15,"姓名：");
	newinfo->data.Chinese=numberinput("语文成绩[0-100]：");
	newinfo->data.Math=numberinput("数学成绩[0-100]：");
	newinfo->data.English=numberinput("英语成绩[0-100]：");
	newinfo->data.HTML=numberinput("WEB前端开发成绩[0-100]：");
	newinfo->data.Integrated_Network_cabling=numberinput("综合网络布线成绩[0-100]：");
	newinfo->data.SQLSEVER=numberinput("数据库成绩[0-100]：");
	newinfo->data.total=newinfo->data.Chinese+newinfo->data.Math+newinfo->data.English+newinfo->data.HTML+newinfo->data.Integrated_Network_cabling+newinfo->data.SQLSEVER;
	newinfo->data.ave=(float)(newinfo->data.total/6);
	newinfo->data.topnum=0;
	newinfo->next=NULL;
	saveflag=1;
	p=l->next;
	while(1)
	{
		if(strcmp(p->data.num,s)==0)
		{
			newinfo->next=p->next;
			p->next=newinfo;
			break;
		}
		p=p->next;
	}
	Disp(l);
	printf("\n\n");
	getchar();
}
//统计学生成绩 
void Tongji(Link l)
{
	Node *pt,*pc,*pm,*pe,*ph,*pinc,*psql;
	Node *r=l->next;
	int countc=0,countm=0,counte=0,counth=0,countinc=0,countsql=0;
	if(!r)
	{
		system("cls");
		printf("\n=====>未找到该生记录\n");
		Sleep(3000);
		getchar();
		return ;
	}
	system("cls");
	Disp(l);
	pc=pm=pe=ph=pinc=psql=pt=r;
	while(r)
	{
		if(r->data.Chinese<60)countc++;
		if(r->data.Math<60)countm++;
		if(r->data.English<60)counte++;
		if(r->data.HTML<60)counth++;
		if(r->data.Integrated_Network_cabling<60)countinc++;
		if(r->data.Chinese>=pc->data.Chinese)pc=r;
		if(r->data.Math>=pm->data.Math)pm=r;
		if(r->data.English>=pe->data.English)pe=r;
		if(r->data.HTML>=ph->data.HTML)ph=r;
		if(r->data.Integrated_Network_cabling>=pinc->data.Integrated_Network_cabling)pinc=r;
		if(r->data.SQLSEVER>=psql->data.SQLSEVER)psql=r;
		r=r->next;
	}
	printf("--------------------不及格--------------------\n");
	printf("语文成绩<60：%d (人)\n",countc);
	printf("数学成绩<60：%d (人)\n",countm);
	printf("英语成绩<60：%d (人)\n",counte);
	printf("WEB前端开发成绩<60：%d (人)\n",counth);
	printf("综合网络布线<60：%d (人)\n",countinc);
	printf("数据库<60：%d (人)\n",countsql);
	printf("-------------------------------------------------------------\n");
	printf("最高分（总分）：%s 总分成绩：%d\n",pt->data.name,pt->data.total);
	printf("最高分（语文）：%s 语文成绩：%d\n",pc->data.name,pc->data.Chinese);
	printf("最高分（数学）：%s 数学成绩：%d\n",pm->data.name,pm->data.Math);
	printf("最高分（英语）：%s 英语成绩：%d\n",pe->data.name,pe->data.English);
	printf("最高分（WEB前端开发）：%s WEB前端开发成绩：%d\n",ph->data.name,ph->data.HTML);
	printf("最高分（综合网络布线）：%s 综合网络布线成绩：%d\n",pinc->data.name,pinc->data.Integrated_Network_cabling);
	printf("最高分（数据库）：%s 数据库:%d\n",pinc->data.name,pinc->data.SQLSEVER);
	printf("\n\n 按任意键返回");
	getchar();
}
//学生排序 
void Sort(Link l)
{
	Link ll;
	Node *p,*rr,*s;
	int i=0,select;
	char ch,key;
	if(l->next==NULL)
	{
		system("cls");
		printf("\n=====>未找到该学生记录\n");
		getchar();
		return ;
	}
	ll=(Node*)malloc(sizeof(Node));
	if(!ll)
	{
		printf("\n 分配内存故障");
		return;	
	} 
	ll->next=NULL;
	system("cls");
	Disp(l);
	p=l->next;
	while(p)
	{
		s=(Node*)malloc(sizeof(Node));
		if(!s)
		{
			printf("\n 分配内存故障");
			return;
			s->data=p->data;
			s->next=NULL;
			rr=ll;
			while(rr->next!=NULL&&rr->data.total>=p->data.total)
			{rr=rr->next;}
			if(rr->next==NULL)
				rr->next=s;
			else
			{
				s->next=rr->next;
				rr->next=s;
			}
			p=p->next;
		}
		l->next=ll->next;
		p=l->next;
		while(p!=NULL)
		{
			i++;
			p->data.topnum=i;
			p=p->next;
		}
		Disp(l);
		saveflag=1;
		printf("\n	=====>排序成功\n");
	}
}
//保存 
void Save(Link l)
{
	FILE* fp;
	Node *p;
	int count=0;
	fp=fopen("c:\\RESULT.txt","wb");//成绩结果保存地址 
	if(fp==NULL)
	{
		printf("\n=====>打开文件失败\n");
		getchar();
		return ;
	}
	p=l->next;
	while(p)
	{
		if(fwrite(p,sizeof(Node),1,fp)==1)//写入成功 
		{
			p=p->next;
			count++;
		}
		else
		{
			break;
		}
		getchar();
	}
	if(count>0)
	{
		getchar();
		printf("\n\n\n\n\n=====>文件保存成功\n");
		getchar();
		saveflag=0;
	}
	else
	{
		system("cls");
		printf("当前数据为空,没有学生记录被保存。\n");
		getchar();	
	}	
	fclose(fp);
}
int main()
{
	Link l;
	FILE *fp;
	int select;
	char ch;
	int count=0,key;
	Node *p,*r;
	l=(Node*)malloc(sizeof(Node));
	if(!l)
	{
		printf("\n 分配内存故障");
		return 0;
	}
	l->next=NULL;
	r=l;
	fp=fopen("C:\\RESULT","ab+");
	if(fp==NULL)
	{
		printf("=====>可以打开文件\n");
		exit(0);
	}
	while(!feof(fp))
	{
		p=(Node*)malloc(sizeof(Node));
		if(!p)
		{
			printf("内存分配故障！\n");
			exit(0);//正常退出 
		}
		if(fread(p,sizeof(Node),1,fp)==1)//读取成功 
		{
			p->next=NULL;
			r->next=p;
			r=p;
			count++;
		}
	}
	fclose(fp);
	printf("\n=====>文件保存成功\n");
	menu();
	while(1)
	{
		system("cls");
		menu();
		p=r;
		printf("\n			请选择(0~9):");
		scanf("%d",&select);//选择功能 
		if(select==0)
		{
			if(saveflag=1)
			{
				getchar();
				printf("\n=====>是否保存修改记录去文件(y/n):");
				scanf("%c",&ch);
				if(ch=='y'||ch=='Y')
					Save(l); 
			}
			printf("=====>感谢为您服务！");
			getchar();
			break;
		}
		switch(select)
		{
			case 1:Add(l);break;
			case 2:Del(l);break;
			case 3:Qur(l);break;
			case 4:Modify(l);break;
			case 5:Insert(l);break;
			case 6:Tongji(l);break;
			case 7:Sort(l);break;
			case 8:Save(l);break;
			case 9:system("cls");Disp(l);break;
			default:Wrong();getchar();break;
		}
	}
	return 0;
}
