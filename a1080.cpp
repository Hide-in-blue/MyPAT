#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int n, m, k;
struct S{
    double g, ge;
    int id, a[3];
} s[40002];
bool cmp(S x, S y){
    if(x.g != y.g)
        return x.g > y.g;
    else
        return x.ge > y.ge;
}
int main(){
    cin >> n >> m >> k;
    vector<int> quota(m), rank(m);
    set<int> admitted[100];
    for (int i = 0; i < m;i++)
        cin >> quota[i];
    for (int i = 0; i < n;i++){
        double g1;
        cin >> g1 >> s[i].ge >> s[i].a[0] >> s[i].a[1] >> s[i].a[2];
        s[i].g = (g1 + s[i].ge) / 2.0;
        s[i].id = i;
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n;i++){
        cout << s[i].id << ' ' << s[i].g << ' ' << s[i].ge << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (i && s[i].g == s[i - 1].g && s[i].ge == s[i - 1].g)
            rank[i] = rank[i - 1];
        else
            rank[i] = i;
    }
    int q = 1, p = 0;
    for (int i = 0; i < n;i++)
        cout << rank[i] << ' ';
    while (p < n)
    {
        while (q < n && rank[q] == rank[p])
            q++;
        vector<int> v;
        for (int i = p; i < q; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (quota[s[i].a[j]])
                {
                    v.push_back(s[i].a[j]);
                    admitted[s[i].a[j]].insert(s[i].id);
                    break;
                }
            }
        }
        for (int i = 0; i < v.size(); i++)
            quota[v[i]]--;
        p = q;
    }
    for (int i = 0; i < m;i++){
        for (auto j = admitted[i].begin(); j != admitted[i].end();j++){
            if(j!=admitted[i].begin())
                cout << ' ';
            cout << *j;
        }
        cout << endl;
    }
}
