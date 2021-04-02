#include<iostream>
using namespace std;
struct Node{
    int data,flag;
    Node *left, *right;
};
int N, in[1010];
bool Getyou = false, Getyou1 = false;
Node* Newnode(int a){
    Node *nnnode = new Node;
    nnnode->data = a;
    nnnode->left = NULL;
    nnnode->right = NULL;
    return nnnode;
}

void Insert(Node* &root,int a){
    if(root==NULL){
        root = Newnode(a);
        return;
    }
    if(a < root->data){
        if(root->flag==1)
            Getyou = true;
        Insert(root->left, a);
    }
    if(a >= root->data){
        root->flag = 1;
        Insert(root->right, a);
    }
}
void Insert1(Node* &root,int a){
    if(root==NULL){
        root = Newnode(a);
        return;
    }
    if(a >= root->data){
        if(root->flag==1)
            Getyou1 = true;
        Insert1(root->left, a);
    }
    if(a < root->data){
        root->flag = 1;
        Insert1(root->right, a);
    }
}

Node* create(int a[],int n){
    Node *root = NULL;
    for (int i = 0; i < n;i++)
        Insert(root, a[i]);
    return root;
}
Node* create1(int a[],int n){
    Node *root = NULL;
    for (int i = 0; i < n;i++)
        Insert1(root, a[i]);
    return root;
}

void pip(Node* root, int n){
    if(root==NULL)
        return;
    pip(root->left,n+1);
    pip(root->right,n+1);
    if(n)
        cout << root->data << ' ';
    else
        cout << root->data;
}
int main(){
    cin >> N;
    for (int i = 0; i < N;i++)
        cin >> in[i];
    Node *root = new Node;
    root = create(in, N);
    Node *root1 = new Node;
    root1 = create1(in, N);
    if(Getyou==true&&Getyou1==true){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if(Getyou==false)
        pip(root,0);
    else{
        pip(root1,0);
    }
        
}