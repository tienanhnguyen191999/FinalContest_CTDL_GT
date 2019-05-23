#include <iostream>

using namespace std;

int a[100],b[100],n;
void sapxep(){
    for (int i = 0 ;  i  < n; i++){
        for (int j = i + 1; j < n; j++){
            if (b[i] > b[j]){
                swap(a[i],a[j]);
                swap(b[i],b[j]);
            }
        }
    }
}

void nhap(){
    cin >> n;
    for (int i = 0; i < n ; i++){
        cin >> a[i] >> b[i];
    }
}

void solve(){
    sapxep();
    int c = 1,end = b[0];
    for (int i = 1 ; i < n ; i++){
        if ( a[i] > end){
            c++;
            end = b[i];
        }
    }
    cout << c;
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