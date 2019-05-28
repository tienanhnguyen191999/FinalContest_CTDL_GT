#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

char x[1000] = "abc/-ak/l-*";

void init(){
    cin >> x;
}

void solve(){
    stack<char> s;
    char  result[1000];
    int c =0,save = 0,m=0;
    for (int i = strlen(x) -1; i >= 0 ; i--){
        if (x[i] >= 'a' && x[i] <= 'z'){
            result[m++] = x[i]; 
            c++;
            if (c == 2){
                result[m++] = s.top();
                s.pop();
                if (save == 1){
                   result[m++] = s.top();
                    s.pop(); 
                    save = 0;
                }
            }
        }
        else{
            s.push(x[i]);
            if (c == 1) save = 1;
            c = 0;
        }
    }
    while (!s.empty()) {
        result[m++] = s.top();
        s.pop(); 
    }
    for (int i = strlen(result) - 1; i >= 0; i--){
        cout << result[i];
    }
    cout << endl;

}
int main(){
    int turn = 1;
    cin >> turn;
    while (turn--){
        init();
        solve();
    }
    return 0;
}