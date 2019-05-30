#include <iostream>

using namespace std;
int mang[100][100];
int n;
void init(){
    cin >> n;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0; j < n ; j++)
            cin >> mang[i][j];
}

void exchage(){
    for (int i = 0 ; i < n ; i++){
        for (int j = 0; j < n ; j++){
            if (mang[i][j] == 1){
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }
}
int main(){
    init();
    exchage();
    return 0;
}