#include <iostream>

using namespace std;
int n,days,store[1000],budget[1000];
void nhap(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> store[i];
    }

    cin >> days;
    for (int i = 0 ; i < days; i++){
        cin >> budget[i];
    }
}

void solve (){
    int c = 0;
    for (int i = 0 ; i < days; i++){
        for (int j = 0 ; j < n; j++){
            if (budget[i] >= store[j]) c++;
        }
        cout << c << endl;
        c = 0;
    }
}
int main(){
    nhap();
    solve();
    return 0;
}