#include <iostream>
#include<stack>
using namespace std;
struct node{
    int data;
    node *left, *right;
};
string s;
stack<int> z;
int N, a, cnt=1,cnt1,in[32], pre[32],lenpre,lenin;
node* create(int inL,int inR,int preL,int preR){
    if(preL>preR)
        return NULL;
    node *root = new node;
    cnt1++;
    root->data = pre[preL];
    int k;
    for (k = inL; k <= inR;k++){
        if(in[k]==pre[preL])
            break;
    }
    int numleft = k - inL;
    root->left = create(inL, k - 1, preL + 1, preL + numleft);
    root->right = create(k + 1, inR, preL + numleft + 1, preR);
    return root;
}
void tip(node* root){
    if(root==NULL)
        return;
    tip(root->left);
    tip(root->right);
    // if(lenin>1){
    //     cout << root->data <<' ';
    //     lenin--;
    // }
    // else if(lenin==1)
    //     cout << root->data<<' '<<"oh";
    if(cnt==1){
        cout << root->data;
    }
    else
        cout << ' ' << root->data;
    cnt++;
}
int main(){
    cin >> N;
    for (int i = 0; i < 2 * N;i++){
        cin >> s;
        if(s=="Push"){
            cin >> a;
            pre[++lenpre] = a;
            z.push(a);
        }
        else{
            in[++lenin] = z.top();
            z.pop();
        }
    }
    if(lenin!=lenpre)
        cout << "cinerror" << endl;
    node* Root=create(1,lenin,1,lenin);
    tip(Root);
}