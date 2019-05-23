#include <iostream>

using namespace std;

typedef struct info{
    int root_index;
    int value;
};
info save[100];
int n,k,a,mang[100];

void init(){
    int tmp = a;
    for (int i = 0 ; i < n ; i++){
        save[n-i-1].value = tmp % 10;
        mang[n-i-1] = tmp % 10;
        save[n-i-1].root_index = n-i-1;
        tmp/=10; 
    }
}

void sapxepgiatri(){
    for (int i = 0 ; i < n ; i++){
        for (int j = i+1 ; j < n; j++)
        {
            if (save[i].value < save[j].value)
            {
                info tmp = save[i];
                save[i] = save[j];
                save[j] =  tmp;
            }
        }
    }
}

void sapxepindex(){
    for (int i = 0 ; i < n ; i++){
        for (int j = i+1 ; j < n; j++)
        {
            if (save[i].root_index > save[j].root_index)
            {
                info tmp = save[i];
                save[i] = save[j];
                save[j] =  tmp;
            }
        }
    }
}

void solve(){
    sapxepgiatri();
    n-=k; // Loại k phần tử có giá trị nhỏ hơn hẳn
    sapxepindex(); // Sắp xếp lại đúng vị trí của số ban đầu
    for (int i = 0 ; i < n ; i++){
        cout << save[i].value ;
    }
    cout << endl;
}
int main(){
    cin >> n >> k >> a;
    init();
    solve();
    return 0;
}