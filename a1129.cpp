#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n + 1, 0), rank(k, 0);// cnt and incices of topk
    
    for (int i = 1; i <= n;i++){
        int t, p = 0,ppop = -1;
        cin >> t;
        cnt[t]++;
        if(i == 1){
            rank[0] = t;
            continue;
        }
        cout << t << ':';
        for (int j = 0; j < k;j++){
            if(rank[j] == 0)
                break;
            cout << ' ' << rank[j];
        }
        cout << endl;
        while (cnt[t] == cnt[rank[p]] && t > rank[p] || cnt[t] < cnt[rank[p]])
            p++;
        for (int j = 0; j < k;j++){
            if (rank[j] == t)
                ppop = j;
        }
        if(ppop != -1)
            rank.erase(rank.begin() + ppop);
        rank.insert(rank.begin() + p, t);

    }

}