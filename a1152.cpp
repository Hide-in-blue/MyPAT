#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
bool isPrime(long long x){
    for (int i = 2; i * i < x;i++){
        if(x % i==0)
            return false;
    }
    return true;
}
string s; 
int n, k;
string getstr(int p){
    string res = "";
    for (int i = p; i < p + k;i++)
        res += s[i];
    return res;
}
long long Stoi(string s){
    long long a = 0;
    for (int i = 0; i < s.length();i++){
        a = a * 10 + (s[i] - '0');
    }
    return a;
}
void Output(long long a){
    long long t = a;
    vector<int> v;
    while(a){
        v.push_back(a % 10);
        a /= 10;
    }
    int len = v.size();
    for (int i = 0;i<k-len;i++){
        cout << '0';
    }
    cout << t;
}
int main(){
    cin >> n >> k >> s;
    if(n<k){
        cout << "404";
        return 0;
    }
    for (int i = 0; i < n - k;i++){
        string s1 = getstr(i);
        long long l = Stoi(s1);
        if(isPrime(l)){
            Output(l);
            return 0;
        }
    }
    cout << "404";
    return 0;
}