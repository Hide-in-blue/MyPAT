#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
const int maxmn = 20;
struct Ij{
    int x;
    int y;
} ij;
queue<Ij> q;
int s[6] = {0, 0, 1, -1, 0, 0};
int ans, m, n, a[maxmn][maxmn], b[maxmn][maxmn];
void bfs(int i,int j){
    ij.x = i;
    ij.y = j;
    q.push(ij);
    b[i][j] = 1;
    while(!q.empty()){
        Ij tt,t = q.front();
        q.pop();
        for (int k = 0; k < 4;k++){
            int i1 = t.x + s[k], j1 = t.y + s[k + 2];
            if(a[i1][j1]==1&&b[i1][j1]==0){
                tt.x = i1;
                tt.y = j1;
                q.push(tt);
                b[i1][j1] = 1;
            }
        }
    }
    ans++;
}
int main(){
    cin >> m >> n;
    for (int i = 1; i <= m;i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= m;i++)
        for (int j = 1; j <= n;j++){
            if(a[i][j]==1&&b[i][j]==0) bfs(i, j);
        }
    cout << ans;
}