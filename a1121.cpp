#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n, m, a[100000];
    bool attend[100000] = {false};
    vector<int> v;
    cin >> n;
    for (int i = 0; i < 100000;i++)
        a[i] = -1;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x] = y;
        a[y] = x;
    }
    cin >> m;
    v.resize(m,-1);
    for (int i = 0; i < m;i++){
        cin>>v[i];
        attend[v[i]] = true;
    }
    sort(v.begin(), v.end());
    int f = 0, cnt = 0;
    for (int i = 0; i < m;i++){
        if(a[v[i]] == -1 || attend[a[v[i]]] == false)
            cnt++;
    }
    cout << cnt << endl;
    for (int i = 0; i < m; i++)
    {
        if (attend[a[v[i]]] == 0)
        {
            if (f)
                cout << ' ';
            cout << v[i];
            f = 1;
        }
    }
}