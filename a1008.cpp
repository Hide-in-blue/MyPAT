#include<iostream>
using namespace std;
int n,x,t,ans;
int Cal(int a){
    int b;
    if(a>0){
        b=a*6+5;
    }
    else b=a*(-1)*4+5;
    return b;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        ans+=Cal(x-t);
        t=x;
    }
    cout<<ans;
}