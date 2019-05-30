#include <iostream>

using namespace std;

int mang[1000][2];
int v,d;
void init(){
    cin >> v >> d;
    for (int i = 0 ; i < d ; i++){
        cin >> mang[i][0] >> mang[i][1];
    }
}

void exchange(){
    for (int i = 0 ; i < v; i++){
        for (int j = 0 ; j < d ; j++){
            if (mang[j][0] == i+1) cout << mang[j][1] << " ";
            else if (mang[j][1] == i+1) cout << mang[j][0] << " ";
        }
        cout << endl;
    }
}
int main(){
    init();
    exchange();
    return 0;
}