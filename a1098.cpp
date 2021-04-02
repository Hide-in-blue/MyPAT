#include<iostream>
#include<vector>
using namespace std;

int n, t, flag;
vector<int> v1, v2, v3, vi, vh;
void Insertsort(){
    for (int i = 2; i <= n;i++){
        int k,temp=vi[i];
        for (int j = 1; j < i;j++){
            k = j;
            if(temp>vi[j]&&temp<=vi[j+1]){
                k = j + 1;
                break;
            }
            if(temp<vi[j])
                break;
        }
        for (int j = i; j > k;j--){
            vi[j] = vi[j - 1];
        }
        vi[k] = temp;
        if(flag==1){
            v3 = vi;
            break;
        }
        if(vi==v2)
            flag = 1;
    }
}
void Adjustdown(int low, int high){
    while(2*low<=high){
        int son = 2 * low, j=son, temp;
        if(son+1<=high&&vh[son+1]>vh[son])
            j = son + 1;
        if(vh[j]>vh[low]){
            temp = vh[low];
            vh[low] = vh[j];
            vh[j]=temp;
        }
        low = j;
    }
}
void Heapsort(){
    //create heap;
    for (int i = n / 2; i > 0;i--){
        Adjustdown(i, n);
    }
    //sort
    for (int i = n; i > 1;i--){
        int t1 = vh[1];
        vh[1] = vh[i];
        vh[i] = t1;
        Adjustdown(1, i - 1);
       
        if (flag == 2)
        {
            v3 = vh;
            break;
            }
        if(vh==v2)
            flag = 2;
    }
}
int main(){
    cin >> n;
    v1.push_back(0);
    v2.push_back(0);
    for (int i = 0; i < n;i++){
        cin >> t;
        v1.push_back(t);
    }
    vi = v1;
    vh = v1;
    for (int i = 0; i < n;i++){
        cin >> t;
        v2.push_back(t);
    }
    Insertsort();
    Heapsort();
    if(flag==2){
        cout << "Heap Sort" << endl;
        cout << v3[1];
        for (int i = 2; i <= n;i++)
            cout << ' ' << v3[i];
    }
    else if(flag==1){
        cout << "Insertion Sort" << endl;
        cout << v3[1];
        for (int i = 2; i <= n;i++)
            cout << ' ' << v3[i];
    }
    else
        cout << "I dont love you anymore" << endl;
}