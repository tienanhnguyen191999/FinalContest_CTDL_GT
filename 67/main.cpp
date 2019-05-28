#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int c = 1;
char x[1000];

void init(){
    cin >> x;
}

void solve(){
    stack<int>s;
    for (int i = 0 ; i < strlen(x) ; i++){
        if ( x[i] == '('){
            cout << c << " ";
            s.push(c++);
        }
        else if (x[i] == ')')
        {
            cout << s.top() << " "; 
            s.pop();
        }
    }
    cout << endl;
}
int main(){
    int turn;
    cin >> turn;
    while (turn--){
        init();
        solve();
        c = 1;
    }
    return 0;
}