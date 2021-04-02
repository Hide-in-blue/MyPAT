#include<iostream>
#include<vector>
using namespace std;
int n, m, k;
vector<int> v[100010];
int main(){
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < m; i++){
        bool f[100010] = {false};
        int a[1010],flag=0;
        cin >> k;
        for (int j = 0; j < k;j++){
            cin >> a[j];
            for (int u = 0; u < v[a[j]].size();u++)
                f[v[a[j]][u]] = true;
        }
        for (int j = 0; j < k;j++){
            if(f[a[j]]==true){
                cout << "No" <<endl;
                flag = 1;
                break;
            }
        }
        if(flag==0)
            cout << "Yes" << endl;
    }
}

