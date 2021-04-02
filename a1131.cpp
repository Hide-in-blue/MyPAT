#include<iostream>
#include<vector>
using namespace std;

int n, m, k;
vector<int> v[10002];

int main(){
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> m;
        int front, back;
        cin >> back;
        for (int j = 1; j < m;j++){
            cin >> front;
            v[back].push_back(front);
            v[front].push_back(back);
            back = front;
        }
    }
    
}