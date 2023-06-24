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
    int id;//���߱��
    string name;//��������
    int borrowsum;//���ѽ��Ķ��ٱ���,Ĭ��Ϊ0
    int number;//���ڻ��ж��ٱ���δ����Ĭ��Ϊ0
    string borrowday;//�ϴν���ʱ�䣬Ĭ��Ϊ0000.00.00
    int b[15];//��������ĵı�ţ����15��
};
struct Librarian
{
    int id;//����Ա��� 
};
struct book
{
    int idnum;//ͼ�������
    int BorrowCount;//ͼ�������,��ʼ��Ϊ0
    string name;//����
    string kind;//ͼ������
    double price;//ͼ��۸�
    int sum;//ͼ���ܿ�����
    int nowsum;//ͼ���ֿ����
    string author;//ͼ������
    int appointment;//ͼ��ԤԼ��,��ʼ��Ϊ0
    bool ok;//�Ƿ�ɽ�,��ʼΪ����
    string borrowdate;//ͼ�����һ�ν��ʱ�䣬Ĭ��Ϊ0000-00-00��
    string returndate;//ͼ�����һ�ι黹ʱ�䣬Ĭ��Ϊ0000-00-00��
    string room;//�ݲص�
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
    int borrownum;//ÿ�½��������
    int returnnum;//ÿ�»�������
    vector<book> data;
    vector<student> data1;
    vector<int> betoli;//ԤԼ�鵽�ݣ���������
public:
    Library();
    void AddBook(book NewBook);  //����ͼ��
    void DeleteBook(string bookname,string author);//ɾ��ͼ��
    void BorrowBook(string name,string author);//����ͼ��
    void BackBook(string name,string author,int k);//�黹ͼ��
    void ShowAllBook(); //���ϵͳ����ͼ��
    void SearchBookPosWithname(string thebook); //��������ѯ
    void SearchBookPosWithAuthor(string theauthor);//�����߲�ѯ
    void SearchBookPosWithKind(string kind);//�������ѯ
    int  SearchBookPosWithAB(string theauthor,string thebook);//�����ߺ�������ѯ
    int  SearchBookPosWithid(int id); //����������Ѱ
    void SortBook(int ca);  //����
    void SortStudent(int ca);//�����߽���������
    void Save();  //����ͼ����ļ�
    void Save1();//����ѧ���ļ�
    void Appointment(string bookname,string author);//ԤԼͼ��
    void printbook(book a);//���ĳ�����������Ϣ
    void revisebook(string name,string author);//�޸�ĳ�������Ϣ
    int SerchStudent(int id);//��ѯĳ������
    //int SerchStudent1(int id);//��ѯĳ������
    void AddStudent(student a);//����һ������
    void AddLibrarian(student a);//����һ������Ա 
    void PrintStudent(int kid);//���������Ϣ
    int GetStudent();//���ض�������
    int readsum(int id);//��ȡĳ�����ߵĽ�����
    int getborrownum();//��ȡ���������
    int getreturnnum();//��ȡ���»�����
    void PrintToLi();//�������ԤԼ��

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
int Library::getborrownum()//��ȡ���������
{
    return borrownum;
}
int Library::getreturnnum()//��ȡ���»�����
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
void Library::BackBook(string name,string author,int k)//k��ʾ����;��
{
    int c=-1;
    SortStudent(1);
    if(k!=-1)//������������
    {
        c=k-1;
    }
    else//����ͨ���軹��̨����
    {
        cout<<"��������Ķ��ߺţ�Please enter your reader ID:";
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
void Library::SearchBookPosWithname(string thebook)//��������ѯ
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
void Library::SearchBookPosWithAuthor(string theauthor)//�����߲�ѯ
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
void Library::SearchBookPosWithKind(string kind)//�������ѯ
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
int Library::SearchBookPosWithAB(string theauthor,string thebook)//�����ߺ�������ѯ
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
void Library::SortBook(int ca)  //����
{
    if (ca==0)   //������������
    {
        sort(data.begin(),data.end(),cmpByCount);
    }
    else    //������������
    {
        sort(data.begin(),data.end(),cmpByidnum);
    }
}
void Library::SortStudent(int ca)
{
    if(ca==0)//������������
        sort(data1.begin(),data1.end(),cmpByBorrowsum);
    else
        sort(data1.begin(),data1.end(),cmpByid);//�����ߺ�����
}
void Library::Save() //�����鼮�ļ�
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
void Library::Save1() //����ѧ���ļ�
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
void Library::revisebook(string name,string author)//�޸�ͼ��
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
void Library::Appointment(string bookname,string author)//ԤԼͼ��
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
    cout.setf(ios::left);//�����
    Library mybook;
    student temp;
    char mima[5];//��������
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
	                        mybook.SearchBookPosWithname(Name); //��������ѯ
	                        break;
	                    case 2:
	                        cout<<"Please enter the author!"<<endl;
	                        cin>>AutHor;
	                        mybook.SearchBookPosWithAuthor(AutHor);//�����߲�ѯ
	                        break;
	                    case 3:
	                        cout<<"Please enter the type!"<<endl;
	                        cin>>Kind;
	                        mybook.SearchBookPosWithKind(Kind);//�������ѯ
	                        break;
	                    case 4:
	                        cout<<"Please enter the author and book name!"<<endl;
	                        cin>>AutHor>>Name;
	                        mybook.SearchBookPosWithAB(AutHor,Name);//�����ߺ�������ѯ
	                        break;
	                    }
	                }
	                while(cho3<=4&&cho3>=1);
	                break;
	            }
	            case 3:         //����ͼ��
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
	                cout<<"Author��";
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
	            case 4:         //ɾ��ͼ��
	            {
	                string bookname,bookauthor;
	                cout<<"Please enter the book name and author:"<<endl;
	                cin>>bookname>>bookauthor;
	                mybook.DeleteBook(bookname,bookauthor);
	                break;
	            }
	            case 5:         //����
	            {
	                string bookname,bookauthor;
	                cout<<"Please enter the title and author of the book you want to borrow��"<<endl;
	                cin>>bookname>>bookauthor;
	                mybook.BorrowBook(bookname,bookauthor);
	                mybook.Save();
	                break;
	            }
	            case 6:         //����
	            {
	                string bookname,bookauthor;
	                cout<<"Please enter the title and author of the book to be returned��"<<endl;
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
                cout<<"                Reader ID��"<<temp.id<<endl;
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
	                        mybook.SearchBookPosWithname(Name); //��������ѯ
							break;
	                    case 2:
	                        cout<<"Please enter the author name!"<<endl;
	                        cin>>AutHor;
	                        mybook.SearchBookPosWithAuthor(AutHor);//�����߲�ѯ
							break;
	                    case 3:
	                        cout<<"Please enter the type!"<<endl;
	                        cin>>Kind;
	                        mybook.SearchBookPosWithKind(Kind);//�������ѯ
							break;
	                    case 4:
	                        cout<<"Please enter the author and book name!"<<endl;
	                        cin>>AutHor>>Name;
	                        mybook.SearchBookPosWithAB(AutHor,Name);//�����ߺ�������ѯ
							break;
	                    }
	                }
	                while(cho3<=4&&cho3>=1);
	                system("cls");
					goto start1;
	            }
	            case 3:         //����
	            {
	                string bookname,bookauthor;
	                cout<<"Please enter the title and author of the book to be returned:"<<endl;
	                cin>>bookname>>bookauthor;
	                mybook.BackBook(bookname,bookauthor,k);
	                system("cls");
					goto start1;
	            }
	            case 4://ԤԼͼ��
	            {
	                  string bookname,author;
	                  cout<<"Please enter the title and author of the book you want to book:"<<endl;
	                  cin>>bookname>>author;
	                  mybook.Appointment(bookname,author);//ԤԼͼ��
	                  system("cls");
					  goto start1;
	            }
	            case 5://���ĸ�����Ϣ
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
				case 6://���ĸ�����Ϣ
	            {
	              	system("C:\ɨ�븶��.jpg");
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
