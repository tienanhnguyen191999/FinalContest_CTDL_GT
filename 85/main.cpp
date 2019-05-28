#include <iostream>
#include <cstring>
using namespace std;

char x[1000];
int n;
void sinh(){
    int bol = 0;
    for (int i = strlen(x) - 1; i >= 0 ; i--){
        if (x[i] == '9'){
            x[i] = '0';
        }
        else{
            x[i] = '9';
            return;
        }
    }
    if (!bol){
        char tmp[100];
        tmp[0] = '9';
        int length = strlen(x);
        tmp[length+1] = '\0';
        for (int i = 1 ; i <= strlen(x); i++){
            tmp[i] = '0';
        }
        strcpy(x,tmp);
    }
}

int check(){
   int s = atoi(x);
   if (s % n == 0) return 0;
   else return 1;
}
int main(){
    int turn;
    cin >> turn;
    while (turn--){
        x[0] = '9';
        x[1] = '\0';
        cin >> n;
        while(check()){
            sinh();
        }
        cout << x << endl;
    }
    
    return 0;
}