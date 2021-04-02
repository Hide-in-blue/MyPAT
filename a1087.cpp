#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
vector<string> ans;
const int inf = 1000000000;
int n, k, cnts, des, maxh[210], dis, happy[210], num[210];
int g[210][210], d[210], vis[210], pre[210],sumh[210];
map<int, string> Itos;
map<string, int> Stoi;
string s, s1, s2;
void Dijkstra(){
    for (int a = 0; a < n;a++){
        int u = -1, minD = inf;
        for (int i = 0; i < n;i++){
            if(vis[i]==0 && d[i]<minD){
                minD = d[i];
                u = i;
            }
        }
        if(u==-1)
            return;
        vis[u] = 1;
        for (int i = 0; i < n;i++){
            if(vis[i]==0 && g[i][u]){
                if(d[u]+g[i][u]<d[i]){
                    d[i] = d[u] + g[i][u];
                    num[i] = num[u];
                    pre[i] = u;
                    sumh[i] = sumh[u] + happy[i];
                    if(happy[u]>maxh[i])
                        maxh[i] = happy[u];
                }
                else if(d[u]+g[i][u]==d[i]){
                    num[i] += num[u];
                    if(maxh[u]>maxh[i]||(maxh[u]<=maxh[i] && sumh[u]+happy[i]>sumh[i])){
                        pre[i] = u;
                        sumh[i] = sumh[u] + happy[i];
                    }
                }
            }       
        }
    }
}
int main(){
    cin >> n >> k >> s;
    Stoi[s] = 0;
    Itos[0] = s;
    for (int i = 1; i < n;i++){
        cin >> s >> happy[i];
        Stoi[s] = i;
        Itos[i] = s;
        maxh[i] = happy[i];
        if(s=="ROM")
            des = i;
    }
    fill(g[0], g[0] + 210 * 210, inf);
    for (int i = 0; i < k;i++){
        cin >> s1 >> s2 >> dis;
        g[Stoi[s1]][Stoi[s2]] = dis;
        g[Stoi[s2]][Stoi[s1]] = dis;
    }
    
    fill(d, d + 210, inf);
    d[0] = 0;
    num[0] = 1;
    Dijkstra();
    for (int i = des; pre[i] != i;i=pre[i])
        ans.push_back(Itos[i]);
    cout << num[des] << ' ' << d[des] << ' ' << sumh[des] << ' ' << sumh[des] / ans.size() << endl;
    cout << Itos[0] << "->";
    for (int i = ans.size()-1; i > 0;i--)
        cout << ans[i] << "->";
    cout << "ROM" << endl;
}
