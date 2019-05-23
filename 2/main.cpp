#include <iostream>
#include <cstring>
using namespace std;

char mang[100];
int k,n,s=0,END = 0;
char save[1000][100];
void check(){
    int c = 0,total=0;
    for (int i = 0 ; i <= n ; i++){
        if (mang[i] == '0' && i != n) c++;
        else{
            if ( c == k ){
                total++;
                if (total >=2 ) return;
            }
            c = 0;
        }
    }
    if (total == 1){
        strcpy(save[s++],mang);
    }
}
void init(){
    for (int i = 0 ; i < n ; i++){
        mang[i] = '0';
    }
}
void sinh(){
    int bol = 0;
    for (int i = n-1 ; i >= 0 ; i--){
        if ( mang[i] == '0'){
            mang[i] = '1';
            bol = 1; 
            break;
        }
        else{       
            mang[i] = '0';
        }
    }
    if (!bol) END = 1;
}

void hienthi(int i){
    for (int j = 0; j < n ; j++){
            if ( save[i][j] == '1') cout << "B";
            else cout << "A";
        }
        cout << endl;
}
int main(){
    cin >> n >> k;
    init();
    while (!END){
        sinh();
        check();
    }
    cout << s << endl;
    for (int i = 0 ; i <  s; i++){
        hienthi(i);
    }
    return 0;
}