#include <iostream>

using namespace std;
int mang[100][100];
int input[100][2];
int n;
void init(){
    cin >> n;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0; j < n ; j++)
            mang[i][j] = 0;


    for (int i = 0 ; i < n ; i++)
        for (int j = 0; j < 2 ; j++){
            cin >> input[i][j];
            mang[i][input[i][j]-1] = 1;
        }
}

void exchage(){
    for (int i = 0 ; i < n ; i++){
        for (int j = 0; j < n ; j++){
            cout << mang[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    init();
    exchage();
    return 0;
}