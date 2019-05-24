#include <iostream>

using namespace std;
int n,k,s=0,save[100],c=0;
void hienthi(int h){
    for (int i = 0 ; i  <= h ;  i++){
        cout << save[i];
    }
    cout << endl;
}
// Phương pháp đệ quy (giới hạn n < 40)
void tryy(){
    for (int i = 1; i <= k; i++){
        if ( s <= n){
            s+= i;
            if (s == n){
                c++;
                //hienthi(h);
            }
            else{
                tryy();
            }
            s-=i;
        }
    }
}
// Phương pháp QHĐ
int main(){
    n = 10, k = 2;
    tryy();
    cout << c;
    return 0;
}