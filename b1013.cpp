#include<iostream>
using namespace std;
bool Is_prime(long long n){
    for (int i = 2; i * i <= n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}
int main(){
    int a, b, i=1;
    cin >> a >> b;
    for (long long n = 2; i <= b; n++){
        if(Is_prime(n)) {
            if(i>=a){
                cout << n;
                if((i-a+1)%10 && i<b)
                    cout << ' ';
                else
                    cout << endl;
            }
            i++;
        }
    }
}