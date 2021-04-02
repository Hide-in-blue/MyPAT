#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct S{
    int index, layer, parent;
    vector<int> child;
} s[102], f;
queue<S> q;
int N, M, k, id, idk, a[102], ans, ans1;
int main(){
    cin >> N >> M;
    for (int i = 0; i < M;i++){
        cin >> id >> k;
        for (int j = 0; j < k;j++){
            cin >> idk;
            s[id].child.push_back(idk);
            s[idk].parent = 1;
        }
    }
    int tou;
    for (tou = 1;tou <= N;tou++){
        if(s[tou].parent==0)
            break;
    }
    q.push(s[tou]);
    while(!q.empty()){
        f = q.front();
        q.pop();
        for (int i = 0; i < f.child.size();i++){
            s[f.child[i]].layer = f.layer + 1;
            q.push(s[f.child[i]]);
        }
    }
    for (int i = 1; i <= N;i++){
        a[s[i].layer]++;
        if(a[s[i].layer]>ans){
            ans = a[s[i].layer];
            ans1 = s[i].layer;
        }
            
    }
    cout << ans << ' ' << ans1+1;
}
