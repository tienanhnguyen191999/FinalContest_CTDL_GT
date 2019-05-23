#include <iostream>

using namespace std;

void tribonacci(int n){
    int MODULO = 1000000007;
    int mang[1000],s = 6;
    mang[1] = 1;
    mang[2] = 2;
    mang[3] = 3;
    for (int i = 4 ; i <= n ; i++){
        mang[i] = mang[i-1] + mang[i-2] + mang[i-3];
        s+=mang[i];
        if (mang[i] > MODULO){ mang[i] %= MODULO;}
        if (s > MODULO){ s %= MODULO;}
    }
    if (n == 1) cout << "1\n";
    else if (n == 2) cout << "3\n";
    else if (n == 3) cout << "6\n";
    else cout << s << endl;
}
int main(){
    int turn, n;
    cin >> turn;
    while (turn--){
        cin >> n;
        tribonacci(n);
    }
    return 0;
}