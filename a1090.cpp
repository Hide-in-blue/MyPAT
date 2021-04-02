#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int N, tou, ans=1;
double P, r, maxp;
struct S{
    int index,layer;
    vector<int> child;
} s[100010],f;
queue<S> q;
int main(){
    cin >> N >> P >> r;
    for (int i = 0; i < N;i++){
        s[i].index = i;
        int t;
        cin >> t;
        if(t!=-1)
            s[t].child.push_back(i);
        else
            tou = i;
    }
    q.push(s[tou]);
    while (!q.empty()){
        f = q.front();
        q.pop();
        for (int i = 0; i < f.child.size();i++){
            s[f.child[i]].layer = f.layer + 1;
            q.push(s[f.child[i]]);
        }
        if(f.child.size()==0){
            double p = P * pow(1.0 + r / 100.0, f.layer);
            if(p>=maxp){
                if(p==maxp)
                    ans++;
                else{
                    maxp = p;
                    ans = 1;
                }
            }
        }
    }
    printf("%.2lf %d", maxp, ans);
}
