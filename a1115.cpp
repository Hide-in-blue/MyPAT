#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

struct node{
    int v;
    node *left, *right;
};
int cnt[1002] = {0};
void Insert(node* &root, int x){
    if (root == NULL){
        root = new node;
        root->v = x;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    else if(x > root->v){
        Insert(root->right, x);
    }
    else
        Insert(root->left, x);
}
void dfs(node *root, int level){
    if(root == NULL)
        return;
    cnt[level]++;
    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
}
int main(){
    int N, k;
    cin >> N;
    node *root = NULL;
    for (int i = 0; i < N;i++){
        int t;
        cin >> t;
        Insert(root, t);
    }
    dfs(root, 0);
    for (k = 0; cnt[k];k++)
        ;
    printf("%d + %d = %d", cnt[k - 1], cnt[k - 2], cnt[k - 1] + cnt[k - 2]);
}