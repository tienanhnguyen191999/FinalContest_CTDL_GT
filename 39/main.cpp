#include <iostream>

using namespace std;
int n,k,save[100],s=0,c=0;
void init(){
    cin >> n >> k;
}



void solve(int d){
    for (int i = 0; i <= k ; i++){
        if ( s <= k){
            if (i == 0 && d == 0) continue;
                s += i;
                if (d == n-1){
                if (s == k) c++;      
            }
            else solve(d+1);
            s -= i;
        }
    }
}

int main(){
    int turn;
    cin >> turn;
    while (turn--){
        init();
        solve(0);
        cout << c << endl;
        c = s = 0;
    }
    return 0;
}