#include<iostream>
#include<vector>
using namespace std;
vector<int> v[10010],ans[10010];
bool flag = true;
int N, K, a, b, cnt, maxl, Maxl, layer[10010], vis[10010];

void Dfs(int a, int last){
    vis[a] = 1;
    for (int i = 0; i < v[a].size();i++){
        if(vis[v[a][i]]==0){
            layer[v[a][i]] = layer[a] + 1;
            if(layer[v[a][i]]>maxl)
                maxl = layer[v[a][i]];
            Dfs(v[a][i],a);
        }
        else if(v[a][i]!=last)
            flag = false;
    }
}
int main(){
    cin >> N;
    for (int i = 0; i < N-1;i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= N; i++){
        if (vis[i] == 0){
            Dfs(i, 0);
            cnt++;
        }
    }
    if(flag==false){
        cout << "Error: " << cnt << " components";
        return 0;
    }
    for (int i = 1; i <= N;i++){
        maxl = 0;
        fill(layer, layer + 10010, 0);
        fill(vis, vis + 10010, 0);
        Dfs(i,0);
        if (maxl > Maxl){
            Maxl = maxl;
            ans[Maxl].push_back(i);
        }
        else if (maxl == Maxl){
            ans[Maxl].push_back(i);
        }
    }
    for (int i = 0; i < ans[Maxl].size();i++)
        cout << ans[Maxl][i] << endl;
}

