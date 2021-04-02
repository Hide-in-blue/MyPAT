#include<iostream>
#include<algorithm>
using namespace std;
struct s{
    int a, b, degree;
} b[2002];
bool cmp(s x, s y){
    if(x.a != y.a)
        return x.a < y.a;
    else
        return x.b < y.b;
}
bool cmp1(s x, s y){
    if(x.degree != y.degree)
        return x.degree > y.degree;
}
int g[2002][2002] = {0}, dsum = 0, cnt = 0;
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int a1, b1, c1, d, e, f;
        scanf("%d:%d:%d %d:%d:%d", &a1, &b1, &c1, &d, &e,&f);
        getchar();
        b[i].a = a1 * 10000 + b1 * 100 + c1;
        b[i].b = d * 10000 + e * 100 + f;
    }
    sort(b, b + n, cmp);
    for (int i = 0; i < n - 1;i++){
        for (int j = i+1; j < n;j++){
            if(b[j].a < b[i].b){
                g[i][j] = g[j][i] = 1;
                b[i].degree++;
                b[j].degree++;
                dsum++;
            }
        }
    }
    sort(b, b + n, cmp1);
    for (int i = 0; i < n && dsum > 0;i++,cnt++){
        dsum -= b[i].degree;
    }
    cout << n-cnt;
}