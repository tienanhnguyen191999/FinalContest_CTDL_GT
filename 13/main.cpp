#include <iostream>
#include <cstring>
using namespace std;
// Trầu bò: Tìm full hoán vị => min
int cx[100],n = 5,minn =100000;
char mang[10][30] = {"ABC","ABEF","DEF","ABCDE","FGH"};
char save[10][30];
void init(){
    for (int i = 0 ; i < n ; i++){
        cx[i] = 1;
    }
}
void solve(){
    int c = 0;
    for (int i = 0 ; i < n-1 ; i++){
        for (int j = 0 ; j < strlen(save[i]); j++){
            for (int m = 0; m < strlen(save[i+1]); m++){
                if (save[i][j] == save[i+1][m]){
                    c++;
                    break;
                }
            }
            if (c >= minn) return;
        }
    }
    //cout <<  c;
    minn = c;
}
void hoanvi(int h){
    for (int i = 0 ; i < n ; i++){
        if (cx[i]){
            cx[i] = 0;
            strcpy(save[h],mang[i]);
            if ( h == n-1 ){
                solve();
            }
            else{
                hoanvi(h+1);
            }
            cx[i] = 1;
        }
    }
}

void nhap(){
    cin >> n;
    for (int i = 0 ; i < n; i++){
        fflush(stdin);
        cin >> mang[i];
    }
}
int main(){
    nhap();
    init();
    hoanvi(0);
    cout << minn;
    return 0;
}