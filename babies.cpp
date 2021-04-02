#include<iostream>
#include<algorithm>
using namespace std;

int father[1010],n,k,t,t1,cnt[1010],num,ans[1010];
char c;
int findf(int a){
    if(father[a])
        while(a!=father[a])
            a = father[a];
    else
        father[a] = a;
    return a;
}
void Union(int a,int b){
    int fa = findf(a);
    int fb = findf(b);
    if(fb!=fa)
        father[fb] = fa;
}
int main(){
    // for (int i = 0; i < 1010;i++)
    //     father[i] = i;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> k >> c;
        cin >> t1;
        int ft1 = findf(t1),f[1010]={0};
        for (int j = 1; j < k;j++){
            cin >> t;
            int ft = findf(t);
            Union(t1,t);
            if(f[ft]==0){
                cnt[ft1] += cnt[ft];
                f[ft] = 1;
            }       
        }
        cnt[ft1]++;
    }
    for (int i = 0; i < 10;i++)
        cout << cnt[i] << ' ';
    cout << endl;
    cout << father[7];
    for (int i = 1; i < 1010;i++)
        if(father[i]==i)
            ans[++num] = cnt[i];
    sort(ans + 1, ans + num + 1);
    cout << num << endl;
    for (int i = num; i > 0;i--){
        cout << ans[i];
        if(i>1)
            cout << ' ';
    }
}