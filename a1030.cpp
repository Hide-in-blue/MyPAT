#include<iostream>
using namespace std;
const int inf = 1000000000;
int n, m, s1, s2, pre[520], vis[520], ans[520];
int g[520][520], c[520][520], d[520], cost[520];
void Dijkstra(int s){
    for (int j = 0; j < n;j++){
        int minD = inf, u = -1;
        for (int i = 0; i < n;i++){
            if(!vis[i] && d[i] < minD){
                minD = d[i];
                u = i;
            }
        }
        if(u==-1)
            return;
        vis[u] = 1;
        for (int i = 0; i < n;i++){
            if(!vis[i] && g[u][i]){
                if(d[u]+g[u][i]<d[i]||(d[u]+g[u][i]==d[i] && cost[u]+c[u][i]<cost[i])){
                    d[i] = d[u] + g[u][i];
                    cost[i] = cost[u] + c[u][i];
                    pre[i] = u;
                }
            }
        }
    }
}
int main(){
    cin >> n >> m >> s1 >> s2;
    for (int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b >> g[a][b] >> c[a][b];
        g[b][a] = g[a][b];
        c[b][a] = c[a][b];
    }
    fill(d, d + 520, inf);
    for (int i = 0; i < n;i++)
        pre[i] = i;
    d[s1] = 0;
    cost[s1] = 0;
    Dijkstra(s1);
    int  sum=0;
    for (int i = s2; pre[i] != i; i = pre[i])
        ans[++sum] = i;
    cout << s1 << ' ';
    for (int i = sum; i > 0;i--)
        cout << ans[i] << ' ';
    cout << d[s2] << ' ' << cost[s2];
}