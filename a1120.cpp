#include<iostream>
using namespace std;
int main(){
    int n, cnt = 0, visited[40]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        int t, sum = 0;
        cin>>t;
        while(t){
            sum += t%10;
            t /= 10;
        }
        if(visited[sum]==0){
            cnt++;
            visited[sum] = 1;
        }
    }
    int f = 0;
    for(int i=0;i<40;i++){
        if(visited[i]){
            if(f) cout<<' ';
            cout<<i;
            f = 1;
        } 
        
    }
}