#include<iostream>
#include<map>
using namespace std;
struct node{
    int a, b;
} s[2];
int main(){
    map<string, node> m;
    m["s"] = s[0];
    if(m.find("s")->second)
        cout << 1;
    else
        cout << 0;
}