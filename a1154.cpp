#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> color;
map<int, int> visitedcolor;
int n, m, k, cnt;
vector<int> v[10002];
void Judge(){
    for (int i = 0; i < n;i++){
        for (int j = 0; j < v[i].size();j++){
            if(color[i] == color[v[i][j]]){
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << cnt << "-coloring" << endl;
    return;
}
int main(){
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> k;
    for (int i = 0; i < k;i++){
        cnt = 0;
        color.clear();
        color.resize(n);
        visitedcolor.clear();
        for (int j = 0; j < n;j++){
            cin >> color[j];
            if(visitedcolor[color[j]]==0)
                cnt++;
            visitedcolor[color[j]] = 1;
        }
        Judge();
    }
}