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
				case 1:cout<<"我的小可爱,会走路了耶,棒棒哟!"<<endl;break;
				case 2:cout<<"哇,宝贝会走路啦,见证你的成长"<<endl;break;
				case 3:cout<<"小小的脚掌大大的力量,未来的你一定有你的光芒"<<endl;break;
				case 4:cout<<"时间好快转眼宝宝会走路了,不再是那个襁褓中的小婴儿了。"<<endl;break;
			}
		}
		void Juvenile_Copywriting(int random_choice)
		{
			switch(random_choice)
			{
				case 1:cout<<"从一个只会哭的小孩，到一个上了小学的小学生，这是成长;从一个淘气的小孩，到一个稳重的学生，这是成长;从一个什么都不懂的小孩，到一个“满腹经纶”的学生，这同样是成长。"<<endl;break;
				case 2:cout<<"从幼儿园到学前到一年级，你已正式步入学堂，新的面貌、新的环境，崭新的一切，是你奋斗的开始，希望你从此以后浪迹书涯，拼博于书海，努力吧孩子!"<<endl;break;
				case 3:cout<<"你从一介幼童，成长为三尺孩童、五尺学童，唱着童言无忌的歌谣，看着格林童话，梦想成为玉女金童。眨眼已鹤发童颜，仍童心未眠，期盼返老还童！哈哈，儿童节快乐！"<<endl;break;
				case 4:cout<<"光阴似箭，日月如梭，转眼间我的孩子在慧园一年了，短短的一年时间让孩子的学习成绩有了突飞猛进的进步，看着孩子们一点点的长大，慢慢的变懂事，我感到很欣慰。"<<endl;break;
			}
		}
		void Teenager_Copywriting(int random_choice)
		{
			switch(random_choice)
			{
				case 1:cout<<"告别童年，张开双手，迎接青春花季的如期而至，让我们在期待中砥砺前行!"<<endl;break;
				case 2:cout<<"每个人都有自己成长的历程。从呀呀学语的儿童，到风华正茂的中学生，到将来走向社会，成为社会的有用之才，每一个成长的过程都饱含了我们奋斗的汗水。"<<endl;break;
				case 3:cout<<"一颗童心如炽，一身青春少年。他们从零开始，从无到有，一步一个脚印，走的越来越坚定。"<<endl;break;
				case 4:cout<<"在小孩的眼里，我们是大人；在大人眼里。我们是小孩；在我们眼里，我们就是我们。我们是一群欢跃的鸟，足交响乐中一组青春的歌，汇成了一条永远追赶的小河。"<<endl;break;
			}
		}
		void Youth_Copywriting(int random_choice)
		{
			switch(random_choice)
			{
				case 1:cout<<"六年，见证了你的成长，你的改变，从懵懂少年，成长为无畏男人，从青涩到成熟，也曾到过巅峰，也曾到过低谷。时光荏苒，归来依旧是少年。"<<endl;break;
				case 2:cout<<"从懵懂到成熟，从刻骨到平凡。成熟的喜欢，最长远，平凡的陪伴，最心安。"<<endl;break;
				case 3:cout<<"骑马倚斜桥，满楼红袖招."<<endl;break;
				case 4:cout<<"一路走来，从懵懂到成熟，从无知到知性，阿赵用她做了我们的榜样，只要有愿望，不停下步伐，终究会有到达、实现的一天！"<<endl;break;
			}
		}
		void middleage_Copywriting(int random_choice)
		{
			switch(random_choice)
			{
				case 1:cout<<"不是所有的故事都能成为你的眼睛里的色彩,因为岁月会淡化你的颜色。当你的人生路走得不平顺的时候,不要忘记了,你只是走过这条路而已,走过以后一切只能任时光处置。"<<endl;break;
				case 2:cout<<"人到中年才知道:涂抹外观是为了给别人看到,修心是为了给自己用的。"<<endl;break;
				case 3:cout<<"人到中年才知道:好听话只能给说给别人,自责唯有反悔时自己领受."<<endl;break;
				case 4:cout<<"永保颠峰壮态，快速行动!"<<endl;break;
			}
		}
		void oldage_Copywriting(int random_choice)
		{
			switch(random_choice)
			{
				case 1:cout<<"岁月催人老,时间流逝,只留下那岁月的痕迹,刻在小伙伴们的脸上。"<<endl;break;
				case 2:cout<<"世间的情爱,不管再动人,都会在岁月流逝中苍老,只有我对你的爱永远不老。"<<endl;break;
				case 3:cout<<"这就是岁月之殇，殇到灵魂；不知道有多少人能和我有同样的体会。很多时候，我们难以忘却的并不是一时之人或一时之事，而是那个人、那件事所承载的一种心情和一段岁月。"<<endl;break;
				case 4:cout<<"岁月流逝，流出一缕清泉，流出一阵芳香；齿月年轮，只剩下苍白的脸，无奈的守候；回忆流沙，谁都看不到他的身影，谁都听不到他的脚步，一切都在流逝中进行，在流逝中爆发。"<<endl;break;
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
