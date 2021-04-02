#include<iostream>
using namespace std;
const int inf = 1000000000;
int n, m, c1, c2, h[510], g[510][510];
int vis[510], d[510], teams[510], num[510];
void dijkstra(int s){
    fill(d, d + 510, inf);
    d[s] = 0;
    teams[c1] = h[c1];
    num[c1] = 1;
    for (int i = 0; i < n;i++){
        int MinD = inf, v = -1;
        for (int j = 0; j < n;j++){
            if(vis[j]==0 && d[j] < MinD){
                MinD = d[j];
                v = j;
            }
        }
        if(v==-1)
            return;
        vis[v] = 1;
        for (int j = 0; j < n;j++){
            if(g[v][j] && vis[j]==0){
                if(g[v][j] + d[v] < d[j]){
                    d[j] = g[v][j] + d[v];
                    teams[j] = teams[v] + h[j];
                    num[j] = num[v];
                }
                else if(g[v][j]+d[v]==d[j]){
                    if(teams[v] + h[j] > teams[j])
                        teams[j] = teams[v] + h[j];
                    num[j]+=num[v];
                }
            }
        }
    }
}
int main(){
    //cin
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n;i++)
        cin >> h[i];
    for (int i = 0; i < m;i++){
        int a, b, l;
        cin >> a >> b >> l;
        g[a][b] = l;
        g[b][a] = l;
    }
    //dijkstra
    dijkstra(c1);
    cout << num[c2] << ' ' << teams[c2];
}