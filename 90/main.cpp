#include <iostream>

using namespace std;

int mang[1000][2];
int v;
void init(){
    cin >> v ;
    for (int i = 0 ; i < v; i++){
        cin >> mang[i][0] >> mang[i][1];
    }
}

void exchange(){
    for (int i = 0 ; i < v; i++){
        if ( i < mang[i][0] ){
            cout << i + 1<<  " " << mang[i][0] << endl;
        }
         if ( i < mang[i][1] ){
            cout << i + 1<<  " " << mang[i][1] << endl;
        }
    }
}
int main(){
    init();
    exchange();
    return 0;
}