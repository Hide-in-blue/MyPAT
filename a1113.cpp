#include<iostream>
#include<algorithm>
using namespace std;
//too easy
int main(){
    int n, s1 = 0, s2 = 0, a[100002];
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n;i++){
        if (i < n/2)
            s1 += a[i];
        else
            s2 += a[i];
    }
    cout << (n % 2 ? 1 : 0) << ' ' << s2 - s1;
}