#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int priority(char x){
    if (x == '+' || x == '-') return 1;
    else if (x == '*' || x == '/') return 2;
    return 0;
}


void solve(char mang[]){
    stack<char> s;
    s.push('(');
    int length = strlen(mang);
    mang[length] = ')';
    mang[length+1] = '\0';
    for (int i = 0 ; i < strlen(mang) ; i++){
        if ( mang[i] >= 'a' && mang[i] <= 'z'){
            cout << mang[i];
        }
        else if (mang[i] == ')'){
            char tmp = s.top();
            s.pop();
            while ( tmp != '('){
                cout << tmp;
                tmp = s.top();
                s.pop();
            }
        }
        else{
            if (mang[i] == '('){
                s.push('(');
            }
            else{
                while (priority(mang[i]) <= priority(s.top()) && !s.empty()){
                    cout << s.top();
                    s.pop();
                }
                s.push(mang[i]);
            }
        }
    }
    cout << endl;
}
int main(){
    char x[1000] = "(a+(b+c))";
    int turn;
    cin >> turn;
    while (turn--){
        cin >> x;
        solve(x);
    }
    return 0;
}