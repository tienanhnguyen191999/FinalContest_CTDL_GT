#include <iostream>
#include <cstring>
using namespace std;

int k,n;

void fibo(){
    char x[100][100];
    strcpy(x[1],"A");
    strcpy(x[2],"B");
    for (int i = 3 ; i <= n;  i++){
        strcpy(x[i],x[i-2]);
        strcat(x[i],x[i-1]);
    }
    cout << x[n][k-1] << endl;
}

int main(){
    int turn;
    cin >> turn;
    while (turn--){
        cin >> n >> k;
        fibo();
    }
    return 0;
}