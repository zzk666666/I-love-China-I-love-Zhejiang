#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class User {
private:
    string username;
    string password;
public:
    User(string u, string p) {
        username = u;
        password = p;
    }
    string getUsername() {
        return username;
    }
    bool checkPassword(string p) {
        return password == p;
    }
};

class Event {
private:
    string name;
    string date;
public:
    Event(string n, string d) {
        name = n;
        date = d;
    }
    string getName() {
        return name;
    }
    string getDate() {
        return date;
    }
};

class Schedule {
private:
    vector<Event> events;
public:
    void addEvent(Event e) {
        events.push_back(e);
    }
    void printSchedule() {
        cout << "My Time Of Birth Schedule:" << endl;
        for (Event e:events) {
        	
        	if(e.getName()=="Life(month)")
        	{
        		cout<<endl;
        		cout<<e.getName() << " on " << e.getDate()<<":"<<endl; 
				continue;
        		if(e.getDate()=="31")
        		{		
        			cout<<e.getName() << " on " << e.getDate()<<"|"<<endl; 
        			cout<<endl;
				}
			}
            cout << e.getName() << " on " << e.getDate()<<"|";
        }
    }
};

class App {
private:
    vector<User> users;
    User* currentUser;
    Schedule schedule;
public:
    void registerUser(string username, string password) {
        User user(username, password);
        users.push_back(user);
    }
    bool login(string username, string password) {
        for (User&user : users) {
            if (user.getUsername() == username && user.checkPassword(password)) {
                currentUser = &user;
                return true;
            }
        }
        return false;
    }
    void logout() {
        currentUser = nullptr;
    }
    void addEvent(string name, string date) {
        if (currentUser != nullptr) {
            Event event(name, date);
            schedule.addEvent(event);
        }
    }
    void printSchedule() {
        if (currentUser != nullptr) {
            schedule.printSchedule();
        }
    }
};
class Life{
	public:
		void Child_Copywriting(int random_choice)
		{
			switch(random_choice)
			{
				case 1:cout<<"�ҵ�С�ɰ�,����·��Ү,����Ӵ!"<<endl;break;
				case 2:cout<<"��,��������·��,��֤��ĳɳ�"<<endl;break;
				case 3:cout<<"СС�Ľ��ƴ�������,δ������һ������Ĺ�â"<<endl;break;
				case 4:cout<<"ʱ��ÿ�ת�۱�������·��,�������Ǹ������е�СӤ���ˡ�"<<endl;break;
			}
		}
		void Juvenile_Copywriting(int random_choice)
		{
			switch(random_choice)
			{
				case 1:cout<<"��һ��ֻ��޵�С������һ������Сѧ��Сѧ�������ǳɳ�;��һ��������С������һ�����ص�ѧ�������ǳɳ�;��һ��ʲô��������С������һ�����������ڡ���ѧ������ͬ���ǳɳ���"<<endl;break;
				case 2:cout<<"���׶�԰��ѧǰ��һ�꼶��������ʽ����ѧ�ã��µ���ò���µĻ�����ո�µ�һ�У�����ܶ��Ŀ�ʼ��ϣ����Ӵ��Ժ��˼����ģ�ƴ�����麣��Ŭ���ɺ���!"<<endl;break;
				case 3:cout<<"���һ����ͯ���ɳ�Ϊ���ߺ�ͯ�����ѧͯ������ͯ���޼ɵĸ�ҥ�����Ÿ���ͯ���������Ϊ��Ů��ͯ��գ���Ѻ׷�ͯ�գ���ͯ��δ�ߣ����η��ϻ�ͯ����������ͯ�ڿ��֣�"<<endl;break;
				case 4:cout<<"�����Ƽ�����������ת�ۼ��ҵĺ����ڻ�԰һ���ˣ��̶̵�һ��ʱ���ú��ӵ�ѧϰ�ɼ�����ͻ���ͽ��Ľ��������ź�����һ���ĳ��������ı䶮�£��Ҹе�����ο��"<<endl;break;
			}
		}
		void Teenager_Copywriting(int random_choice)
		{
			switch(random_choice)
			{
				case 1:cout<<"���ͯ�꣬�ſ�˫�֣�ӭ���ഺ���������ڶ��������������ڴ�������ǰ��!"<<endl;break;
				case 2:cout<<"ÿ���˶����Լ��ɳ������̡���ѽѽѧ��Ķ�ͯ�����绪��ï����ѧ����������������ᣬ��Ϊ��������֮�ţ�ÿһ���ɳ��Ĺ��̶����������Ƿܶ��ĺ�ˮ��"<<endl;break;
				case 3:cout<<"һ��ͯ����㣬һ���ഺ���ꡣ���Ǵ��㿪ʼ�����޵��У�һ��һ����ӡ���ߵ�Խ��Խ�ᶨ��"<<endl;break;
				case 4:cout<<"��С������������Ǵ��ˣ��ڴ������������С����������������Ǿ������ǡ�������һȺ��Ծ�����㽻������һ���ഺ�ĸ裬�����һ����Զ׷�ϵ�С�ӡ�"<<endl;break;
			}
		}
		void Youth_Copywriting(int random_choice)
		{
			switch(random_choice)
			{
				case 1:cout<<"���꣬��֤����ĳɳ�����ĸı䣬���¶����꣬�ɳ�Ϊ��η���ˣ�����ɬ�����죬Ҳ�������۷壬Ҳ�������͹ȡ�ʱ�����ۣ��������������ꡣ"<<endl;break;
				case 2:cout<<"���¶������죬�ӿ̹ǵ�ƽ���������ϲ�����Զ��ƽ������飬���İ���"<<endl;break;
				case 3:cout<<"������б�ţ���¥������."<<endl;break;
				case 4:cout<<"һ·���������¶������죬����֪��֪�ԣ����������������ǵİ�����ֻҪ��Ը������ͣ�²������վ����е��ʵ�ֵ�һ�죡"<<endl;break;
			}
		}
		void middleage_Copywriting(int random_choice)
		{
			switch(random_choice)
			{
				case 1:cout<<"�������еĹ��¶��ܳ�Ϊ����۾����ɫ��,��Ϊ���»ᵭ�������ɫ�����������·�ߵò�ƽ˳��ʱ��,��Ҫ������,��ֻ���߹�����·����,�߹��Ժ�һ��ֻ����ʱ�⴦�á�"<<endl;break;
				case 2:cout<<"�˵������֪��:ͿĨ�����Ϊ�˸����˿���,������Ϊ�˸��Լ��õġ�"<<endl;break;
				case 3:cout<<"�˵������֪��:������ֻ�ܸ�˵������,����Ψ�з���ʱ�Լ�����."<<endl;break;
				case 4:cout<<"�����߷�׳̬�������ж�!"<<endl;break;
			}
		}
		void oldage_Copywriting(int random_choice)
		{
			switch(random_choice)
			{
				case 1:cout<<"���´�����,ʱ������,ֻ���������µĺۼ�,����С����ǵ����ϡ�"<<endl;break;
				case 2:cout<<"������鰮,�����ٶ���,���������������в���,ֻ���Ҷ���İ���Զ���ϡ�"<<endl;break;
				case 3:cout<<"���������֮�䣬�䵽��ꣻ��֪���ж������ܺ�����ͬ������ᡣ�ܶ�ʱ������������ȴ�Ĳ�����һʱ֮�˻�һʱ֮�£������Ǹ��ˡ��Ǽ��������ص�һ�������һ�����¡�"<<endl;break;
				case 4:cout<<"�������ţ�����һ����Ȫ������һ���㣻�������֣�ֻʣ�²԰׵��������ε��غ򣻻�����ɳ��˭��������������Ӱ��˭�����������ĽŲ���һ�ж��������н��У��������б�����"<<endl;break;
			}
		}
};

int main() {
    App app;
    Life life;
    srand(time(NULL));
	time_t timep;
	struct tm *p;
	char string[16] = {0};
	int startday=4,lastday;
	int initmonth=5;
	time(&timep);
	p=gmtime(&timep);
    app.registerUser("user1", "password1");
    app.registerUser("user2", "password2");
    bool loggedIn = app.login("user1", "password1");
    system("color 0A");
    if (loggedIn) {
    	//app.addEvent("Meeting", "2004-05-04");
		for(int year=2004;year<=int(1900+p->tm_year);year++){
			app.addEvent("                     Life(year)",itoa(year,string,10));
       		for(int month=initmonth;month<=12;month++)
			{
				system("cls");
				cout<<endl;
				system("color 06");
				app.addEvent("Life(month)",itoa(month,string,10));
				if(year%400==0 || year%4==0&&year%100!=0)
				{
					switch(month)
					{
						case 1:lastday=31;break;
						case 2:lastday=29;break;
						case 3:lastday=31;break;
						case 4:lastday=30;break;
						case 5:lastday=31;break;
						case 6:lastday=30;break;
						case 7:lastday=31;break;
						case 8:lastday=31;break;
						case 9:lastday=30;break;
						case 10:lastday=31;break;
						case 11:lastday=30;break;
						case 12:lastday=30;break;
					}
	        	}else{	
	        		switch(month)
					{
						case 1:lastday=31;break;
						case 2:lastday=28;break;
						case 3:lastday=31;break;
						case 4:lastday=30;break;
						case 5:lastday=31;break;
						case 6:lastday=30;break;
						case 7:lastday=31;break;
						case 8:lastday=31;break;
						case 9:lastday=30;break;
						case 10:lastday=31;break;
						case 11:lastday=30;break;
						case 12:lastday=30;break;
					}
				}
	        	for(int day=startday;day<=lastday;day++)
				{
					if(year==2004&&month==5&&day==4)
					{
						system("color 0B");
						Sleep(1000);
					}else system("color 0F");
					app.addEvent("Life(day)",itoa(day,string,10));
	        		app.printSchedule();
					if (year==int(1900+p->tm_year)&&month==int(1+p->tm_mon)&&day==int(8+p->tm_mday))
					{
	        			app.logout();
	        		}
	        		if(year==2007&&month==5&&day==4)
	        		{
	        			life.Child_Copywriting(rand()%5);
					}
					if(year==2011&&month==5&&day==4)
	        		{
	        			life.Juvenile_Copywriting(rand()%5);
					}
	        		if(year==2016&&month==5&&day==4)
	        		{
	        			life.Teenager_Copywriting(rand()%5);
					}else if(year==2049&&month==5&&day==4)
					{
						life.middleage_Copywriting(rand()%5);
					}else if(year==2064&&month==5&&day==4)
					{
						life.oldage_Copywriting(rand()%5);
					}
	        		if(day==lastday)
	        		{
						startday=1;
						break;
					}
					Sleep(1000);
					system("cls");
	        	}
	        	cout<<endl;
				if(month==12)
	        	{
					initmonth=1;
					system("cls");
					break;
				} 
        	}
			cout<<endl;	
        	Sleep(1000);
    	}
    	cout<<endl;	
    	Sleep(1000);
    }

    return 0;
}
