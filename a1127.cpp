#include<queue>
#include<iostream>
#include<vector>
using namespace std;
struct node{
    int v, level;
    node *left, *right;
} * root;
int n;
vector<int> vin, vpost, ans[35];
node* build(int inleft, int inright, int postleft, int postright, int level){
    if(postleft > postright){
        return NULL;
    }
    int p;
    for (p = inleft; p <= inright;p++)
        if(vin[p]==vpost[postright])
            break;
    node *root = new node;
    root->v = vpost[postright];
    root->left = build(inleft, p - 1, postleft, postleft + p - inleft - 1, level+1);
    root->right = build(p + 1, inright, postleft + p - inleft, postright - 1, level+1);
    root->level = level;
    return root;
}
void bfs(){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *t = q.front();
        q.pop();
        ans[t->level].push_back(t->v);
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }
}
int main(){
    cin >> n;
    vin.resize(n);
    vpost.resize(n);
    for (int i = 0; i < n;i++)
        cin >> vin[i];
    for (int i = 0; i < n;i++)
        cin >> vpost[i];
    root = build(0, n - 1, 0, n - 1, 0);
    bfs();
    cout << ans[0][0];
    for (int i = 1; i < 35;i++){
        if(i%2){
            for (int j = 0; j < ans[i].size();j++)
                cout << ' ' << ans[i][j];
        }
        else{
            for (int j = ans[i].size() - 1; j >= 0; j--)
                cout << ' ' << ans[i][j];
        }
    }
}