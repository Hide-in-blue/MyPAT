#include<iostream>
using namespace std;
const int INF = 1000000000;
int h[2020];
void Postorder_Traversal(int p,int cnt){
    if(h[p]==INF)
        return;
    Postorder_Traversal(p * 2, cnt + 1);
    Postorder_Traversal(p * 2 + 1, cnt + 1);
    cout << h[p];
    if(cnt>1)
        cout << ' ';
}
int main(){
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m;i++){
        int f = 0, t=0, ff=0, p;
        fill(h, h + 2020, INF);
        for (int j = 1; j <= n;j++){
            cin >> h[j];
            if(j>1){
                p = j % 2 ? (j - 1) / 2 : j / 2;
                if(t==0&&h[j]>h[p]){
                    f = 2;//min
                    t = 1;
                }
                else if(t==0&&h[j]<h[p]){
                    f = 1;//max
                    t = 1;
                }   
                if(t){
                    if((f==1&&h[j]>h[p])||(f==2&&h[j]<h[p]))
                        ff = 1;
                }
            }
        }
        if(ff==1)
            cout << "Not Heap" << endl;
        else if(f==1)
            cout << "Max Heap" << endl;
        else if(f==2)
            cout << "Min Heap" << endl;
        Postorder_Traversal(1,1);
        cout << endl;
    }
    

}