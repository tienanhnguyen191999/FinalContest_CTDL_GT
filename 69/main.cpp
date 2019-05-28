#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

char x[1000] = "*-a/bc-/akl";

void init(){
    cin >> x;
}

void solve(){
    stack<char> s;
    int c =0,save = 0;
    for (int i = 0 ; i < strlen(x) ; i++){
        if (x[i] >= 'a' && x[i] <= 'z'){
            cout << x[i];
            c++;
            if (c == 2){
                cout << s.top();
                s.pop();
                if (save == 1){
                    cout << s.top();
                    s.pop();
                    save = 0;
                }
                c = 0;
            }
        }
        else{
            s.push(x[i]);
            if (c == 1) save = 1;
            c = 0;
        }
    }
    while (!s.empty()){
        cout << s.top();
        s.pop();
    }
    cout << endl;
}
int main(){
    int turn;
    cin >> turn;
    while (turn--){
        init();
        solve();
    }
    return 0;
}