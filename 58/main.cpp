#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int priority(char x ){
    if ( x == '+' || x == '-') return 1;
    else if ( x == '*' || x == '/' ) return 2;
    else if ( x == '^') return 3;
    else return 0; 
}

void exchange(char data[], char result[]){
    stack<char> s;
    int length = strlen(data);
    s.push('(');
    data[length] = ')';
    data[length+1] = '\0';
    int m = 0;
    for (int i = 0 ; i < strlen(data) ;i++){
        if (data[i] >= 'a' && data[i] <= 'z'){
            result[m++] = data[i];
        }
        else if (data[i] == ')'){
            char tmp = s.top();
            s.pop();
            while ( tmp != '('){
                result[m++] = tmp;
                tmp = s.top();
                s.pop();
            }
        }
        else{
            // Dấu ( và +,-,*,/
            if ( data[i] == '('){
                s.push('(');
            }
            else{
                while( priority(data[i]) <= priority(s.top()) && !s.empty()){
                    result[m++] = s.top();
                    s.pop();
                }
                s.push(data [i]);
            }
        }
    }
    result[m] = '\0';
}
int main(){
    int turn;
    cin >> turn;
    char result[1000]; // Biểu thức hậu tố
    char data[1000];
    while (turn--){
        cin >> data;
        exchange(data,result);
        cout << result << endl;
    }
    return 0;
}