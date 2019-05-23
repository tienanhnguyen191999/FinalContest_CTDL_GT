#include <iostream>

using namespace std;

int mang[100] = {1,2,5,10,20,50,100,200,500,1000};
int total = 0,n,index  = 9;

void solve(){
    int k;
    while (n != 0){
        if (n >= mang[index]){
            k = n / mang[index];
            n -= k*mang[index];
            total+= k;
        }
        index--;
    }
}

int main(){
    int turn;
    cin >> turn;
    while (turn--){
        cin >> n;
        solve();
        cout << total << endl;
        index = 9;
        total = 0;
    }
    return 0;
}