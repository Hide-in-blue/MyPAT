#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct S{
    int layer;
    vector<int> child;
} s[110], f;
queue<S> q;
int M, N, id, K, idk, cnt[110], maxl;
int main(){
    cin >> N >> M;
    for (int i = 0; i < M;i++){
        cin >> id >> K;
        for (int j = 0; j < K;j++){
            cin >> idk;
            s[id].child.push_back(idk);
        }
    }
    s[1].layer = 1;
    q.push(s[1]);
    while (!q.empty()){
        f = q.front();
        q.pop();
        // cout << f.layer << endl;
        if(f.child.size()==0)
            cnt[f.layer]++;
        for (int i = 0; i < f.child.size();i++){
            s[f.child[i]].layer = f.layer + 1;
            maxl = f.layer + 1;
            q.push(s[f.child[i]]);
        }
    }
    if(N==1){
        cout << 1;
    }
    else
        for (int i = 1; i <= maxl;i++){
            if(i==1)
                cout << cnt[i];
            else
                cout << ' ' << cnt[i];
        }
}