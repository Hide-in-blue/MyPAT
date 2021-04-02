#include<iostream>
#include<vector>
using namespace std;
int n, maxp;
bool isPrime(int x){
    if(x==1)
        return false;
    for (int i = 2; i * i <= x;i++)
        if(x % i == 0)
            return false;
    return true;
} 
int main(){
    cin >> n >> maxp;
    if(n>1){
    for (int cd = maxp / (n - 1); cd > 0;cd--){//gongcha 250--
        vector<int> v;
        for (int i = maxp;i>=1+(n-1)*cd;i--){ // start from maxp--
            for (int j = i; j >= 1;j-=cd){
                if(isPrime(j))
                    v.push_back(j);
                else{
                    v.clear();
                    break;
                }
            }
            if(v.size()){
                for (int k = v.size() - 1; k >= 0;k--){
                    if(k < v.size()-1)
                        cout << ' ';
                    cout << v[k];
                }
                return 0;
            }
        }
    }
    }
    for (int i = maxp; i > 1;i--){
        if(isPrime(i)){
            cout << i;
            return 0;
        }
            
    }
}