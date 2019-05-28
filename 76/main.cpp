#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int main(){
    queue<int> s;
    int turn,n,k;
    char tmp[100];
    cin >> n;
    while (n--){
        cin >> tmp;
        if (strcmp(tmp,"push") == 0){
            cin >> k;
            s.push(k);
        }
        else if (strcmp(tmp,"pop") == 0){
            s.pop();
        }
        else{
            if (s.empty) cout << "NONE\n";
            else cout << s.front() << endl;
        }
    }
    return 0;
}