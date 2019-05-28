#include <iostream>
#include <queue>
using namespace std;



int main(){
    queue<int> s;
    int turn,n,tmp,k;
    cin >> turn;
    while(turn--){
        cin >> n;
        while (n--){
            cin >> tmp;
            switch (tmp)
            {
            case 1:
                cout << s.size() << endl;
                break;
            case 2:
                cout << (s.empty()) ? "YES\n" : "NO\n";
                break;
            case 3:
                cin >> k;
                s.push(k);
                break;
            case 4:
                if (!s.empty())s.pop();
                break;
            case 5:
                cout << s.front() << endl;
                break;
            case 6:
                cout << s.back() << endl;
                break;
            }
        }
    }
    return 0;
}