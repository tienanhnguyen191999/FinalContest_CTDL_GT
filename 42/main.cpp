#include <iostream>

using namespace std;

void selectionSort(int mang[], int n){
    int minn = 0;
    for (int i = 0 ; i < n-1 ; i++){
        for ( int j = i + 1; j < n; j++){
            if (mang[minn] > mang[j]){
                minn = j;
            }
        }
        swap(mang[minn],mang[i]);
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

    selectionSort(mang,n);
    return 0;
}