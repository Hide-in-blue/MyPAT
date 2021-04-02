#include<iostream>
#include<queue>
using namespace std;

int N, L, M, n, cnt, g[1010][1010],vis[1010],level[1010];
queue<int> q;
int ans(int a){
    q.push(a);
    vis[a] = 1;
    level[a] = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        cnt++;
        if(level[t]<L){
            for (int i = 1; i <= N;i++){
                if(vis[i]==0&&g[t][i]){
                    q.push(i);
                    vis[i] = 1;
                    level[i] = level[t] + 1;
                }
            }
        }    
    }
    return cnt - 1;
}
int main(){
    cin >> N >> L;
    for (int i = 1; i <= N;i++){
        cin >> M;
        for (int j = 0; j < M;j++){
            int t;
            cin >> t;
            g[t][i] = 1;
        }
    }
    cin >> n;
    for (int i = 0; i < n;i++){
        int t;
        cin >> t;
        cnt = 0;
        fill(level, level + 1010, 0);
        fill(vis, vis + 1010, 0);
        cout << ans(t) << endl;
    }
}