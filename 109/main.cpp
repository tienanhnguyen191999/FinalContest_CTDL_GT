#include <iostream>
#include <stack>
using namespace std;
int input[1000][2],mang[1000][1000];
int e,v,cx[1000];

void init(){
    cin >> v >> e;
    for(int i = 0;  i < e ; i++) cin >> input[i][0] >> input[i][1];
    
    for (int i = 0  ; i < v ;i++){
        for (int j = 0 ; j < v ; j++){
            mang[i][j] = 0 ;
        }
    }

    for (int i = 0; i < e; i++){
        mang[input[i][0] - 1][input[i][1] - 1] = 1; 
        mang[input[i][1] - 1][input[i][0] - 1] = 1; 
    }

    for (int i = 0 ; i < v ;i++) cx[i] = 1;
}

void dfs(int u){
    stack<int> s;
    s.push(u);
    cx[u] = 0 ;
    while(!s.empty()){
        int tp = s.top();
        s.pop();
        for (int i = 0; i < v ; i++){
            if (mang[tp][i] && cx[i]){
                s.push(tp); 
                s.push(i);
                cx[i] = 0;
                break; 
            }
        }
    }
}

int check(){
    for (int i = 0 ;  i < v;  i++){
        if (cx[i] == 1) return  i;
    }
    return -1;
}
void canhcau(){
    for (int i =0; i < e; i++){
        for (int j = 0 ; j < v; j++) cx[j] = 1;
        cx[input[i][0]-1] = cx[input[i][1]-1] = 0;
        dfs(check());
        // cout <<"cx: " ;
        // for(int i =0 ; i < v; i++) cout << cx[i] << " ";
        // cout << endl;
        if (check() != -1) cout << i + 1 << endl;
    }
}

int main(){
    init();
    canhcau();
    return 0;
}