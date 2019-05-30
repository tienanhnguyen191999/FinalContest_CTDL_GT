#include <iostream> 
#include <stack>
using namespace std;

int input[1000][2]= {{1,2},{1,4},{2,3},{3,4},{5,6},{5,7},{6,8},{7,8}},v=8,e=8,u = 1;
int mang[1000][1000],cx[1000];
void init(){
    //cin >> v >> e;
    //for (int i = 0 ; i < e ;i++) cin >> input[i][0] >> input[i][1];

    for (int i = 0; i < v ; i++)
        for (int j = 0 ; j < v ; j++) mang[i][j] = 0;

    for (int i = 0 ; i < e ; i ++) 
    {
        mang[input[i][0]-1][input[i][1]-1] = 1;
        mang[input[i][1]-1][input[i][0]-1] = 1;
    }

    for (int j = 0 ; j < v ;j++) cx[j] = 1;
}

void hienthi(){
    for (int i = 0 ; i < v ; i++){
        for (int j = 0 ; j < v ;j++){
            cout << mang[i][j] << " ";
        }
        cout << endl;
    }
}
void dfs(){
    stack<int> s;
    int tp;
    s.push(u);
    cx[u] = 0;
    cout << u+1 << " ";
    while (!s.empty()){
        tp = s.top();
        s.pop();
        for (int i = 0 ; i < v ; i++){
            if (mang[tp][i] == 1 && cx[i]){
                cout << i + 1<< " ";
                s.push(tp);
                s.push(i);
                cx[i] = 0;
                break;
            }
        }
    }
}

int check(){
    for(int i = 0; i < v ; i++){
        if (cx[i] == 1){
            return i;
        }
    }
    return -1;
}
void soTPLT(){
    int c =0 ;
    u = check();
    while (u != -1){
        c++;
        dfs();
        u = check();
        cout << endl;
    }
    cout << c;
}
int main(){
    init();
    hienthi();
    soTPLT();
    return 0;
}