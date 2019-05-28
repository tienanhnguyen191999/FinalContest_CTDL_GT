#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
char x[10000] = "0";
int k;
void sinh(){
    int bol = 0;
    for (int i = strlen(x) - 1 ; i >=0  ; i--){
        if (x[i] == '1'){
            x[i] = '0';
        }
        else{
            x[i] = '1';
            bol = 1;
            break;
        }
    }
    //cout << x << endl;
    if (!bol){
        char tmp[1000];
        int length = strlen(x);
        tmp[0] = '1';
        for (int i = 1; i <= strlen(x); i++){
            tmp[i] = '0';
        }
        tmp[length+1] = '\0';
        strcpy(x,tmp);
    }
}

int mu(int coso,int somu){
    int s = 1;
    for(int i = 0 ; i < somu; i++){
        s*= coso;
    }
    return s;
}
int check(){
    int s = 0;
    for (int i = 0 ; i < strlen(x) ;i++){
        s+= (x[i] -'0') * mu(2,strlen(x) - i - 1);
    }
    if ((int)s == k) return 1;
    else return 0;
}
int main(){
    int turn;
    cin >> turn;
    while(turn--){
        x[0] = '0';
        x[1] = '\0';
        cin >> k;
        while (!check()){
            sinh();
            cout << x <<  " ";
        }
        cout << endl;
    }
    return 0;
}