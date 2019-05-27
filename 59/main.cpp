#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

void solve(char x[]){
    stack<char> s;
    int c = 0 ;
    for (int i = 0 ; i < strlen(x); i++){
        if (x[i] == '('){
            s.push('(');
            c = 0;
        }
        else{
            if (s.top() == '('){
                s.pop();
            }
            c+=2;
        }
    }
}

int main(){

    return 0;
}