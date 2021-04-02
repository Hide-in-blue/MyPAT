#include<iostream>
#include<vector>
using namespace std;
const long long inf = 10000000002;
long long tree[2050];
int n, f = 0;
vector<long long> v;
void dfs(long long index){
    if(index > n){
        if(index - 1 > n && (index % 2) == 0){
            long long t = v[0];
            for (int i = 0; i < v.size();i++){
                if(i){
                    cout << ' ';
                    if(v[i] < t){
                        if(f == 0)
                            f = 1;
                        else if(f == 2)
                            f = -1;
                    }
                    else if (v[i] > t){
                        if(f == 0)
                            f = 2;
                        else if(f == 1)
                            f = -1;
                    }
                }
                cout << v[i];
            }
            cout << endl;
        }
        return;
    }
    v.push_back(tree[index]);
    dfs(index * 2 + 1);
    dfs(index * 2);
    v.pop_back();
    return;
}

int main(){
    fill(tree, tree + 2050, inf);
    cin >> n;
    for (int i = 1;i<=n;i++)
        cin >> tree[i];
    dfs(1);
    if(f == -1)
        cout << "Not Heap";
    else if(f == 1)
        cout << "Max Heap";
    else if(f == 2)
        cout << "Min Heap";
}