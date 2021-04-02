#include<iostream>

using namespace std;
int visited[502] = {0};
int n, m, g[502][502] = {0}, degree[502] = {0}, cnt = 0, cntt = 0;
void dfs(int index){
    visited[index] = 1;
    cntt++;
    for (int i = 1; i <= n;i++){
        if(i!=index && g[index][i] && visited[i]==0)
            dfs(i);
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(j != i && g[i][j])
                degree[i]++;
        }
    }
    for (int i = 1; i <= n;i++){
        if(i>1)
            cout << ' ';
        cout << degree[i];
        if(degree[i]%2)
            cnt++;
    }
    cout << endl;
    dfs(1);
    if(cnt == 0 && cntt == n)
        cout << "Eulerian";
    else if(cnt == 2 && cntt == n)
        cout << "Semi-Eulerian";
    else
        cout << "Non-Eulerian";
}