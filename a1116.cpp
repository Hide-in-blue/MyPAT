#include<iostream>
using namespace std;

int N, M, Rank[10002] = {0}, Q[10002] = {0};
bool checked[10002] = {false}, Yeah[10002] = {false};
bool isPrime(int x){
    for (int i = 2; i * i <= x;i++){
        if(x%i==0)
            return false;
    }
    return true;
}
int main(){
    cin >> N;
    for (int i = 1; i <= N;i++){
        int id;
        cin >> id;
        Rank[i] = id;
        Q[id] = i;
        if(isPrime(i))
            Yeah[id] = true;
    }
    cin >> M;
    for (int i = 0; i < M;i++){
        int id;
        cin >> id;
        if(Q[id] == 0)
            printf("%04d: Are you kidding?\n", id);
        else if(checked[id])
            printf("%04d: Checked\n");
        else if(Q[id]==1)
            printf("%04d: Mystery Award\n");
        else if(Yeah[id])
            printf("%04d: Minion\n");
        else
            printf("%04d: Chocolate\n");
        checked[id] = true;
    }
}