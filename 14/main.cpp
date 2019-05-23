#include <iostream>

using namespace std;
int n,k;
void nhap(){
    cin >> n >> k;
}

void solve (){
    int s = 1;
    int MODULO = 1000000007;
    for (int i = 0; i < k ; i++ ){
        s *= n;
        if (s > MODULO){
            s %= MODULO;
        }
    }
    cout << s << endl;
}
int main(){
    int turn;
    cin >> turn;
    while (turn--){
        nhap();
        solve();
    }
    return 0;
}