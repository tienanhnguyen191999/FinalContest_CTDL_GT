#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
char save[100];
int STOP = 0;
int n = 1;


void genBinary (){
    int bol = 0;
    for (int i = strlen(save)-1 ; i >= 0; i--){
        if (save[i] == '1'){
            save[i] = '0';
        }
        else{
            save[i] = '1';
            bol = 1;
            break;
        }
    }
    if (!bol) STOP = 1;
}
void init(){
    for (int i = 0 ; i < n ; i++){
        save[i] = '0';
    }
}
void hienthi(){
    int s = 0;
    for (int i = 0 ; i < strlen(save) ; i++){
        if (save[i] == '1'){
            cout << " += " << 9 * pow(10,strlen(save)-i-1) <<" ";
            s += 9 * pow(10,strlen(save)-i-1);    
        }
    }
    cout << s <<  endl;
}
void getall(){
    while ( n < 8){
        init();
        while ( !STOP ){
            genBinary();
            hienthi(); // solve here
        }
        STOP = 0;
        n++;
    }
}
int main(){
    getall();
    return 0;
}