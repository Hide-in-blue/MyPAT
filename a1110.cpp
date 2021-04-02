#include<iostream>
using namespace std;
int tr[100000];
int n,In[22][2],root;
void Create(int p){
    tr[p*2]=
}
int main(){
    fill(In[0], In[0] + 22 * 2, -1);
    cin >> n;
    for (int i = 0; i < n;i++){
        char c1, c2; 
        cin >> c1 >> c2;
        if(c1!='-')
            In[i][0] = c1 - '0';
        if(c2!='-')
            In[i][1] = c2 - '0';
    }
    for (int i = 0; i < n;i++){
        int f = 0;
        for (int j = 0; j < n;j++){
            if(In[j][0]==i||In[j][1]==i)
                f = 1;
        }
        if(f==0)
            root = i;
    }
    tr[1] = root;
    int p = root;
    Create(1);
    cout << "NO " << root;
}