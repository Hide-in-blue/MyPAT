#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int Max = 26 * 26 * 26;
struct node{
    int v, w;
    node(int v1,int w1) : v(v1) ,w(w1){}
};
int n, k, headw, head, vis[Max], sum[Max], cnt, blocks, f, thres;
vector<node> G[Max];
vector<node> ans;
bool cmp(node a, node b){
        return a.v < b.v;
}
void DFS(int a){
    vis[a] = 1;
    cnt++;
    if(sum[a]>headw){
        headw = sum[a];
        head = a;
    }
    thres += sum[a];
    if(thres>k*2)
        f = 1;
    for(int i=0;i<G[a].size();i++){
        if(!vis[G[a][i].v])
            DFS(G[a][i].v);
    }
}
int getid(void){
    string s;
    cin >> s;
    return s[2]-'A'+(s[1]-'A')*26+(s[0]-'A')*26*26;
}
string getname(int a){
    string s="AAA";
    int i=2;
    if(!a)
        return "AAA";
    else {
        while(a){
            s[i--] = char(a % 26 + 'A');
            a = a / 26;
        }
    }
    return s;
}
int main(){
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        int a = getid(), b = getid(), c;
        cin >> c;
        G[b].push_back(node(a, c));
        G[a].push_back(node(b, c));
        sum[a] += c;
        sum[b] += c;
    }
    for (int i = 0; i < Max;i++){
        headw = 0;
        cnt = 0;
        f = 0;
        thres = 0;
        head = 0;
        if (vis[i] == 0 && G[i].size()){
            DFS(i);
            if(f&&cnt>2){
                blocks++;
                ans.push_back(node(head, cnt));
            }
        }
    }
    cout << blocks << endl;
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < blocks; i++)
        cout << getname(ans[i].v) << ' ' << ans[i].w << endl;
}