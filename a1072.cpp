#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = 1000000000;
queue<int> q;
vector<int> baba;
string s;
int n, m, k, ds, tt, f[12];
int g[1020][1020], d[12][1010];
int vis[1020], dmin[12];
double davr[12];
bool cmp1(int a, int b){
    if(dmin[a]!=dmin[b])
        return dmin[a] > dmin[b];
    else{
        if(davr[a]!=davr[b])
            return davr[a] < davr[b];
        else
            return a < b;
    }
}
void Dijkstra(int s){
    int gi = s - n;
    d[gi][s] = 0;
    for (int i = 1; i <= tt;i++){ //get every d[di][]
        int minD = inf, u = -1;
        for (int j = 1; j <= tt;j++){   
            if (vis[j] == 0 && d[gi][j] < minD){
                minD = d[gi][j];
                u = j;
            }
        }
        if(u==-1)
            return;
        vis[u] = 1;
        for (int v = 1; v <= tt;v++){
            if(g[u][v] && vis[v]==0 && d[gi][v]>d[gi][u]+g[u][v])
                d[gi][v] = d[gi][u] + g[u][v];
        }
    }
    int mind = inf;
    double sumD = 0;
    for (int i = 1; i <= n;i++){
        if(d[gi][i]<mind)
            mind = d[gi][i];
        sumD += d[gi][i];
        if(d[gi][i]>ds)
            f[gi] = 1;
    }
    dmin[gi] = mind;
    davr[gi] = sumD / n;
}
int main(){
    cin >> n >> m >> k >> ds;
    tt = n + m;
    for (int i = 0; i < k;i++){//cin
        int a[2] = {0};
        for (int j = 0; j < 2;j++){
            cin >> s;
            if(s[0]=='G'){
                if(s.length()==2)
                    a[j] = s[1] - '0' + n;
                else
                    a[j] = n + 10;
            }
            else
                a[j] = stoi(s);
        }
        cin >> g[a[0]][a[1]];
        g[a[1]][a[0]] = g[a[0]][a[1]];
    }
    for (int i = 1; i <= m;i++){
        fill(vis, vis + 1020, 0);
        fill(d[i], d[i] + 1020, inf);
        Dijkstra(n + i);
    }
    for (int i = 1; i <= m;i++){
        if(f[i]==0)
            baba.push_back(i);
    }
    if(baba.size()==0){
        cout << "No Solution" << endl;
        return 0;
    }
    sort(baba.begin(), baba.end(), cmp1);
    int ye = baba[0];
    cout << 'G' << ye << endl;
    printf("%d.0 %.1f", dmin[ye], davr[ye] + 0.05);
}
