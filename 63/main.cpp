#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int priority(char x){
    if (x == '+' || x == '-') return 1;
    else if (x == '*' || x == '/') return 2;
    else return 0;
}


void exchange(char data[], char result[], int &c){
    stack<char> s;
    s.push('(');
    int length = strlen(data);
    data[length] = ')';
    data[length+1] = '\0';
    char tmp;
    int bol = 0;
    for (int i = 0 ; i < strlen(data) ; i++){
        if (data[i] >= '0' && data[i] <= '9'){
            result[c++] = data[i]; 
        }
        else if (data[i] == ')'){
            tmp = s.top();
            s.pop();
            while ( tmp != '('){
                result[c++] = tmp;
                tmp = s.top();
                s.pop();    
            }
        }
        else{
            if (data[i] == '('){
                s.push('(');
            }
            else{
                while (priority(data[i]) <= priority(s.top()) && !s.empty()){
                    result[c++] = s.top();
                    s.pop();                    
                }
                s.push(data[i]);
            }
        }
    }
    result[c] = '\0';
    for (int i = 0 ; i < c ; i++){
        cout << result[i];
    }
    cout << endl;
}

void solve(char x[]){
    stack<int> s;
    for (int i = 0 ; i < strlen(x); i++){
        if (x[i] >= '0' && x[i] <= '9'){
            s.push(x[i] - '0');
        }
        else{
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            switch (x[i])
            {
            case '+':
                s.push(a+b);
                break;
            case '-':
                s.push(b-a);
                break;
            case '*':
                s.push(a*b);
                break;
            case '/':
                s.push(b/a);
                break;
            default:
                break;
            }
        }
    }
    cout << s.top() << endl;
}
int main(){
    char x[1000] = "6*3+2-(6-4/2)";
    char result[1000];
    int c =0;
    int turn;
    cin >> turn;
    while (turn--){
        cin >> x;
        exchange(x,result,c);
        solve(result);
        c = 0;
    }
    return 0;
}