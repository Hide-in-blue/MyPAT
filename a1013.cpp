#include<iostream>
using namespace std;

int n, m, k, g[1010][1010], cnt, vis[1010];
void Dfs(int a){
    vis[a] = 1;
    for (int i = 1; i <= n;i++){
        if(vis[i]==0 && g[i][a])
            Dfs(i);
    }
}
int main(){
    cin >> n >> m >> k;
    for (int i = 0; i < m;i++){
        int a1, a2;
        cin >> a1 >> a2;
        g[a1][a2] = 1;
        g[a2][a1] = 1;
    }
    for (int i = 0; i < k;i++){
        int a;
        cin >> a;
        vis[a] = 1;
        for (int j = 1; j <= n;j++){
            if(vis[j]==0){
                Dfs(j);
                cnt++;
            }
        }
        cout << cnt - 1 << endl;
        fill(vis, vis + 1010, 0);
        cnt = 0;
    }
}