#include <iostream>
using namespace std;

int input[500][500] = { 
                        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1}
                    }; 
int luu[500][500];
int h = 6,c = 5,res = 0; // resolution 


void init(){
    cin >> h >> c;
    for (int i = 0; i < h; i++ ){
        for (int j = 0 ; j < c; j++){
            cin >> input[i][j];
            luu[i][j] = 1;
        }
    }
}
int minn (int a,int b, int c){
    int m  = a;
    if ( m > b) m = b;
    if ( m > c ) m = c;
    return m;
}

void solve(){
    res = 0;
    for (int i = 1; i < h ; i++)
    {
        for (int j = 1 ; j < c ; j++)
        {
            // Nếu 3 ô kề = giá trị => tạo vuông 
            if (input[i][j] == 1 && input[i][j] == input[i-1][j] && input[i][j] == input[i-1][j-1] && input[i][j] == input[i][j-1])
                luu[i][j] = minn(luu[i-1][j],luu[i-1][j-1],luu[i][j-1]) + 1;
            if (res < luu[i][j]) res = luu[i][j];
        }
    }
    if (res > 1)cout << res << endl;
    else cout << 0 << endl;
    
}
int main(){
    int turn;
    cin >> turn;
    while(turn--){
        init();
        solve();
    }
    return 0;
}