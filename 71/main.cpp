#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
char x[1000] = "ab*c+";
void init(){
    cin >> x;
}

void solve(){
    stack<char> s;
    char result[1000];
    int m =0 ,c = 0;
    for (int i = strlen(x) -1; i >= 0 ; i--){
        if (x[i] >= 'a' && x[i] <= 'z'){
            result[m++] = x[i];
            c++;
            if (c == 2){
                result[m++] =  '(';
                if (!s.empty()){
                    result[m++] = s.top();
                    s.pop();
                    c = 0;
                }
            }
            else{
                if (!s.empty()){
                    result[m++] = s.top();
                    s.pop();
                }              
            }
        } 
        
        else{
            result[m++] = ')';
            s.push(x[i]);
            c = 0;
        }
    }
    result[m++] = '(';
    result[m] = '\0';
    for (int i = strlen(result) - 1;  i >= 0  ; i--){
        cout << result[i];
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