#include<iostream>
#include<algorithm>
using namespace std;
int k, maxdp=-1, ansa, ansb;
long long s[10010], dp[10010], a[10010];
int main(){
    cin >> k;
    for (int i = 1; i <= k;i++){
        cin >> s[i];
    }
    a[0] = 1;
    for (int i = 1; i <= k;i++){
        dp[i] = max(dp[i - 1] + s[i], s[i]);
        if(s[i]>dp[i-1]+s[i])
            a[i] = i;
        else
            a[i] = a[i - 1];
    }
    for (int i = 1; i <= k;i++){
        if(dp[i]>maxdp){
            maxdp = dp[i];
            ansa = a[i];
            ansb = i;
        }
    }
    if(maxdp>=0)
        cout << maxdp << ' ' << s[ansa] << ' ' << s[ansb];
    else
        cout << 0 << ' ' << s[1] << ' ' << s[k];
}