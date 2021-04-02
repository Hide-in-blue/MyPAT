#include<iostream>
// #include<algorithm>
using namespace std;

int father[10002], cnted[10002] = {0}, cnt = 0, n, Max = 0;
int findfather(int x){
    int t = x;
    while(x!=father[x]){
        x = father[x];
    }
    while(t!=x){
        int a = father[t];
        father[t] = x;
        t = a;
    }
    return x;
}
void Union(int x, int y){
    int fx = findfather(x), fy = findfather(y);
    if(fx!=fy)
        father[fx] = fy;
}
int main(){
    cin >> n;
    for (int i = 0; i < 10002;i++)
        father[i] = i;
    for (int i = 0; i < n; i++){
        int k, first;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int b;
            cin >> b;
            Max = max(b, Max);
            if (j == 0)
                first = b;
            else
                Union(b, first);
            // cout << first << endl;
        }
    }
    for (int i = 1; i <= Max;i++){
        // cout << findfather(i) << ' ';
        if(cnted[findfather(i)]==0){
            cnt++;
            cnted[findfather(i)] = 1;
        }
    }
    cout << cnt << ' ' << Max << endl;

    int q;
    cin >> q;
    for (int i = 0; i < q;i++){
        int a, b;
        cin >> a >> b;
        if(findfather(a)==findfather(b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}