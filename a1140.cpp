#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<int> a, b;
int d, n;

int main(){
    
    cin >> d >> n;
    a.push_back(d);
    for (int i = 1; i < n;i++){
        for (int j = 0, p = 0; j <= a.size();j++){
            if(j == int(a.size()) || a[j] != a[p]){
                b.push_back(a[p]);
                b.push_back(j - p);
                p = j;
            }
        }
        a = b;
        b.clear();
    }
    for (int i = 0; i < a.size();i++)
        cout << a[i];
}