#include <iostream>

using namespace std;
int n,s,a[100];


void nhap(){
    cin >> n >> s;
    for (int i = 0 ; i < n ; i++) cin >> a[i];
}

void solve(){
    int c = 0,index = n-1,k=0;
    while ( s > 0){
        if (s >= a[index]){
            k = s /a[index];
            s -= k*a[index];
            c += k;
        }
        index--;
    }
    cout << c;
}
int main(){
    nhap();
    solve();
    return 0;
}