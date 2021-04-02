#include<iostream>
#include<vector>
#include<map>
using namespace std;

int k, n;
int main(){
    cin >> k;
    for (int i = 0; i < k;i++){
        cin >> n;
        bool f = true;
        vector<int> v(n + 1), vplus(2*n + 1, 0), vrows(n + 1, 0);
        map<int, int> mminus;
        for (int i = 1; i <= n;i++){
            cin >> v[i];
            if(vplus[v[i]+i] || mminus[v[i]-i] || vrows[v[i]]){
                f = false;
                // cout << "oh " << i << endl;
            }
                
            vplus[v[i] + i] = mminus[v[i] - i] = vrows[v[i]] = 1;
        }
        if(f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
