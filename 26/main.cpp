#include <iostream>

using namespace std;
int n;
void solve(){
    int k7 = n / 7,k4,bol = 0;
    for (int i = k7 ; i >= 0; i--){
        if ( (n-i*7) % 4 == 0 ){
            bol = 1;
            k4 = (n-i*7) / 4; 
            for (int j = 0 ; j < k4 ; j++) cout << "4";
            for (int j = 0 ; j < i ; j++) cout << "7";
            cout << endl;
            break;
        }
    }
    if (!bol) cout << "-1\n";
}

int main(){
    int turn;
    cin >> turn;
    while (turn--){
        cin >> n;
        solve();
    }
    return 0;
}