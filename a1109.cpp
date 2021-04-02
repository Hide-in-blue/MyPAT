#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct sg{
    string s;
    int g;
} st[10010];
bool cmp(sg a,sg b){
    if(a.g!=b.g)
        return a.g > b.g;
    else
        return a.s < b.s;
}
int n, k, h, yu;
void Sort(int x,int y){
    int Rank[10010] = {0}, len = y - x + 1, cnt=0;
    int mi = double(1.0 + len) / 2 + 0.5;
    Rank[mi] = x;
    for (int i = 1; i < mi;i++){
        Rank[mi - i] = x + (++cnt);
        if(cnt==y-x)
            break;
        else
            Rank[mi + i] = x + (++cnt);
    }
    cout << st[Rank[1]].s;
    for (int i = 2; i <= len;i++){
        cout << ' ' << st[Rank[i]].s;
    }
    cout << endl;
}
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> st[i].s >> st[i].g;
    }
    sort(st + 1, st + n + 1, cmp);
    h = n / k;
    yu = n - h * k;
    Sort(1, h + yu);
    for (int i = 1; i < k;i++){
        Sort(i * h + yu + 1, i * h + yu + h);
    }
}