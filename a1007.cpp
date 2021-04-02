#include<iostream>
using namespace std;
long long s[10010], sum, sumr;
int k, a, b, t;
int main(){
    cin >> k;
    for (int i = 0; i < k;i++)
        cin >> s[i];
    while (t < k - 1){
        sumr = 0;
        t++;
        for (int i = b + 1; i <= t;i++)
            sumr += s[i];
        if(sumr>0){
            b = t;
            int tt = b - 1, suml=0;
            for (int i = tt; i >= a;i--){
                suml += s[i];
                if(suml>=0){
                    tt = i;
                    suml = 0;
                }
            }
            a = tt;
        }
    }
    for (int i = a; i <= b;i++){
        sum += s[i];
    }
    if(sum>=0)
        cout << sum << ' ' << s[a] << ' ' << s[b];
    else{
        cout << 0 << ' ' << s[0] << ' ' << s[k - 1];
    }
}
// 2 -1 5 -3 -4 7 1