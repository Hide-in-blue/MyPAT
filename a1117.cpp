#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
int main(){
    int n, Max=0, a[100002], sum = 0;
    map<int, int> m;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        m[a[i]]++;
        Max = max(Max, a[i]);
        // cout << "h";
    }
    for (int i = Max; i > 0;i--){
        sum += m[i];
        // cout << sum << ' ';
        if(sum == i-1){
            cout << i - 1;
            return 0;
        }
    }
    if(Max == 0)
        cout << 0;
}
