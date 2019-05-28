#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
int main(){
    deque<int> s;
    int turn,n,k;
    char tmp[100];
    cin >> n;
    while (n--){
        cin >> tmp;
        if (strcmp(tmp,"pushback") == 0){
            cin >> k;
            s.push_back(k);
        }
        else if (strcmp(tmp,"pushfront") == 0){
            cin >> k;
            s.push_front(k);
        }
        else if (strcmp(tmp,"popback") == 0){
            s.pop_back();
        }
        else if (strcmp(tmp,"popfront") == 0){
            s.pop_front();
        }
        else if (strcmp(tmp,"printfront") == 0){
            if (!s.empty()) cout << s.front() << endl;
            else  cout <<  "NONE\n";
        }
        else if (strcmp(tmp,"printback") == 0){
            if (!s.empty()) cout << s.back() << endl;
            else  cout <<  "NONE\n";
        }
    }
    return 0;
}