// #include<iostream>
// #include<vector>
// #include<map>
// using namespace std;
// map<string, bool> win;
// vector<string> v;
// int n, m, k, c = 1,f = 0;
// int main(){
//     cin >> n >> m >> k;
//     v.resize(n + 1);
//     for (int i = 1; i <= n;i++,c++){
//         cin >> v[i];
//         if(win[v[i]]){
//             c--;
//             continue;
//         }
//         if(win[v[i]] == false && (c-k)%m == 0){
//             cout << v[i] << endl;
//             f = 1;
//             win[v[i]] = true;
//         }
//     }
//     if( f == 0)
//         cout << "Keep going...";
// }
#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<string, bool> win;
vector<string> v;
int n, m, k;
int main(){
    cin >> n >> m >> k;
    v.resize(n + 1);
    for (int i = 1; i <= n;i++)
        cin >> v[i];
    if(n < k){
        cout << "Keep going...";
        return 0;
    }
    for (int i = 1; i <= n; i++){
        if (win[v[i]] && (i - k) % m == 0)
        {
            for (int j = i + 1; j < i + m && j <= n; j++)
            {
                if (win[v[j]] == false)
                {
                    cout << v[j] << endl;
                    win[v[j]] = true;
                    break;
                }
            }
        }
        if (win[v[i]] == false && (i - k) % m == 0)
        {
            cout << v[i] << endl;
            win[v[i]] = true;
        }
    }
    
        
}