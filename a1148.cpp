#include<iostream>
using namespace std;
struct fayan{
    int id, f;
} fy[110];
int n,cntw,cur[110],flag[5],cntf;
int main(){
    cin >> n;
    fill(cur, cur + 110, -1);
    for (int i = 1; i <= n;i++){
        char c;
        int a;
        cin >> c >> a;
        fy[i].id = a;
        if(c=='-'){
            fy[i].f = 1;
            cntw++;
        }
        else
            fy[i].f = 0;
        if(cur[a]!=-1&&cur[a]+fy[i].f==1){
            flag[cntf++]=
        }
    }
    for (int p = 1; p < n;p++)
        for (int q = 2; q <= n;q++){//p,q are the liars;
            fy[p].f = !fy[p].f;
            fy[q].f = !fy[q].f;
            //no more than two wolves;
            if(fy[p].f==1)
                cntw++;
            else
                cntw--;
            if(fy[q].f==1)
                cntw++;
            else
                cntw--;
            if(cntw>2)
                continue;
            //no shuangchong shenfen
            //no less than two wolves
            fy[p].f = !fy[p].f;
            fy[q].f = !fy[q].f;
        }
}