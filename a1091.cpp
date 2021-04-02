#include<iostream>
#include<queue>

using namespace std;

int post[32], in[32];
struct node {
    int data;
    node *left, *right;
};
queue<node*> q;
node* create(int postL,int postR,int inL,int inR){
    int k;
    if(postL>postR)
        return NULL;
    node *root = new node;
    root->data = post[postR];
    for (k = inL; k <= inR;k++){
        if(in[k]==post[postR]){
            break;
        }
    }
    int numLeft = k - inL;
    root->left = create(postL, postL + numLeft-1, inL, k - 1);
    root->right = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}

int main(){
    int N,count=0;
    
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> post[i];
        cin >> in[i];
    }

    node* tree = new node;
    tree = create(0, N - 1, 0, N - 1);

    q.push(tree);
    cout << tree->data;
    while(!q.empty()){
        node *front = q.front();
        count++;
        if(count>1)
            cout << ' ' << front->data;
        q.pop();
        if(front->left!=NULL)
            q.push(front->left);
        if(front->right!=NULL)
            q.push(front->right);
    }
}