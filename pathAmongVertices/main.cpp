#include <iostream>
#include <stack>
#include <fstream>
#include <cstring>
using namespace std;
int mang[100][100],v;
int cx[100];
int pre[100];

void path(int u){ // almost same to Dfs
    stack<int> s;
    s.push(u);
    cx[u] = 0;
    while (!s.empty()){
        int top = s.top();
        s.pop();
        for (int i = 0 ; i < v; i++){
            if (mang[top][i] == 1 && cx[i]){
                cout << top + 1 << " ";
                s.push(top);
                s.push(i);
                pre[i] = top;
                cx[i] = 0;
                break;
            }
        }
    }
}

void init(){
    fstream in("data.inp",ios::in);
    in >> v;
    for (int i = 0 ; i < v; i++){
        for (int j = 0 ; j < v ; j++){
            in >> mang[i][j];
        }
    }
    for (int i = 0 ; i < v; i++){
        for (int j = 0 ; j < v; j++){
            cout << mang[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0 ; i < v ; i++) cx[i] = 1;
    for(int i = 0 ; i < v ; i++) pre[i] = 0;
}
void hienthi(){
    for (int i = 0 ; i < v; i++){
        cout << "DINH " << i + 1 << ": ";
        for (int j = i; j != 0; j = pre[j])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(){
    init();
    path(0);
    hienthi();
    return 0;
}