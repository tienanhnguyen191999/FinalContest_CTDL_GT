#include <iostream>

using namespace std;

int mang[100],k,n;
void check(){
    int c = 0;
    for (int i = 0 ; i < n ; i++){
        if (mang[i] == 1) c++;
    }
    if (c == k) {
        for (int i = 0 ; i < n; i++){
            cout << mang[i];
        }
        cout << endl;
        return;
    }
}
void  tryy(int m){
    for (int i = 0 ; i <= 1; i++){
        mang[m] = i;
        if (m == n-1){
            check();
        }
        else{
            tryy(m+1);
        }
    }
}
int main(){
    int turn;
    cin >> turn;
    while (turn--){
        cin >> n >> k;
        tryy(0);
    }
    return 0;
}