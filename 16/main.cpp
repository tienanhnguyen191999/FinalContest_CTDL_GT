#include <iostream>

using namespace std;

int save[10000] = {1};
int n,k;
void nhap(){
    cin >> n >> k;
}

void solve(){
    int l = 1;
    for (int i = 0 ; i < n  ; i++){
        save[l] = i+2;
        for (int j = l+1 ; j < 2*l+1 ; j++){
            save[j] = save[j-l-1];
        }
        l = l*2 + 1;
    }
    // for (int i = 0 ; i < l ; i++){
    //     cout << save[i];
    // }
    cout << save[k-1]<< endl;
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