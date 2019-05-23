#include <iostream>

using namespace std;
int mang[100][100] = {{2,4,3},
                      {1,3,6},
                      {4,2,4}};
int n,k,cx[100],s=0,save[100],luu[100][100];
int total = 0;
void init (){
    for (int i = 0 ; i < n ; i++){
        cx[i] = 1;
    }
}
void hienthi(int h){
    for (int i = 0; i < n ; i++){
        cout << luu[h][i]+1 << " ";
    }
    cout << endl;
}
void backtrack(int h){
    for (int i = 0 ; i < n ; i++){
        if (cx[i]){
            cx[i] = 0;
            s+= mang[h][i];
            save[h] = i;
            if (s > k);
            else if (h == n-1){
                if (s == k){
                    for(int i = 0 ; i<n ;i++){
                        luu[total][i] = save[i]; 
                    }
                    total++;
                }
            }
            else{
                backtrack(h+1);
            }
            cx[i] = 1;
            s-=mang[h][i];
        }
    }
}

int main(){
    n = 3;
    k = 10;
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            cin >> mang[i][j];
        }
    }
    init();
    backtrack(0);
    cout << total << endl;
    for (int i = 0 ; i < total ; i++){
        hienthi(i);
    }
    return 0;
}