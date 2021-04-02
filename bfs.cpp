#include<iostream>
#include<queue>
using namespace std;
const int maxmn=20;
int ans[maxmn][maxmn],sum=0;
int flag, m, n, b[maxmn][maxmn], f[6]={0,0,-1,1,0,0};
char c[maxmn][maxmn];
struct Ij{
    int x, y;
} ij,s,t;
queue<Ij> q;
int main(){
    cin >> m >> n;
    for (int i = 1; i <= m;i++)
        for (int j = 1; j <= n;j++){
            cin >> c[i][j];
            if(c[i][j]=='S') {
                s.x = i;
                s.y = j;
            }
            // if(c[i][j]=='T'){
            //     t.x = i;
            //     t.y = j;
            // }
        }
    q.push(s);
    b[s.x][s.y] = 1;
    Ij t, tt;
    while(1){
        tt = q.front();
        q.pop();
        // cout << c[tt.x][tt.y] <<' '<<tt.x<<' '<<tt.y<< endl;
        if(c[tt.x][tt.y]=='T'){
            flag = 1;
            break;
        }
        for (int k = 0; k < 4;k++){//search four directions
            int x1 = tt.x + f[k], y1 = tt.y + f[k + 2];
            t.x = x1;
            t.y = y1;
            if((c[x1][y1]=='.'||c[x1][y1]=='T')&&b[x1][y1]==0){
                q.push(t);
                b[x1][y1] = 1;
                ans[x1][y1] = ans[tt.x][tt.y]+1;
            }   
        }
    }
    if(flag)
        cout << ans[tt.x][tt.y];
    else
        cout << "Impossible!!!";
}