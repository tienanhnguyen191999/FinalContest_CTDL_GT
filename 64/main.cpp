#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
queue<int>  s;
int n;

void init(){
    int tmp;
    cin >> n ;
    while (n--){
        cin >> tmp ;
        s.push(tmp);
    }
}

void hienthi(){
    while (!s.empty()){
        cout << s.front();
        s.pop();
    }
}

void solve(){
    queue<int> tmp;
    int x,flag = 0;
    while (!s.empty()){
        x = s.front();
        s.pop();
        tmp = s;
        flag = 0;
        while( !tmp.empty()){
            int y = tmp.front();
            tmp.pop();
            if (y > x){
                cout << y << " ";
                flag = 1;
                break;
            }
        }
        if (!flag) cout << "-1 ";
    }
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