#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double N;
int rn, ln, num3, yu, ceng, rootid, n, a[1010], level[1010];
//I love you baby.
struct node{
    int data;
    node *left, *right;
};
node* newNode(int v){
    node *Node = new node;
    Node->data = v;
    Node->left = Node->right = NULL;
    return Node;
}
int calc(int N){//find rootid, ln and rn.
    ceng = log(N+1) / log(2) ;
    num3 = pow(2, ceng - 1) - 1;
    yu = N - pow(2, ceng) + 1;
    if(yu*2<=pow(2,ceng)){
        rn = num3;
        ln = num3 + yu;
    }
    else{
        ln = pow(2, ceng) - 1;
        rn = N - ln - 1;
    }
    rootid = N - rn - 1;
    return rootid;
    //I love you..
}

void create(int N,int lef,node* &root){//递归地寻找并新建结点 注意参数
    if(N==0)
        return;
    int id = calc(N);
    root = newNode(a[lef + id]);
    create(id, lef, root->left);
    create(N - id - 1, id + lef + 1, root->right);
}


void dfs(node* root,int p){
    if(root==NULL)
        return;
    level[p] = root->data;
    dfs(root->left, p * 2);
    dfs(root->right, p * 2 + 1);
}

int main()
{
    cin >> n;
    N = n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    // cout << "I love you";
    node *root = new node;
    create(n,0,root);
    dfs(root,1);
    for (int i = 1; i <= n;i++){
        if(i==1)
            cout << level[i];
        else
            cout << ' ' << level[i];
    }
    // int rootid = N - pow(2, (int)(log(N) / log(2))-1);
    //I love you...
}