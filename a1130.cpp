#include<iostream>
#include<cstring>
using namespace std;

struct node{
    string data;
    int left, right;
} tree[21];
int n, root, visited[21] = {0};

void inordertraversal(int index, int leftorright){
    if(index == -1)
        return;
    if(index != root && tree[index].left+tree[index].right != -2) cout << '(';
    inordertraversal(tree[index].left, 1);
    cout << tree[index].data;
    inordertraversal(tree[index].right, 2);
    if(index != root && tree[index].left+tree[index].right != -2) cout << ')';
}

int main(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> tree[i].data >> tree[i].left >> tree[i].right;
        visited[tree[i].left] = visited[tree[i].right] = 1;
    }
    for (int i = 1; i <= n;i++) if(visited[i] == 0)
        root = i;
    inordertraversal(root, 0);
}
