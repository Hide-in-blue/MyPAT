#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
struct t{
    int left, right;
} t[12];
int N, a[2000], f[12], r, ling, cnt;
char c1, c2;
void create(int r,int p){
    if(r==-1)
        return;
    create(t[r].left,p*2);
    create(t[r].right, p * 2 + 1);
    a[p] = r;
    if(r==0)
        ling = p;
}
void til(void){
    for (int n = 1; n < 1000;n*=2)
        for (int i = 2 * n - 1; i >= n; i--){
            if(n==1)
                cout << a[i];
            else if(a[i]!=0||i==ling)
                cout << ' ' <<a[i];
        }
}
void tii(int p){
    if(a[p]==0&&p!=ling)
        return;
    tii(p * 2 + 1);
    if(cnt==0){
        cout << a[p];
        cnt++;
    }
    else
        cout << ' ' << a[p];
    tii(p * 2);
}
int main(){
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> c1 >> c2;
        if(c1!='-'){
            t[i].left = c1 - '0';
            f[t[i].left] = 1;
        }
        else
            t[i].left = -1;
        if(c2!='-'){
            t[i].right = c2 - '0';
            f[t[i].right] = 1;
        }
        else
            t[i].right = -1;
    }
    for (int i = 0; i < N;i++){
        if(f[i]==0)
            r = i;
    }
    a[1] = r;
    create(r,1);
    til();
    cout << endl;
    tii(1);
}