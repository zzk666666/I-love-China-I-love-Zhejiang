#include<iostream>
using namespace std;
char ch[25]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E'};
int x,m;
void fun(int x,int m){
	if(x==0)return;
	fun(x/m,m);
	cout<<ch[x%m];
}
int main(){
	cin>>x>>m;
	fun(x,m);
	return 0;
}
