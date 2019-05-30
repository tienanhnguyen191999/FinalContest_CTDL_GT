#include <iostream> 
#include <queue>
using namespace std;

int input[1000][2],v,e,u ;
int mang[1000][1000],cx[1000];
void init(){
    cin >> v >> e >> u;
    for (int i = 0 ; i < e ; i++) cin >> input[i][0] >> input[i][1];

    for (int i = 0 ;  i < v; i++)
        for (int j = 0 ; j < v ; j++) mang[i][j] = 0;
    
    for (int i = 0 ;i < e; i++){
        mang[input[i][0]-1][input[i][1]-1] = 1;
        mang[input[i][1]-1][input[i][0]-1] = 1;
    }

    for(int i = 0 ; i < v ; i++ ) cx[i] = 1;
}

void hienthi(){
    for (int i = 0 ; i < v ; i++){
        for (int j = 0 ; j < v ;j++){
            cout << mang[i][j] << " ";
        }
        cout << endl;
    }
}
void bfs(){
    queue<int> s;
    int tp;
    s.push(u-1);
    cx[u-1] = 0;
    while (!s.empty()){
        tp = s.front();
        s.pop();
        for (int i = 0 ; i < v ; i++){
            if (mang[tp][i] == 1 && cx[i]){
                cout << tp + 1<< " " << i+1 << endl;
                s.push(i);
                cx[i] = 0;
            }
        }
    }
}

int main(){
    init();
    hienthi();
    bfs();
    return 0;
}