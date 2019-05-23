#include <iostream>
using namespace std;
int save[1000],index = 0,l,r;
void cutt(int n){
    if (n == 0 || n == 1) save[index++] = n;
    else{
        cutt(n/2);
        cutt(n%2);
        cutt(n/2);
    }
}

int main(){
    int turn, n,c;
    cin >> turn;
    while (turn--){
        cin >> n >> l >> r;
        cutt(n);
        c = 0;
        for (int i = l ; i <= r ; i++){
            if (save[i] == 1) c++;
        }
        cout << c << endl;
    }
    return 0;
}