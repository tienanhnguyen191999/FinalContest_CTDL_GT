#include <iostream>

using namespace std;
int th[100],root[100];
int n,k;
void hienthi(){
    for (int i = 1; i <= k ; i++){
        cout << th[i];
    }
    cout << endl;
}
 
int dung=0;
void sinhth () {
    int i=k;
    while (i>0 && th[i]==n-k+i) i--;
    if (i>0) {
        th[i]++;
        for (int j=i+1; j<=k; j++) {
            th[j]=th[i]+j-i;
        }
    } else dung=1;
}

void compare (){
    int c = 0;
    for (int i = 1 ; i <= k  ; i++){
        for (int j = 1 ; j <= k; j++){
            if ( th[i] == root[j]){
                c++;
                break;
            }
        }
    }
    if (c == k) cout << k << endl;
    else   cout << k-c << endl;
}
int main(){
    int turn;
    cin >> turn;
    while (turn--){
        cin >> n >> k;
        for (int i = 1 ; i <= k ; i++){
            cin >> root[i];
            th[i] = root[i];  
        }
        sinhth();
        compare();
    }
    return 0;
}