#include<iostream>
#include<vector>
using namespace std;
int nv, ne, m, k, g[202][202] = {0}, degree[202] = {0}, visited[202] = {0}, f = 0;
vector<int> v;
void isMax(vector<int> v){
    int flag = 0, len = v.size();
    for (int i = 0; i < len;i++){
        for (int j = i + 1; j < len;j++){
            if(g[v[i]][v[j]] == 0){
                cout << "Not a Clique" << endl;
                return;
            }
        }
    }
    for (int i = 1; i <= nv;i++){
        if(visited[i] == 0){
            flag = 0;
            for (int j = 0; j < len;j++){
                if(g[i][v[j]]==0)
                    flag = 1;
            }
        }
        if(flag == 0 && f == 0){
            cout << "Not Maximal" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
}
int main(){
    cin >> nv >> ne;
    for (int i = 0; i < ne;i++){
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
        degree[a]++;
        degree[b]++;
    }
    cin >> m;
    for (int i = 0; i < m;i++){
        cin >> k;
        for (int j = 0; j < k;j++){
            int t;
            cin >> t;
            v.push_back(t);
            visited[t] = 1;
            if(degree[t] == k-1)
                f = 1;
        }
        isMax(v);
        v.clear();
        f = 0;
        fill(visited, visited + 202, 0);
    }
}