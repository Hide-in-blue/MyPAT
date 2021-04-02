#include<iostream>
using namespace std;
int Msize, M, N, Sumtime;
int H[10010] = {false};
bool IsPrime(int a){
    for (int i = 2; i * i <= a;i++)
        if(a%i==0)
            return false;
    return true;
}
int FindPrime(int a){
    for (int i = a;;i++)
        if(IsPrime(i))
            return i;
}
void Quadratic_probing(int a,int Msize){
    int yu = a % Msize;
    for (int j = 0;;j++){
        int p = (yu + j * j) % Msize;
        if(!H[p]){
            H[p] = a;
            break;
        }
        if(j==Msize-1){
            cout << a << " cannot be inserted." << endl;
            break;
        }
    }
}
int Searchtime(int a){
    int yu = a % Msize;
    for (int j = 0;j<=Msize;j++){
        int p = (yu + j * j) % Msize;
        if(H[p]==a||H[p]==0||j==Msize)
            return j + 1;
    }
}
int main(){
    cin >> Msize >> N >> M;
    Msize = FindPrime(Msize);
    for (int i = 0; i < N;i++){
        int a;
        cin >> a;
        Quadratic_probing(a, Msize);
    }
    for (int i = 0; i < M;i++){
        int a;
        cin >> a;
        Sumtime += Searchtime(a);
        
    }
    printf("%.1f", double(Sumtime) / M + 0.05);
}