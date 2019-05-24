#include <iostream>

using namespace std;

void selectionSort_old(int mang[], int n){
    for (int i = 0 ; i < n-1 ; i++){
        for ( int j = i + 1; j < n; j++){
            if (mang[i] > mang[j]){
                swap(mang[i],mang[j]);
            }
        }
        cout << "BUOC "<< i+1 << ": ";
        for (int m = 0 ; m < n ; m++){ cout << mang[m] << " ";} cout << endl;
    }
}

int main(){
    int n, mang[100];
    cin >> n;
    for (int i = 0 ;  i < n ; i++){
        cin >> mang[i];
    }

    selectionSort_old(mang,n);
    return 0;
}