#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n, m, type;
map<string, int> m1, m2, m3;
struct S{
    string id;
    int score;
} st[10002];
bool cmp(S x, S y){
    if(x.score != y.score)
        return x.score > y.score;
    else
        return x.id < y.id;
}

struct ss{
    string si;
    int num;
} sss[10002];
bool cmp1(ss a, ss b){
    if(a.num != b.num)
        return a.num > b.num;
    else
        return a.si < b.si;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        string s;
        int sc;
        cin >> s >> sc;
        st[i].id = s;
        st[i].score = sc;
        m1[s.substr(1, 3)]++;
        m2[s.substr(1, 3)] += sc;
    }
    sort(st, st + n, cmp);
    for (int j = 0; j < m;j++){
        string s;
        cin >> type >> s;
        printf("Case %d: %d ", j+1, type);
        cout << s << endl;
        if(type == 1){
            for (int i = 0; i < n;i++){
                if(st[i].id[0] == s[0])
                    cout << st[i].id << ' ' << st[i].score << endl;
            }
        }
        else if(type == 2){
            if(m1[s])
                cout << m1[s] << ' ' << m2[s] <<endl;
            else
                cout << "NA" << endl;
        }
        else{
            vector<string> v;
            for (int i = 0; i < n;i++){
                string t = st[i].id.substr(4, 6);
                if(st[i].id.substr(4, 6) == s){
                    string site = st[i].id.substr(1, 3);
                    if(m3[site]==0) 
                        v.push_back(site);
                    m3[site]++;
                }
            }
            for (int i = 0; i < v.size();i++){
                sss[i].si = v[i];
                sss[i].num = m3[v[i]];
            }
            sort(sss, sss + int(v.size()), cmp1);
            for (int i = 0; i < v.size();i++)
                cout << sss[i].si << ' ' << sss[i].num << endl;
        }
    }
}
