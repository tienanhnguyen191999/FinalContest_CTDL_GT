#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

void solve(char x[]){
    stack<char> s;
    for (int i = 0 ; i < strlen(x) ; i++){
        if (x[i] == '(' || x[i] == '[' || x[i] == '{' ){
            s.push(x[i]);
        }
        else{
            switch(x[i]){
                case ')':
                    if (s.top() != '('){
                    cout << "NO";
                    return;
                    }
                    break;
                case '}':
                    if (s.top() != '{'){
                    cout << "NO";
                    return;
                    }
                    break;
                case ']':
                    if (s.top() != '['){
                    cout << "NO";
                    return;
                    }
                    break;
            }
            s.pop();
        }
    }
    if (!s.empty()){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}
int main(){
    char tmp[1000];
    cin >> tmp;
    solve(tmp);
    return 0;
}