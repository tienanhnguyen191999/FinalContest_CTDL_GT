#include <iostream>
using namespace std;

int mang[25],n,c;

void nhap(){
    cin >> c  >> n;
    for (int i =0  ; i < n ; i++) cin >> mang[i];
}
void selectionSort(){
    int minn = 0;
    for (int i = 0 ; i < n ; i++){
        for (int j = i + 1; j < n; j++){
            if (mang[minn] < mang[j]){
                minn = j;
            }
        }
        swap(mang[i],mang[minn]);
    }
}

void solve(){
    int s =0;
    selectionSort();
    for (int i = 0 ; i < n ; i++){
        if (mang[i] <= c){
            c-=mang[i];
            s+=mang[i];
        }

    }
    cout << s;
}

int main(){
    nhap();
    solve();
    return 0;
}