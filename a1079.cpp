#include<iostream>
#include <vector>
#include<queue>
#include<cmath>
using namespace std;

const int maxn = 100100;
struct S{
    int amount;
    int layer;
    vector<int> child;
} s[maxn],f;
queue<S> q;
int N, k[maxn], id[maxn];
double P, r, ans;
int main(){
    cin >> N >> P >> r;
    for (int i = 0; i < N;i++){
        cin >> k[i];
        for (int j = 0; j < k[i];j++){
            cin >> id[j];
            s[i].child.push_back(id[j]);
        }
        if(k[i]==0){
            cin >> s[i].amount;
        }
    }
    q.push(s[0]);
    while(!q.empty()){
        f = q.front();
        ans += f.amount * pow(1 + r / 100, f.layer) * P;
        q.pop();
        for (int i = 0; i < f.child.size();i++){
            s[f.child[i]].layer = f.layer + 1;
            q.push(s[f.child[i]]);
        }
    }
    printf("%.1lf", ans);
}