#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
char x[1000] = "((a+b))";


int check1(stack<int> s){
    while (!s.empty()){
        int tmp = s.top();
        s.pop();
        stack<int> clone = s;
        while (!clone.empty()){
            if ( clone.top() > tmp && clone.top() - tmp < 4){
                return 0;
            }
            clone.pop();
        }
    }
    return 1;
}


void solve(){
    stack<int> s;
    int c = 0,tmp;
    for (int i = 0 ; i < strlen(x); i++){
        if (x[i] == '(' ){
            s.push(i);
            c = 0;
        }
        else if (x[i] == ')' ){
            c++;
            if (c == 2){
                if (tmp == s.top() + 1)
                {
                    cout << "YES\n";
                    return;
                }
            }
            tmp = s.top();
            s.pop();
            if ( i - tmp < 4) {
                cout << "YES\n";
                return;
            }
        }
        else{
            c = 0;
        }
    }
    cout << "NO";
}

int main(){
    int turn;
    cin >> turn;
    while (turn--){
        cin >> x;
        solve();
    }
    return 0;
}