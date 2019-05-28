#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
char x[1000] = "*+ab-cd";
//char x[1000] = "*-a/bc-/akl";

void init(){
    cin >> x;
}
void solve(){
    stack<char> s;
    int c = 0;
    for (int i = 0 ; i < strlen(x); i++){
        if (x[i] >= 'a' && x[i] <= 'z'){
            cout << x[i];
            c++;
            if ( c == 2 ) {
                cout << ")";
                if (!s.empty()){
                    cout << s.top();
                    s.pop();
                    c=0;
                }
            }
            else{
                if (!s.empty()){
                    cout << s.top();
                    s.pop();
                }
            }
        }
        else{
            cout << '(';
            s.push(x[i]);
            c = 0; 
        }
    }
    cout << ")\n";
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