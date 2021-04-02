#include<iostream>
using namespace std;
int g[210][210];
int n, m, k, kn, shortest=20000000, sp;
int main(){
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int a, b, d;
        cin >> a >> b >> d;
        g[a][b] = g[b][a] = d;
    }
    cin >> k;
    for (int i = 1; i <= k;i++){
        if(i==6)
            ;
        cin >> kn;
        int vis[n + 1]={0}, p[kn + 1]={0},cnt=0,d=0,ff=0;
        for (int j = 0; j < kn;j++){
            cin >> p[j];
            if(vis[p[j]] ==0){
                vis[p[j]] = 1;
                cnt++;
            }
            if(j){
                if(g[p[j]][p[j - 1]]==0){
                    ff = 1;
                }
                d += g[p[j]][p[j - 1]];
            }
        }
        if(cnt==n && p[0]==p[kn-1] && ff==0){
            if(kn==n+1)
                printf("Path %d: %d (TS simple cycle)\n", i, d);
            else
                printf("Path %d: %d (TS cycle)\n", i, d);
            if(d<shortest){
                shortest = d;
                sp = i;
            }
        }
        else if(ff==0)
            printf("Path %d: %d (Not a TS cycle)\n", i, d);
        else 
            printf("Path %d: NA (Not a TS cycle)\n", i);
    }
    printf("Shortest Dist(%d) = %d", sp, shortest);
}

