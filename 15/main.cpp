#include <iostream>

using namespace std;
int n,k,mang[1000];
void nhap(){
    cin >> n >> k;
    for (int i = 0 ; i < n ; i ++ ){
        cin >> mang[i];
    }
}
void sapxep(){
    for (int i = 0 ; i < n-1 ; i++){
        for (int j = i + 1; j < n; j++){
            if (mang[i] > mang[j]){
                swap(mang[i],mang[j]);
            }
        }
    }
}

void binarySearch(int left,int mid,int right){
    //cout << "left: " << left << " right: " << right << endl;
    if (left >= right){
        if (mang[left] == k) {
            cout << k;
            return;
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }
    if (mang[mid] == k){
        cout << "Found" << endl;
        return;
    }
    else if (mang[mid] < k){
        binarySearch(mid+1,(mid+1+right)/2,right);
    }
    else{
        binarySearch(left,(mid-1+left)/2,mid-1);
    }
    
} 
int main(){
    int turn;
    cin >> turn;
    while(turn--)
    {
        nhap();
        sapxep();
        binarySearch(0,(n-1)/2,n-1);
    }
    return 0;
}