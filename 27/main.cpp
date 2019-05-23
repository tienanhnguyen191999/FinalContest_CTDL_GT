#include <iostream>

using namespace std;
//int mang[100] = {10,9,8,3,3,2,1};
int mang[100] = {2,4,1,2,10,2,3};
int n = 7;
// Dựa trên priority queue làm

void hienthi(){
    for (int i = 0 ; i < n ; i++){
        cout << mang[i] << " ";
    }
    cout << endl;
}
void insertt (int k){
    if ( k <= mang[n-1] ){
        mang[n] = k;
        n++;
        return;
    }
    for (int i = 0 ; i < n ; i++){
        if (k >= mang[i]){
            for (int j = n ; j > i  ; j--)
            {
                mang[j] = mang[j-1];
            }
            mang[i] = k;
            n++;
            break;
        }
    }
}

void sapxep(){
    for (int i = 0 ; i < n ; i++){
        for (int j = i + 1;  j < n;  j++){
            if (mang[i] < mang[j]){
                swap(mang[i],mang[j]);
            }
        }
    }
}

void solve(){  
    sapxep();
    int s = 0;
    int tmp;
    while ( n > 0){
        //hienthi();
        tmp = mang[n-1] + mang[n-2];
        n-=2;
        insertt(tmp);
        s+=tmp;
    }
    cout << s;
}
int main(){
    cin >> n;
    for (int i = 0 ; i < n; i++) cin >> mang[i];
    solve();
    return 0;
}