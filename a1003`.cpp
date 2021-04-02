#include<iostream>
#include<vector>
using namespace std;
const int inf = 1000000000;
struct node{
    int v, len, flag;
    node(int v1, int len1, int flag1): v(v1), len(len1), flag(flag1){}
};
vector<node> g[520];

int n, m, c1, c2, a, b, l, d[520];
int h[520], teams[520], num[520];
void Bellman_Ford(int s){
    for (int i = 0; i < n-1;i++){

        for (int u = 0; u < n;u++)
            for (int j = 0; j < g[u].size();j++){
                int v = g[u][j].v, len = g[u][j].len, f = g[u][j].flag;
                if(d[u] + len < d[v]){
                    d[v] = d[u] + len;
                    teams[v] = teams[u] + h[v];
                    num[v] = num[u];
                    g[u][j].flag = 1;
                }
                else if(d[u] + len == d[v] && !f){
                    if(teams[v] < teams[u] + h[v])
                        teams[v] = teams[u] + h[v];
                    num[v] += num[u];
                    g[u][j].flag = 1;
                }
            }
        if(i==0)
            cout << d[4];
    }
}
int main(){
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n;i++)
        cin >> h[i];
    for (int i = 0; i < m;i++){
        cin >> a >> b >> l;
        g[a].push_back(node(b, l, 0));
        g[b].push_back(node(a, l, 0));
    }
    fill(d, d + 520, inf);
    d[c1] = 0;
    teams[c1] = h[c1];
    num[c1] = 1;
    Bellman_Ford(c1);
    cout << num[c2] << ' ' << teams[c2];
}
