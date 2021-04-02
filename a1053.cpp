#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
struct S{
    long long w;
    vector<int> child;
} s[110];

int N, M, id, K, idk, mark[110], cnt1=-1;
long long Weight, sum, op[70][100];

void DPS(int index, long long sumw,int cnt,long long ans[]){
    ans[cnt] = s[index].w;
    if(s[index].child.size()==0&&sumw==Weight){
        cnt1++;
        for (int i = 1; i <= cnt;i++)
            op[cnt1][i] = ans[i];
    }
    for (int i = 0; i < s[index].child.size();i++)
        DPS(s[index].child[i],sumw+s[s[index].child[i]].w,cnt+1,ans);
}
int main(){
    cin >> N >> M >> Weight;
    for (int i = 0; i < N;i++)
        cin >> s[i].w;
    for (int i = 0; i < M;i++){
        cin >> id >> K;
        for (int j = 0; j < K;j++){
            cin >> idk;
            s[id].child.push_back(idk);
        }
    }
    long long ans[110] = {0};
    DPS(0, s[0].w, 1, ans);
    // sort(op, op + cnt1 + 1);
    for (int i = 0; i <= cnt1;i++){
        cout << op[i][1];
        for (int j = 2; op[i][j] != 0;j++)
            cout << ' ' << op[i][j];
        cout << endl;
    }
}