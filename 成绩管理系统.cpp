#include<bits/stdc++.h>
#include<conio.h>
#define HEADER1 "-------------------STUDENT----------------------------\n"
#define HEADER2 "      |    number    |    name    |bikinggrade|swimminggrade|topnum|    total    |sum|ave    |mici    | \n"
#define HEADER3 "|--------|--------|----|----|----|--------|--------|--------|" 
#define FORMAT "     |  %-10s |%-15s|%4d|%4d|%4d| %4d    |%.2f |%4d|\n"
#define DATA p->data.num,p->data.name,p->data.bikinggrade,p->data.swimminggrade,p->data.programminggrade,p->data.topnum
#define END "----------------------------------------------------------------------------\n"
using namespace std;
int saveflag=0;
typedef struct student
{
	char num[10],name[10];
	int bikinggrade,swimminggrade,programminggrade,topnum;
	int total;
	float ave;
}student;
typedef struct node{
	struct student data;
	struct node *next;
}Node,*Link;
int gotoxy(int x,int y)
{ 
	
} 
void menu()
{
	system("cls");
	//textcolor(10);
	printf("         The Students' Grade Management System \n");
	gotoxy(10,8);
	printf("****************************Menu********************************************\n");
	gotoxy(10,9);
	printf("            * 1 input record                2 delete record           *\n");
	gotoxy(10,10);
	printf("            * 3 search record                4 modify record           *\n");
	gotoxy(10,11);
	printf("            * 5 insert record                6 count record           *\n");
	gotoxy(10,12);
	printf("            * 7 insert record                8 count record           *\n");
	gotoxy(10,13);
	printf("            * 9 insert record                0 count record           *\n");
	gotoxy(10,14);
	printf("***********************************************************************************************\n");
	
}
void printdata(Node *pp)
{
	Node *p;
	p=pp;
	printf(FORMAT,DATA);	
} 
void Wrong()
{
	printf("\n\n\n\n\n\n********Error:input has wrong! press any key to continue**********\n");
	getchar();
}
void Nofind()
{
	printf("\n==========>Not find this student!\n");
}
void Disp(Link l)
{
	Node *p;
	p=l->next;
	if(!p)
	{
		printf("\n========>Not student record!\n");
		getchar();
		return;
	}
	printf("\n\n");
	//printheader();
	while(p)
	{
		printdata(p);
		p=p->next;
		printf(HEADER3);
	}
	getchar(); 
}
void stringinput(char t[255],int lens,char *notice)
{
	char n[255];
	do{
		printf(notice);
		scanf("%s",n);
		if(strlen(n)>lens)printf("\n exceed the required length!    \n");
	}while(strlen(n)>lens);
	strcpy(t,n);
}
int numberinput(char *notice)
{
	int t=0;
	do{
		printf(notice);
		scanf("%d",&t);
		if(t>100||t<0)printf("\n score must in [0,100]!\n");
	}while(t>100||t<0);
	return t;
}
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
			stringinput(num,10,"input number(press '0'return menu):");
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
				printf("=====>The number %s isnot existing,try again?(y/n):",num);
				scanf("%c",&ch);
				if(ch=='y'||ch=='Y')
				continue;
				else
					return;
			}
			else
			{break;}
		}
		p=(Node *)malloc(sizeof(Node));
		if(!p)
		{
			printf("\n allocate memory failure");
			return ;
		}
		strcpy(p->data.num,num);
		stringinput(p->data.name,15,"Name:");
		p->data.bikinggrade=numberinput("Biking scores[0-100]");
		p->data.swimminggrade=numberinput("Swimming scores[0-100]");
		p->data.programminggrade=numberinput("Programminggrade scores[0-100]");
		p->data.total=p->data.programminggrade+p->data.swimminggrade+p->data.bikinggrade;
		p->data.ave=(float)(p->data.total/3);
		p->next=NULL;
		r->next=p;
		r=p;
		saveflag=1; 
	}
	return;
}
void Qur(Link l)
{
	int select;
	char searchinput[20];
	Node *p;
	if(!l->next)
	{
		system("cls");
		printf("\n=====>No student record!\n");
		getchar();
		return;
	}
	system("cls");
	printf("\n    =====>l Search by number =====>2 Search by name\n");
	scanf("%d",&select);
	if(select==1)
	{
		stringinput(searchinput,10,"input the existing student number:");
		p=Locate(l,searchinput,"num");
		if(p)
		{
			//printheader();
			printdata(p);
			printf(END);
			printf("press any key to return");
			getchar();
		}
		else
		Nofind();
		getchar();
	}
	else if(select==2)
	{
		stringinput(searchinput,15,"input the existing student name:");
		p=Locate(l,searchinput,"name");
		if(p)
		{
			//printheader();
			printdata(p);
			printf(END);
			printf("press any key to return");
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
		printf("\n=====>No student record!\n");
		getchar();
		return;
	} 
	system("cls");
	Disp(l);
	printf("\n =====>1 Delete by number =====>2 Delete by name\n");
	printf("     please choice[1,2]:");
	scanf("%d",&sel);
	if(sel==1)
	{
		stringinput(findmess,10,"input the existing student number:");
		p=Locate(l,findmess,"num");
		if(p)
		{
			r=l;
			while(r->next!=p)
			r=r->next;
			r->next=p->next;
			free(p);
			printf("\n=====>delete success!\n");
			getchar();
			saveflag=1;
		}
		else
			Nofind();
			getchar();
	}
	else if(sel==2)
	{
		stringinput(findmess,15,"input the existing student name");
		p=Locate(l,findmess,"name");
		if(p)
		{
			r=l;
			while(r->next!=p)
			r=r->next;
			r->next=p->next;
			free(p);
			printf("\n=====>delete success!\n");
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
void Modify(Link l)
{
	Node *p;
	char findness[20];
	if(!l->next)
	{
		system("cls");
		printf("\n=====>No student record!\n");
		getchar();
		return;
	}
	system("cls");
	printf("modity student recorder");
	Disp(l);
	stringinput(findness,10,"input the existing student number");
	p=Locate(l,findness,"num");
	if(p)
	{
		printf("Number:%s,\n",p->data.num);
		printf("Number:%s,",p->data.name);
		stringinput(p->data.name,15,"input new game:");
		printf("Biking score:%d",p->data.bikinggrade);
		p->data.bikinggrade=numberinput("Biking Score:[0-100]:");
		printf("Swimming score:%d,",p->data.swimminggrade);
		p->data.swimminggrade=numberinput("Swimminggrade Score:[0-100]");
		printf("Programming score:%d,",p->data.programminggrade);
		p->data.total=p->data.bikinggrade+p->data.swimminggrade+p->data.bikinggrade;
		p->data.ave=(float)(p->data.total/3);
		p->data.topnum=0;
		printf("\n=====>modify success!\n");
		Disp(l);
		saveflag=1;
	}
	else{
		Nofind();
		getchar();
	}
}
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
		stringinput(s,10,"please input insert location after the Number");
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
			printf("\n=====>The number %s is not existing,try again?(y/n):",s);
			scanf("%c",&ch);
			if(ch=='y'||ch=='Y')
			{continue;}
			else
				{return;} 
		}		
	}
	stringinput(num,10,"input new Number");
	v=l->next;
	while(v)
	{
		if(strcmp(v->data.num,num)==0)
		{
			printf("=====>Sorry,the new number:'%s' is existing!\n",num);
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
		printf("\n allocate memory failure");
		return ;
	} 
	strcpy(newinfo->data.num,num);
	stringinput(newinfo->data.name,15,"Name:");
	newinfo->data.bikinggrade=numberinput("BIKINGGRADE SCORES[0-100]:");
	newinfo->data.programminggrade=numberinput("PROGRAMMINGGRADE SCORES[0-100]:");
	newinfo->data.swimminggrade=numberinput("SWIMMINGGRADE SCORES[0-100]:");
	newinfo->data.total=newinfo->data.bikinggrade+newinfo->data.programminggrade+newinfo->data.swimminggrade;
	newinfo->data.ave=(float)(newinfo->data.total/3);
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
void Tongji(Link l)
{
	Node *pb,*pp,*ps,*pt;
	Node *r=l->next;
	int countb=0,countp=0,counts=0;
	if(!r)
	{
		system("cls");
		printf("\n=====>Not student record!\n");
		getchar();
		return ;
	}
	system("cls");
	Disp(l);
	pb=pp=ps=r;
	while(r)
	{
		if(r->data.bikinggrade<60)countb++;
		if(r->data.programminggrade<60)countp++;
		if(r->data.swimminggrade<60)counts++;
		if(r->data.bikinggrade>=pb->data.bikinggrade)pb=r;
		if(r->data.programminggrade>=pp->data.programminggrade)pp=r;
		if(r->data.swimminggrade>=pb->data.swimminggrade)ps=r;
		r=r->next;
	}
	printf("--------------------the Statistics result--------------------\n");
	printf("BIKINGGRADE<60:%d (ren)\n",countb);
	printf("PROGRAMMINGGRADE<60:%d (ren)\n",countp);
	printf("SWIMMINGGRADE<60:%d (ren)\n",counts);
	printf("-------------------------------------------------------------\n");
	printf("The highest student by total    scores    name:%s totoal scores:%d\n",pt->data.name,pt->data.total);
	printf("The highest student by SWIMMINGGRADE    scores    name:%s SWIMMINGGRADE scores:%d\n",ps->data.name,ps->data.total);
	printf("The highest student by PROGRAMMINGGRADE    scores    name:%s PROGRAMMINGGRADE scores:%d\n",pp->data.name,pp->data.total);
	printf("The highest student by BIKINGGRADE    scores    name:%s BIKINGGRADE scores:%d\n",pb->data.name,pb->data.total);
	printf("\n\n press any key to return");
	getchar();
}
void Sort(Link l)
{
	Link ll;
	Node *p,*rr,*s;
	int i=0;
	if(l->next==NULL)
	{
		system("cls");
		printf("\n=====>Not student record!\n");
		getchar();
		return ;
	}
	ll=(Node*)malloc(sizeof(Node));
	if(!ll)
	{
		printf("\n allocate memory failure");
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
			printf("\n allocate memory failure");
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
			p->data.total=i;
			p=p->next;
		}
		Disp(l);
		saveflag=1;
		printf("\n	=====>sort complete!\n");
	}
}

void Save(Link l)
{
	FILE* fp;
	Node *p;
	int count=0;
	fp=fopen("c:\\SPORT","wb");
	if(fp=NULL)
	{
		printf("\n=====>open file error!\n");
		getchar();
		return ;
	}
	p=l->next;
	while(p)
	{
		if(fwrite(p,sizeof(Node),1,fp)==1)
		{
			p=p->next;
			count++;
		}
		else
		{
			break;
		}
	}
	if(count>0)
	{
		getchar();
		printf("\n\n\n\n\n=====>save file complete,total saved's record number is:%d\n",count);
		getchar();
		saveflag=0;
	}
	else
	{
		system("cls");
		printf("the current link is empty,no student record is saved!\n");
		getchar();	
	}	
	fclose(fp);
}
