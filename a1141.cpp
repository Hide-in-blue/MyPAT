#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
string ToLower(string s){
    char c[7];
    strcpy(c, s.c_str());
    for (int i = 0; i < s.length();i++){
        if(c[i] < 'a')
            c[i] = c[i] + 32;
    }
    string s1 = c;
    return s1;
}
struct S{
    string sname;
    double score;
    int ns;
} st[100002];

map<string, int> strtoint;
map<int, string> inttostr;
int n, s, cnt = 0;

bool cmp(S a,S b){
    if(a.score != b.score)
        return a.score > b.score;
    else{
        if(a.ns != b.ns)
            return a.ns < b.ns;
        else
            return a.sname < b.sname;
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n;i++){
        char c;
        double level;
        int tid, ts;
        string tsch;
        cin >> c >> tid >> ts >> tsch;
        if(c == 'B')
            level = 2;
        else if(c =='A')
            level = 3;
        else
            level = 4.5;
        tsch = ToLower(tsch);
        if(strtoint.count(tsch) == 0){
            cnt++;
            strtoint[tsch] = cnt;
            inttostr[cnt] = tsch;
            st[cnt].sname = tsch;
            st[cnt].score = level * ts;
            st[cnt].ns = 1;
        }
        else{
            st[strtoint[tsch]].score += level * ts;
            st[strtoint[tsch]].ns++;
        }
    }
    for (int i = 1; i <= cnt;i++){
        st[i].score = floor(st[i].score / 3.0);
        // cout << st[i].sname << ' ' << int(st[i].score) << ' ' << st[i].ns << endl;
    }
        

    
    sort(st + 1, st + cnt + 1, cmp);
    cout << cnt << endl;
    for (int i = 1, rank = 1; i <= cnt;i++){
        if(i > 1 && st[i].score != st[i-1].score)
            rank = i;
        cout << rank << ' ' << st[i].sname << ' ' << int(st[i].score) << ' ' << st[i].ns << endl;
    }
}