#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <conio.h>
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;


struct student
{
    int id;//读者编号
    string name;//读者姓名
    int borrowsum;//你已借阅多少本书,默认为0
    int number;//现在还有多少本书未还，默认为0
    string borrowday;//上次借阅时间，默认为0000.00.00
    int b[15];//你所借书的的编号，最多15本
};
struct Librarian
{
    int id;//管理员编号 
};
struct book
{
    int idnum;//图书检索号
    int BorrowCount;//图书借阅量,初始化为0
    string name;//书名
    string kind;//图书种类
    double price;//图书价格
    int sum;//图书总库存存量
    int nowsum;//图书现库存量
    string author;//图书作者
    int appointment;//图书预约量,初始化为0
    bool ok;//是否可借,初始为可以
    string borrowdate;//图书最近一次借出时间，默认为0000-00-00；
    string returndate;//图书最近一次归还时间，默认为0000-00-00；
    string room;//馆藏地
};
bool cmpByidnum(book a,book b)
{
    return a.idnum<b.idnum;
}
bool cmpByCount(book a,book b)
{
    return a.BorrowCount>b.BorrowCount;
}
bool cmpByBorrowsum(student a,student b)
{
    return a.borrowsum>b.borrowsum;
}
bool cmpByid(student a,student b)
{
    return a.id<b.id;
}
class Library
{
private:
    int borrownum;//每月借出书数量
    int returnnum;//每月还书数量
    vector<book> data;
    vector<student> data1;
    vector<int> betoli;//预约书到馆，储存其编号
public:
    Library();
    void AddBook(book NewBook);  //增加图书
    void DeleteBook(string bookname,string author);//删除图书
    void BorrowBook(string name,string author);//借阅图书
    void BackBook(string name,string author,int k);//归还图书
    void ShowAllBook(); //输出系统所有图书
    void SearchBookPosWithname(string thebook); //按书名查询
    void SearchBookPosWithAuthor(string theauthor);//按作者查询
    void SearchBookPosWithKind(string kind);//按种类查询
    int  SearchBookPosWithAB(string theauthor,string thebook);//按作者和书名查询
    int  SearchBookPosWithid(int id); //按检索号搜寻
    void SortBook(int ca);  //排序
    void SortStudent(int ca);//按读者借阅量排序
    void Save();  //存入图书馆文件
    void Save1();//存入学生文件
    void Appointment(string bookname,string author);//预约图书
    void printbook(book a);//输出某本书的所有信息
    void revisebook(string name,string author);//修改某本书的信息
    int SerchStudent(int id);//查询某个读者
    //int SerchStudent1(int id);//查询某个读者
    void AddStudent(student a);//增加一个读者
    void AddLibrarian(student a);//增加一个管理员 
    void PrintStudent(int kid);//输出读者信息
    int GetStudent();//返回读者总数
    int readsum(int id);//获取某个读者的借阅量
    int getborrownum();//获取本月外借量
    int getreturnnum();//获取本月还书量
    void PrintToLi();//输出到馆预约书

};
Library::Library()
{
    borrownum=0;
    returnnum=0;
    int AllBook,AllStudent;
    ifstream fin("book.txt");
    if(fin)
    {
        fin>>AllBook;
        for(int i=0; i<AllBook; i++)
        {
            book tem;
            fin>>tem.idnum>>tem.name>>tem.author>>tem.price>>tem.kind>>tem.room>>tem.sum>>tem.nowsum>>tem.BorrowCount>>tem.ok>>tem.appointment>>tem.borrowdate>>tem.returndate;
            data.push_back(tem);
        }
        fin.close();
    }
    //cin.clear();
    //cin.sync();
    ifstream tfin("student.txt");
    if(tfin)
    {
        tfin>>AllStudent;
        for(int i=0; i<AllStudent; i++)
        {
            student tem;
            tfin>>tem.id>>tem.name>>tem.borrowsum>>tem.number>>tem.borrowday;
            for(int j=0;j<10;j++)
            {
                tfin>>tem.b[j];
            }
            data1.push_back(tem);
        }
        tfin.close();
    }
}
int Library::readsum(int a)
{
    //SortStudent(1);
    return data1[a-1].borrowsum;
}
int Library::getborrownum()//获取本月外借量
{
    return borrownum;
}
int Library::getreturnnum()//获取本月还书量
{
    return returnnum;
}
int Library::GetStudent()
{
    int k=(int)data1.size();
    return k+1;
}
void Library::AddBook(book NewBook)
{
    data.push_back(NewBook);
}
void Library::AddStudent(student newstudent)
{
    data1.push_back(newstudent);
}
void Library::DeleteBook(string bookname,string author)
{
    int pos = SearchBookPosWithAB(author,bookname);
    if (pos!=-1)
    {
        data.erase(data.begin()+pos);
        return ;
    }
    else
        cout<<"No such book found!\n";
}
void Library::BorrowBook(string name,string author)
{
    string BorrowDate;
    string BackDate;
    char c;
    int flag=0;
    SortStudent(1);
    int sid=-1;
    for (int i = 0; i <(int)data.size(); i++)
    {
        if (data[i].name==name&&data[i].author==author)
        {
            if(data[i].nowsum)
            {
                cout<<"The reader ID of the borrowing reader is: (Enter 0 to exit)";
                cin>>sid;
                if(sid==0)break; 
                if(data1[sid-1].number>15)
                {
                    cout<<"Now you have borrowed 15 books at the same time! No more borrowing!"<<endl;
                    break;
                }
                flag=1;
                data[i].nowsum=data[i].nowsum-1;
                data[i].BorrowCount=data[i].BorrowCount+1;
                cout<<"Please enter the borrowing date"<<endl;
                cin>>BorrowDate;
                data[i].borrowdate=BorrowDate;
                cout<<"Please enter the expected return date (up to one month can be borrowed)"<<endl;
                cin>>BackDate;
                data[i].returndate=BackDate;
                data[i].ok=bool(data[i].nowsum);
                borrownum++;
                data1[sid-1].number++;
                for(int j=0;j<15;j++)
                {
                    if(data1[sid-1].b[j]==0)
                    data1[sid-1].b[j]=data[i].idnum;
                    Save();
                    Save1();
                }
            }
            else
            {
                cout<<"~~~~(>_<)~~~~ ! wuuu....This book has been borrowed! Do you want to make an appointment?Y/N"<<endl;
                cin>>c;
                c=toupper(c);
                if(c=='Y')
                    data[i].appointment++;
            }
        }
    }
    if(!flag)
        cout<<"Sorry, the book you are looking for was not found."<<endl;
}
void Library::BackBook(string name,string author,int k)//k表示还书途径
{
    int c=-1;
    SortStudent(1);
    if(k!=-1)//读者自助还书
    {
        c=k-1;
    }
    else//读者通过借还总台还书
    {
        cout<<"请输入你的读者号：Please enter your reader ID:";
        cin>>c;
        c=c-1;
    }
    for (int i = 0; i <(int)data.size(); i++)
    {
        if (data[i].name==name&&data[i].author==author)
        {
            data[i].nowsum=data[i].nowsum+1;
            data[i].ok=bool(data[i].nowsum);
            returnnum++;
            if(data[i].appointment!=0)
            {
                data[i].appointment--;
                betoli.push_back(data[i].idnum);
            }
            for(int j=0;j<10;j++)
                {
                    if(data1[c].b[j]==data[i].idnum)
                        data1[c].b[j]=0;
                }
                data1[c].number--;
            break;
        }
    }
    Save();
    Save1();
}
void Library::printbook(book a)
{
    cout<<setw(8)<<a.idnum<<"|";
    cout<<setw(14)<<a.name<<"|";
    cout<<setw(14)<<a.author<<"|";
    cout<<setw(14)<<fixed<<setprecision(2)<<a.price<<"|";
    cout<<setw(14)<<a.kind<<"|";
    cout<<setw(14)<<a.room<<"|";
    cout<<setw(14)<<a.sum<<"|";
    cout<<setw(14)<<a.nowsum<<"|";
    cout<<setw(14)<<a.BorrowCount<<"|";
    cout<<setw(10)<<(a.ok==0?"Not lendable":"Lendable");
    cout<<setw(14)<<a.appointment<<"|";
    cout<<setw(14)<<a.borrowdate<<"|";
    cout<<setw(14)<<a.returndate<<"|"<<endl;
    // cout<<endl;
}
void Library::PrintToLi()
{
    SortBook(1);
    int k=(int)betoli.size();
    if(!k) cout<<"     There is currently no appointment book available!"<<endl;
    else
    {
        cout<<"        The appointment forms for arriving at the library include:\n";
        for(int i=0;i<k;i++)
        {
            printbook(data[betoli[i]-1]);
        }
    }
}
void Library::PrintStudent(int kid)
{
    int id=kid-1;
    //id=SerchStudent(id);
    SortStudent(1);
    SortBook(1);
    //SortStudent(1);
    cout<<setw(8)<<data1[id].id;
    cout<<setw(8)<<data1[id].name;
    cout<<setw(14)<<data1[id].borrowsum;
    cout<<setw(18)<<data1[id].number;
    cout<<setw(14)<<data1[id].borrowday<<endl;
    if(data1[id].number!=0)
    {
        cout<<"You are currently borrowing these books:\n";
        cout<<setw(16)<<"Accession number"<<setw(16)<<"Book name"<<setw(16)<<"Author"<<endl;
        for(int i=0;i<15;i++)
        {
            if(data1[id].b[i]!=0)
            cout<<setw(16)<<data[data1[id].b[i]-1].idnum<<setw(16)<<data[data1[id].b[i]-1].name<<setw(16)<<data[data1[id].b[i]-1].author<<endl;
        }
    }
    else
        cout<<"You haven't borrowed any books currently, go borrow a book and take a look!\n";
}
void Library::ShowAllBook()
{
    cout<<setw(8)<<"|Accession number|"<<setw(14)<<"Book name|"<<setw(14)<<"Author|"<<setw(14)<<"Price|"<<setw(14)<<"Type|"<<setw(14)<<"Library storage area|"<<setw(14)<<"Total inventory|"<<setw(14)<<"Quantity in the library|"<<setw(14)<<"Book borrowing volume|"<<setw(10)<<"Whether or not borrowing|"<<setw(14)<<"Reservation quantity|";
    cout<<setw(14)<<"Borrow Time|"<<setw(14)<<"Return time|"<<endl;
    for (int i = 0; i <(int)data.size(); i++)
    {
        printbook(data[i]);
    }
}
int Library::SerchStudent(int id)
{
    int m=-1;
     for (int i = 0; i <(int)data1.size(); i++)
     {
        if (data1[i].id==id)
        {
            return i;
        }
     }
     return m;
 }
void Library::SearchBookPosWithname(string thebook)//按书名查询
{
    int flag=0;
    for (int i = 0; i <(int)data.size(); i++)
    {
        if (data[i].name==thebook)
        {
            printbook(data[i]);
            flag=1;
        }
    }
    if(!flag) cout<<"No such books found!\n";
}
void Library::SearchBookPosWithAuthor(string theauthor)//按作者查询
{
    bool flag=false;
    for (int i = 0; i <(int)data.size(); i++)
    {
        if (data[i].author==theauthor)
        {
            flag=true;
            printbook(data[i]);
        }
    }
    if(!flag) cout<<"No book by this author found!";
}
void Library::SearchBookPosWithKind(string kind)//按种类查询
{
    bool flag=false;
    for (int i = 0; i <(int)data.size(); ++i)
    {
        if (data[i].kind==kind)
        {
            flag=true;
            printbook(data[i]);
        }
    }
    if(!flag) cout<<"No such books found!";
}
int Library::SearchBookPosWithAB(string theauthor,string thebook)//按作者和书名查询
{
    for (int i = 0; i <(int)data.size(); ++i)
    {
        if (data[i].author==theauthor&&data[i].name==thebook)
        {
            printbook(data[i]);
            return i;
        }
    }
    cout<<"No such books found!";
    return -1;
}
int Library::SearchBookPosWithid(int id)
{
    for (int i = 0; i <(int)data.size(); i++)
    {
        if (data[i].idnum==id)
        {
            return i;
        }
    }
    return -1;
}
void Library::SortBook(int ca)  //排序
{
    if (ca==0)   //按借阅量排序
    {
        sort(data.begin(),data.end(),cmpByCount);
    }
    else    //按检索号排序
    {
        sort(data.begin(),data.end(),cmpByidnum);
    }
}
void Library::SortStudent(int ca)
{
    if(ca==0)//按借阅量排序
        sort(data1.begin(),data1.end(),cmpByBorrowsum);
    else
        sort(data1.begin(),data1.end(),cmpByid);//按读者号排序
}
void Library::Save() //存入书籍文件
{
    ofstream fout("book.txt");
    if (fout)
    {
        fout<<data.size()<<endl;
        //book p;
        for (int i = 0; i <(int)data.size(); i++)
        {
            fout<<data[i].idnum<<" "<<data[i].name<<" "<<data[i].author<<" "<<data[i].price<<" "<<data[i].kind<<" "<<data[i].room<<" "<<data[i].sum<<" "<<data[i].nowsum<<" "<<data[i].BorrowCount<<" "<<data[i].ok<<" "<<data[i].appointment<<" "<<data[i].borrowdate<<" "<<data[i].returndate<<" "<<endl;
        }
        fout.close();
    }
}
void Library::Save1() //存入学生文件
{
    ofstream fout("student.txt");
    if (fout)
    {
        fout<<data1.size()<<endl;
        //student p;
        for (int i = 0; i <(int)data1.size(); i++)
        {
            fout<<data1[i].id<<" "<<data1[i].name<<" "<<data1[i].borrowsum<<" "<<data1[i].number<<" "<<data1[i].borrowday;
            for(int j=0;j<10;j++)
            {
                fout<<" "<<data1[i].b[j];
            }
            fout<<endl;
        }
        fout.close();
    }
}
void Library::revisebook(string name,string author)//修改图书
{
    string Room,Kind;
    int num,k=0;
    printf("What do you want to modify:\n");
    printf("                 1.Library storage area modify\n");
    printf("                 2.Total Book Inventory Modification\n");
    printf("                 3.Revision of the type of book\n");
    printf("                 4.Exit\n");
    for (int i = 0; i <(int)data.size(); i++)
    {
        if (data[i].author==author&&data[i].name==name)
        {
            k=i;
            break;
        }
    }
    int cho;
    do
    {
        cin>>cho;
        switch(cho)
        {
        case 1:
        {
            cout<<"Please enter new library storage area\n";
            cin>>Room;
            data[k].room=Room;
            break;
        }
        case 2:
        {
            cout<<"Please enter new total inventory:\n";
            cin>>num;
            data[k].sum=num;
            break;
        }
        case 3:
        {
            cout<<"Please enter the new category of the book:\n";
            cin>>Kind;
            data[k].kind=Kind;
            break;
        }
        }
    }
    while(cho<4);
}
void Library::Appointment(string bookname,string author)//预约图书
{
    for (int i = 0; i <(int)data.size(); i++)
    {
        if (data[i].author==author&&data[i].name==bookname)
        {
            if(data[i].nowsum>0) printf("There are books in the library, you don't need to make an appointment!\n");
            else
            {
                data[i].appointment++;
                printf("Appointment successful!");
            }
        }
    }
}

int main()
{
	
	system("color 4F");
    cout.setf(ios::left);//左对齐
    Library mybook;
    student temp;
    char mima[5];//密码数组
    int n;
   // mybook.PrintStudent(0);
   start1:
   	system("cls");
    cout<<"                                                   Welcome to the Book Borrowing Management System"<<endl;
    cout<<"Please select your login option:\n";
    cout<<"                  1.Administrator Login"<<endl;
    cout<<"                  2.Reader login"<<endl;
    int cho,start,kk=1;
    cin>>start;
    system("cls");
    switch(start)
    {
        case 1:
       {
       		auto char password[]="20101";
	        cout<<"Please enter the administrator password:";
	        do{
	            kk=1;
		        for(int i=0;i<5;i++)
		        {
			        mima[i]=getch();
			        cout<<"*";
		        }
		        cout<<endl;
	            for(int i=0;i<5;i++)
	            {
		            if (mima[i]!=password[i])
		            {
		                cout<<"Please enter the correct password!"<<endl;
		                kk=0;
		                break;
		            }
	            }
	        }while(!kk);
	        do
	        {
	        	system("cls");
	        	start3:
	           	cout<<"                                  Welcome to the Book Borrowing Management System"<<endl;
	            cin.clear();
	            cin.sync();
	            cout<<"              1.All book catalogs "<<endl;
	            cout<<"              2.Search for books "<<endl;
	            cout<<"              3.Add books "<<endl;
	            cout<<"              4.Delete book "<<endl;
	            cout<<"              5.Borrowing books "<<endl;
	            cout<<"              6.Returning Books "<<endl;
	            cout<<"              7.Modifying Book Information "<<endl;
	            cout<<"              8.Borrow and return statistics for this month"<<endl;
	            cout<<"              9.Appointment book arrival status "<<endl;
	            cout<<"              10.Exit "<<endl;
	            cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
	            cout<<"              Please select the function and enter the command "<<endl;
	            cin>>cho;
	            switch(cho)
	            {
	            case 1:
	            {
	                int cho2;
	                do
	                {
	                    mybook.ShowAllBook();
	                    cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	                    cout<<"0: Sort by borrowing amount, 1: Sort by index number, 2: Exit"<<endl;
	                    cin>>cho2;
	                    switch(cho2)
	                    {
	                    case 0:
	                        mybook.SortBook(0);
	                        break;
	                    case 1:
	                        mybook.SortBook(1);
	                        break;
	                    }
	                }
	                while (cho2<2);
	                break;
	            }
	            case 2:
	            {
	                cout<<"              1.Search by book name "<<endl;
	                cout<<"              2.Query by Author "<<endl;
	                cout<<"              3.Query by category "<<endl;
	                cout<<"              4.Search by book title and author "<<endl;
	                cout<<"              5.Exit "<<endl;
	                cout<<"              Please select the function and enter the command "<<endl;
	                int cho3;
	                do
	                {
	                    string Name,AutHor,Kind;
	                    cin>>cho3;
	                    switch(cho3)
	                    {
	                    case 1:
	                        cout<<"Please enter the book name!"<<endl;
	                        cin>>Name;
	                        mybook.SearchBookPosWithname(Name); //按书名查询
	                        break;
	                    case 2:
	                        cout<<"Please enter the author!"<<endl;
	                        cin>>AutHor;
	                        mybook.SearchBookPosWithAuthor(AutHor);//按作者查询
	                        break;
	                    case 3:
	                        cout<<"Please enter the type!"<<endl;
	                        cin>>Kind;
	                        mybook.SearchBookPosWithKind(Kind);//按种类查询
	                        break;
	                    case 4:
	                        cout<<"Please enter the author and book name!"<<endl;
	                        cin>>AutHor>>Name;
	                        mybook.SearchBookPosWithAB(AutHor,Name);//按作者和书名查询
	                        break;
	                    }
	                }
	                while(cho3<=4&&cho3>=1);
	                break;
	            }
	            case 3:         //增加图书
	            {
	                book temp;
	                cout<<"Please enter the search number:";
	                cin>>temp.idnum;
	                while (mybook.SearchBookPosWithid(temp.idnum)>-1)
	                {
	                    cout<<"The search number is duplicated! ~~~~(>_<)~~~~ !"<<endl;
	                    cin>>temp.idnum;
	                }
	                cin.clear();
	                cin.sync();
	                cout<<"Book name:";
	                cin>>temp.name;
	                cout<<"Author：";
	                cin>>temp.author;
	                cout<<"Price:";
	                cin>>temp.price;
	                cout<<"Type:";
	                cin>>temp.kind;
	                cout<<"Library Collection Address:";
	                cin>>temp.room;
	                cout<<"Number:";
	                cin>>temp.sum;
	                temp.nowsum=temp.sum;
	                temp.BorrowCount=0;
	                temp.ok=true;
	                temp.appointment=0;
	                temp.borrowdate="0000.00.00";
	                temp.returndate="0000.00.00";
	                mybook.AddBook(temp);
	                mybook.Save();
	                cout<<"Information saved successfully"<<endl;
	                break;
	            }
	            case 4:         //删除图书
	            {
	                string bookname,bookauthor;
	                cout<<"Please enter the book name and author:"<<endl;
	                cin>>bookname>>bookauthor;
	                mybook.DeleteBook(bookname,bookauthor);
	                break;
	            }
	            case 5:         //借书
	            {
	                string bookname,bookauthor;
	                cout<<"Please enter the title and author of the book you want to borrow："<<endl;
	                cin>>bookname>>bookauthor;
	                mybook.BorrowBook(bookname,bookauthor);
	                mybook.Save();
	                break;
	            }
	            case 6:         //还书
	            {
	                string bookname,bookauthor;
	                cout<<"Please enter the title and author of the book to be returned："<<endl;
	                cin>>bookname>>bookauthor;
	                mybook.BackBook(bookname,bookauthor,-1);
	                mybook.Save();
	                break;
	            }
	            case 7:
	            {
	                string name,author;
	                cout<<"Please enter the title and author of the book you want to modify:"<<endl;
	                cin>>name>>author;
	                mybook.revisebook(name,author);
	                system("cls");
	                break;
	            }
	            case 8:
	            {
	                  printf("                     Borrow books %d times this month\n",mybook.getborrownum());
	                  printf("                     %d book returns this month\n",mybook.getreturnnum());
	                  system("cls");
	                  break;
	            }
	            case 9:
	            {
	                 mybook.PrintToLi();
	                 cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
	                 system("cls");
					 break;
	            }
	            }
	        }
	        while (cho<10);
	        system("cls");
	        goto start1;
	       // mybook.Save();
    }
    case 2:
    {
    	Library tsg;
        int bh,cho,k;
        cout<<"Please enter your reader ID:\n";
        cin>>bh;
        if(mybook.SerchStudent(bh)==-1)
        {
            int n;
            cout<<"You are not a reader of this system, do you want to register?\n";
            cout<<"                    1.Register\n";
            cout<<"                    2.I'll think about it again\n";
            cin>>n;
            student temp;
            if(n==1)
            {
                cout<<"Please enter your name:";
                cin>>temp.name;
                cin.clear();
                cin.sync();
                temp.id=mybook.GetStudent();
                temp.borrowsum=0;
                temp.number=0;
                temp.borrowday="0000.00.00";
                for(int i=0;i<10;i++)
                {
                    temp.b[i]=0;
                }
                mybook.AddStudent(temp);
                mybook.Save1();
                cout<<"Information saved successfully"<<endl;
                cout<<"                Registration successful! Please remember your reader number. If you forget, please contact the administrator!\n";
                cout<<"                Name:"<<temp.name<<endl;
                cout<<"                Reader ID："<<temp.id<<endl;
                k=temp.id;
                Sleep(5000);
            }
            else{
            	goto start1;

     		}
        }
        else
        {
            k=bh;
        }
        do
        {
        start2:
            system("cls");
            cout<<"                                  Welcome to the Book Borrowing Management System"<<endl;
            cin.clear();
            cin.sync();
            cout<<"              1.All book catalogs "<<endl;
            cout<<"              2.Search for books "<<endl;
            cout<<"              3.Returning books "<<endl;
            cout<<"              4.Book reservation"<<endl;
            cout<<"              5.View my borrowing information "<<endl;
            cout<<"              6.Scan the QR code to purchase books "<<endl;
            cout<<"              7.Exit "<<endl;
            cout<<"              Please select the function and enter the command "<<endl;
            cin>>cho;
            switch(cho)
            {
	            case 1:
	            {
	                int cho2;
	                do
	                {
	                    mybook.ShowAllBook();
	                    cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	                    cout<<"0: Sort by borrowing amount, 1: Sort by index number, 2: Exit"<<endl;
	                    cin>>cho2;
	                    switch(cho2)
	                    {
	                    case 0:
	                        mybook.SortBook(0);
	                        system("cls");
	                        break;
	                    case 1:
	                        mybook.SortBook(1);
	                        system("cls");
	                        break;
	                    }
	                }
	                while (cho2<2);
	                break;
	            }
	            case 2:
	            {
	                cout<<"              1.Search by Book Title "<<endl;
	                cout<<"              2.Query by Author "<<endl;
	                cout<<"              3.Query by category "<<endl;
	                cout<<"              4.Search by book title and author "<<endl;
	                cout<<"              5.Exit "<<endl;
	                cout<<"              Please select the function and enter the command "<<endl;
	                int cho3;
	                do
	                {
	                    string Name,AutHor,Kind;
	                    cin>>cho3;
	                    switch(cho3)
	                    {
	                    case 1:
	                        cout<<"Please enter the book name!"<<endl;
	                        cin>>Name;
	                        mybook.SearchBookPosWithname(Name); //按书名查询
							break;
	                    case 2:
	                        cout<<"Please enter the author name!"<<endl;
	                        cin>>AutHor;
	                        mybook.SearchBookPosWithAuthor(AutHor);//按作者查询
							break;
	                    case 3:
	                        cout<<"Please enter the type!"<<endl;
	                        cin>>Kind;
	                        mybook.SearchBookPosWithKind(Kind);//按种类查询
							break;
	                    case 4:
	                        cout<<"Please enter the author and book name!"<<endl;
	                        cin>>AutHor>>Name;
	                        mybook.SearchBookPosWithAB(AutHor,Name);//按作者和书名查询
							break;
	                    }
	                }
	                while(cho3<=4&&cho3>=1);
	                system("cls");
					goto start1;
	            }
	            case 3:         //还书
	            {
	                string bookname,bookauthor;
	                cout<<"Please enter the title and author of the book to be returned:"<<endl;
	                cin>>bookname>>bookauthor;
	                mybook.BackBook(bookname,bookauthor,k);
	                system("cls");
					goto start1;
	            }
	            case 4://预约图书
	            {
	                  string bookname,author;
	                  cout<<"Please enter the title and author of the book you want to book:"<<endl;
	                  cin>>bookname>>author;
	                  mybook.Appointment(bookname,author);//预约图书
	                  system("cls");
					  goto start1;
	            }
	            case 5://查阅个人信息
	            {
	                //mybook.SortStudent(1);
	                cout<<setw(8)<<"Reader ID"<<setw(8)<<"Name"<<setw(14)<<"Historical borrowing times"<<setw(18)<<"Number of books borrowed now"<<setw(14)<<"Last return time"<<endl;
					mybook.PrintStudent(k);
	                mybook.SortStudent(0);
	                printf("You ranked %d in borrowing volume among all readers\n",mybook.SerchStudent(k)+1);
	                printf("The highest borrowing volume among all readers is:%d times\n",mybook.readsum(1));
	                mybook.SortStudent(1);
	                cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
	            	goto start2;
	            	continue; 
				}
				case 6://查阅个人信息
	            {
	              	system("C:\扫码付款.jpg");
	            	goto start2;
	            	continue; 
				}
            }
        }
        while (cho<7);
        system("cls");
		goto start1;
    }
   }
   mybook.Save();
   mybook.Save1();
   return 0;
} 
