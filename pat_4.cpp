#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Inf = 100000000, visited[202] = {0};
int g[202][202]={0}, d[202][202], n, m, cnt = 0, f = 0;
int findminnext(int index){
    int Min = Inf, res = -1;
    for (int i = 0; i < n;i++){
        if (i != index && visited[i] == 0 && d[index][i] < Min){
            Min = d[index][i];
            res = i;
        }
    }
    return res;
}
int main(){
    for (int i = 0; i < 201;i++)
        for (int j = 0; j < 201;j++){
            d[i][j] = Inf;
            g[i][j] = 0;
        }
    
    cin >> n >> m;
    n++;
    for (int i = 0; i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = d[b][a] = d[a][b] = c;
    }
    for (int i = 0; i < n;i++)
        d[i][i] = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            for (int k = 0; k < n;k++){
                if(d[j][i]!=Inf && d[i][k]!=Inf && d[j][i]+d[i][k]<d[j][k])
                    d[j][k] = d[j][i] + d[i][k];
            }
        }
    }
    for (int i = 1; i < n;i++){
        if(d[0][i] == Inf)
            f = 1;
    }
    int index = 0, next = findminnext(0);
    cout << index;
    visited[0] = 1;
    while(next != -1){
        cout << ' ' <<next;
        visited[next] = 1;
        cnt += d[index][next];
        index = next;
        next = findminnext(index);
    }
    cout << endl;
    int ff = 0;
    if(f){
        for (int i = 0; i < n;i++){
            if(d[0][i] == Inf){
                if(ff)
                    cout << ' ';
                cout << i;
                ff = 1;
            } 
        }
    }
    else{
        cout << cnt;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << d[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
}