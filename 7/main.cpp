#include <iostream> 
using namespace std;

int mang[10][10] =  {
                        {1, 2, 3, 4, 5, 6, 7, 8,},
                        {9, 10, 11, 12, 13, 14, 15, 16},
                        {17, 18, 19, 20, 21, 22, 23, 24},
                        {25, 26, 27, 28, 29, 30, 31, 32},
                        {33, 34, 35, 36, 37, 38, 39, 40},
                        {41, 42, 43, 44, 45, 46, 47, 48},
                        {48, 50, 51, 52, 53, 54, 55, 56},
                        {57, 58, 59, 60, 61, 62, 63, 64}
                    };
int n = 8,save[10],maxx = 0;
int cxc[10]; // Chưa xét hàng
int cxcs[20]; // Chưa xét chéo sắc
int cxch[20]; // Chưa xét chéo huyền

void init(){
    for (int i = 0 ;i < n ; i++){
        cxc[i] = 1;
    }
    for (int i = 0 ; i < n*2 ; i++){
        cxcs[i] = 1;
        cxch[i] = 1;
    }
}
void check(){
    int s = 0;
    for (int i = 0 ; i < n ; i++){
        cout << mang[i][save[i]] << " ";
        s += mang[i][save[i]];
    }
    cout << endl;
    if ( s > maxx) maxx = s;
}
void tryy(int h){
    for (int i = 0 ; i < n ; i++){
        if ( cxc[i] && cxch[n+h-i] && cxcs[h+i]){
            cxc[i] = 0;
            cxch[n+h-i] = 0;
            cxcs[h+i] = 0;
            save[h] = i; // Lưu đường đi từ h1 => h8
            if (h == n-1){
                check();
            }
            else{
                tryy(h+1);
            }
            cxc[i] = 1;
            cxch[n+h-i] = 1;
            cxcs[h+i] = 1;
        }
    }
}

int main(){
    int turn;
    cin >> turn;
    while (turn--){
        for (int i = 0 ; i < 8 ; i++){
            for (int j = 0 ; j < 8 ; j++){
                cin >> mang[i][j];
            }
        }
        init();
        tryy(0);
        cout << maxx;
    }
    return 0;
} 