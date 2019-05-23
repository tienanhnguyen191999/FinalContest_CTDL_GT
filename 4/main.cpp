#include <iostream>

using namespace std;

int n = 3,k=10;
int mang[100][100] = { {2,4,3},
                       {1,3,6},
                       {4,2,4}};

void solve(){
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            for (int m = 0 ; m < n ; m++)
            {
                if (mang[0][i] + mang[1][j] + mang[2][m] == 10){
                        cout << i + 1 << j + 1  << m + 1<< endl;
                }
            }
        }
    }

    for (int i = 0 ; i < n; i++){
        
    }
}
int main(){
    solve();
    return 0;
}