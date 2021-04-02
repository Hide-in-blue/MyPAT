#include<iostream>
#include<cstring>
using namespace std;
string s1, s2;
long long  tag, ra, a, b;
int main(){
    cin >> s1 >> s2 >> tag >> ra;
    int l1 = s1.length(), l2 = s2.length();
    if(tag==1){
        for (int i = 0; i < l1;i++){
        if(s1[i]>='0'&&s1[i]<='9')
            a = a * ra + (s1[i] - '0');
        else a = a * ra + (s1[i] - 'a' + 10);
    }
    for (int r = 2; r < 37;r++){
        b = 0;
        for (int j = 0; j < l2;j++){
            long long  tt;
            if(s2[j]>='0'&&s2[j]<='9')
                tt = s2[j] - '0';
            else
                tt = s2[j] - 'a' +10;
            if(tt>=r)
                goto here1;
            b = b * r + tt;
        }
        if(b==a){
            cout << r;
            return 0;
        }
        if(b>a)
            goto h1;
    here1:;
    }
    h1:
    cout << "Impossible";
    return 0;
    }
    string s3 = s1;
    s1 = s2;
    s2 = s3;
    for (int i = 0; i < l2;i++){
        if(s1[i]>='0'&&s1[i]<='9')
            a = a * ra + (s1[i] - '0');
        else a = a * ra + (s1[i] - 'a' + 10);
    }
    for (int r = 2; r < 37;r++){
        b = 0;
        for (int j = 0; j < l1;j++){
            long long tt;
            if(s2[j]>='0'&&s2[j]<='9')
                tt = s2[j] - '0';
            else
                tt = s2[j] - 'a' +10;
            if(tt>=r)
                goto here;
            b=b*r+tt;
        }
        if(b==a){
            cout << r;
            return 0;
        }
        if(b>a)
            goto h;
    here:;
    }
    h:
    cout << "Impossible";
    return 0;
}