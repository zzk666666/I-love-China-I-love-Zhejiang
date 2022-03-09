#include <bits/stdc++.h>

using namespace std;
int main(){

    int i,n,m,x,s=0,maxn=0,num[1001];
    cin>>n;
    for(i=1;i<=n;i++)cin>>num[i];
    sort(num,num+n);
    for(i=1;i<=n;i++){
        if(n%2==0)m=(num[n/2]+num[n/2+1])/2;
        else m=num[3];
    }
    cout<<m<<" ";
    sort( num+1,num+n+1 );
    for(i=1;i<=n;i++){
        if(s>maxn)x=num[i];
        if(num[i]!=num[i+1]){
            if(s>maxn)maxn=s;
            s=0; 
        }
        else{
            s++;
        }
    }
    cout<<x;
    return 0;
}
