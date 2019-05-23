#include <iostream> 
using namespace std;

int mang[10][10],n = 8,save[10],total = 0;
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
void hienthi(){
    for (int i = 0 ; i < n ; i++){
        cout << save[i] + 1 << " ";
    }
    cout << endl;
}
void tryy(int h){
    for (int i = 0 ; i < n ; i++){
        if ( cxc[i] && cxch[n+h-i] && cxcs[h+i]){
            cxc[i] = 0;
            cxch[n+h-i] = 0;
            cxcs[h+i] = 0;
            save[h] = i; 
            if (h == n-1){
                total++;
                //hienthi();
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
    cin >> n;
    init();
    tryy(0);
    cout << total;
    return 0;
} 