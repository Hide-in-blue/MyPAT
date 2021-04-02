#include<iostream>
using namespace std;
int vis[100010];
int main(){
    int n, a;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a;
        if(a>0&&a<100002)
            vis[a] = 1;
    }
    for (int i = 1; i <= n+1;i++){
        if(vis[i]==0){
            cout << i;
            return 0;
        }
    }
}

// #include <iostream>
// #include <map>
// using namespace std;
// int main() {
//     int n, a, num = 0;
//     cin >> n;
//     map<int, int> m;
//     for (int i = 0; i < n; i++) {
//         cin >> a;
//         m[a]=1;
//     }
//     for(int i=1;;i++)
//         if(m[i]==0){
//             cout<<i;
//             return 0;
//         }
// }