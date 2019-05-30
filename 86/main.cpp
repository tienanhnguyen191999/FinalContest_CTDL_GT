#include <iostream>
#include <cstring>
using namespace std;

char x[1000] = "0";
int k = 0;
void sinh(){
    for (int i = strlen(x) - 1; i >=0 ;i--){
        if (x[i] == '0'){
            x[i] = '1';
            return;
        }
        else{
            x[i] = '0';
        }
    }

    char tmp[1000];
    tmp[0] = '1';
    for (int i  = 1; i <= strlen(x); i++){
        tmp[i] = '0';
    }
    tmp[strlen(x) + 1] = '\0';
    strcpy(x,tmp);
}

int check(){
    if (atoi(x) % k == 0) return 1;
    else return 0;
}

int main(){
    int turn;
    cin >> turn;
    while (turn--){
        cin >> k;
        x[0] = '1';
        x[1] = '\0';
        while (!check()){
        //cout << x << endl;
            sinh();
        }
        cout << x << endl;
    }
    return 0;
}