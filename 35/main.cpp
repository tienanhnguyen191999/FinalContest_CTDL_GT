#include <iostream>
using namespace std;

int gt(int n){
    int s = 1;
    for (int i = 2; i <= n ; i++) s*=i;
    return s;
}

int tohop(int n,int k){
    return gt(n) / (gt(k) * gt(n-k));
}

int main(){
    int turn, n , k;
    cin >> turn;
    while (turn--){
        cin >> n >> k;
        cout << tohop(n,k) << endl;
    }
    return 0;
}