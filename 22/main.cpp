#include <iostream>

using namespace std;


void solve(int n){
    if (n % 2 == 1){
        cout << 0 << endl;
        return;
    }
    int c = 0;
    for (int i = 2; i <= n/2 ; i+=2){
        if (n % i == 0) c++;
    }
    cout << c+1 << endl;
}
int main(){
    int turn,n;
    cin >> turn;
    while (turn--){
        cin >> n;
        solve(n);
    }
    return 0;
}