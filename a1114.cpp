#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
struct family{
    int ID, m;
    double a1, a2;
} F[10002];
int father[10002], cnt = 0;
int findfather(int x){
    while(x != father[x]){
        x = father[x];
    }
    return x;
}
void Union(int x, int y){
    int fx = findfather(x), fy = findfather(y);
    if(fx != fy){
        if(fx < fy)
            father[fy] = fx;
        else
            father[fx] = fy;
    }
}
bool cmp(family x, family y){
    if (x.a2 != y.a2)
        return x.a2 > y.a2;
    else
        return x.ID < y.ID;
}
int main(){
    int n, m, id, f, cnt = 0, k, child[5], sets, area, Count[10002]={0};
    double S[10002]= {0}, A[10002]={0};
    fill(S, S + 10002, 0);
    cin >> n;
    for (int i = 0; i < 10002;i++)
        father[i] = i;

    for (int i = 0; i < n;i++){
        cin >> id >> f >> m >> k;
        int fid = findfather(id);
        if(f != -1)
            Union(fid, f);
        if(m != -1)
            Union(fid, m);
        for (int j = 0; j < k;j++){
            cin >> child[j];
            Union(child[j], fid);
        }
        cin >> sets >> area;
        S[id] = sets;
        A[id] = area;
        // cout << findfather(id) << ' ' << findfather(f) << ' ' << findfather(m) << endl;
    }

    for (int i = 0; i < 10002;i++){
        int ft = findfather(i);
        Count[ft]++;
        if (ft != i) S[ft] += S[i];
        if (ft != i) A[ft] += A[i];
    }

    for (int i = 0; i < 10002;i++){
        if(Count[i] > 1 || S[i] && Count[i]){
            F[cnt].ID = i;
            F[cnt].m = Count[i];
            F[cnt].a1 = S[i]/F[cnt].m;
            F[cnt].a2 = A[i]/F[cnt].m;
            cnt++;
        }
    }
    sort(F, F + cnt, cmp);

    cout << cnt << endl;
    for (int i = 0; i < cnt;i++){
            printf("%04d %d %.3f %.3f\n", F[i].ID, F[i].m, F[i].a1, F[i].a2);
    }
}