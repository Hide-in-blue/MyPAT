#include<iostream>
#include<cstring>
#include<map>
using namespace std;
//stucked keyboard
// Sample input:
//     3
//     caseee1__thiiis_iiisss_a_teeeeeest
// Sample Output:
//     ei
//     case1__this_isss_a_teest
//事后清算法 遍历s 用current标记当前嫌疑字符，进入下一字符或最大长度时清算嫌疑
//鉴于有一次清白证明即可洗白，故应设全部字符默认有罪（有罪不容易判定，而洗白很容易）
int main(){
    int t = 0, k;
    map<char, int> m;
    string s;
    cin >> k >> s;
    char cur = s[0];
    for (int i = 0; i < s.length();i++){
        m[s[i]] = 1;
        if (s[i] != cur){
            if (t % k)
                m[cur] = 0;
            cur = s[i];
            t = 1;
            if(i == s.length()-1)
                m[cur] = 0;
        }
        else if (i == s.length()-1 && s[i] == cur){
            if (++t % k)
                m[cur] = 0;
        }
        else
            t++;
    }
    for (int i = 0; i < s.length();i++){
        if(m[s[i]]==1){
            cout << s[i];
            m[s[i]] = 2;
        }
    }
    cout << endl;
    for (int i = 0; i < s.length();i++){
        cout << s[i];
        if (m[s[i]]==2)
            i += k - 1;
    }
}
