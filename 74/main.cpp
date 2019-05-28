#include <iostream>
#include <cstring>
using namespace std;

char x[100][100];
int  n = 4;
void init(){
    int i =0;
    int tmp = n;
    while(tmp--){
        cin >> x[i++];
    }
}


void solve(){
    for (int i = 0 ; i < n; i++){
        for (int j = strlen(x[i]) - 1 ; j >= 0; j-- ){
            cout << x[i][j];
        }
        cout << " ";
    }
    cout << endl;
}
int main(){
    init();
    solve();
    return 0;
}