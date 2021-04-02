#include <iostream>
#include<cstring>
using namespace std;

int main(){
    char c[5];
    for (int i = 0; i < 4;i++)
        cin >> c[i];
    int a = atoi(c);
    cout << a + 1;
}