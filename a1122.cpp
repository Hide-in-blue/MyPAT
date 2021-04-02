#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, k, n;
int g[202][202];

int main(){
    cin >> N >> M;
    for (int i = 0; i < M;i++){
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    cin >> k;
    for (int i = 0; i < k;i++){
        cin >> n;
        vector<int> v(n), visited(n+1,0);
        for (int j = 0; j < n;j++){
            cin >> v[j];
        }
        if(n != N+1 || v[0]!=v[n-1]){
            cout << "NO" << endl;
            continue;
        }
        bool flag = true;
        for (int j = 0; j < n - 1; j++){
            if(visited[v[j]] || g[v[j]][v[j+1]] == 0){
                flag = false;
                break;
            }
            visited[v[j]] = 1;
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
