#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n, cur;
priority_queue<double, vector<int>, greater<double>> q;
int main(){
    cin >> n;
    for (int i = 0; i < n;i++){
        int t;
        cin >> t;
        q.push(t);
    }
    for (int i = 1; i < n;i++){
        double a = q.top();
        q.pop();
        double b = q.top();
        q.pop();
        q.push((a + b)/2);
    }
    cout << int(q.top());
}