#include <iostream>
using namespace std;
int mang[10000],n,minn=10000000,c=0;

void nhap(){
    cin >> n ;
    for (int i = 0 ; i < n ; i++){
        cin >> mang[i];
    }
}

void solve(){
    for (int i = 0 ;i < n-1 ; i++){
        for (int j = i+1; j <n ; j++){
            if (abs(mang[i] - mang[j]) < minn){
                minn = abs(mang[i] - mang[j]);
                c = 1;
            }
            else if ( abs(mang[i] - mang[j]) == minn){
                c++;
            }
        }
    }
}

int main(){
    int turn;
    cin >> turn;
    while (turn--){
        nhap();
        solve();
        cout << minn << " " << c << endl;
        minn = 100000;
    }
    return 0;
}