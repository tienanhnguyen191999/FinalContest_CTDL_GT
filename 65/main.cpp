#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
deque<int> s;
int n;
void init(){
    cin >> n;
    int tmp;
    while (n--){
        cin >> tmp;
        s.push_back(tmp);
    }
}

int minn(deque<int> tmp){
    int a = 10000;
    while (!tmp.empty()){
        if ( tmp.back() < a){
            a = tmp.back();
        }
        tmp.pop_back();
    }
    return a;
}
void solve(){
    deque<int> tmp;
    int maxx = 0,square;
    while (!s.empty()){
        tmp = s;
        while (!tmp.empty()){
            square = tmp.size() * minn(tmp);
            if (square > maxx) maxx = square;
            tmp.pop_back();
        }
        s.pop_front();
    }
    cout << maxx;
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