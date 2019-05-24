#include <iostream>

using namespace std;
int input[100][100] = { 
                        {1,2,3},
                        {4,8,2},
                        {1,5,3},
                        };
int h = 3, c = 3,minn = 110;
int baitx = 3, baity = 2;
int s = 1;
int cx[100][100] = { {0,1,1},
                     {1,1,1},
                     {1,1,1}
                    };
void searchh(int x, int y){
    if ( x == baitx -1 && y == baity - 1){
        // code
        //cout << s << endl;
        if (s < minn) minn = s;
        return;
    }
    if ( y != 0 && cx[x][y-1]){  
        //cout << "LEFT\n";
        cx[x][y-1] = 0;
        s+= input[x][y-1];
        searchh(x,y-1);
        s-= input[x][y-1];
        cx[x][y-1] = 1;
    // left 
    }
    if ( y != c -1 && cx[x][y+1]) {
        //cout << "RIGHT\n";
        cx[x][y+1] = 0;
        s+= input[x][y+1];
        searchh(x,y+1); // right 
        s-= input[x][y+1];
        cx[x][y+1] = 1;
    }
    if ( x != h -1 && cx[x+1][y]) {
        //cout << "DOWN\n";
        cx[x+1][y] = 0;
        s+= input[x+1][y];
        searchh(x+1,y); // down 
        s-= input[x+1][y];    
        cx[x+1][y] = 1;
    }
    if ( y != 0 && x != 0 && cx[x+1][y-1]) {
        //cout << "DOWN-LEFT\n";
        cx[x+1][y-1] = 0;
        s+= input[x+1][y-1];
        searchh(x+1,y-1);     // down-left
        s-= input[x+1][y-1];
        cx[x+1][y-1] = 1;
    }
    if ( y != c -1 && x != h-1 && cx[x][y+1]) {
        //cout << "DOWN-RIGHT\n";
        cx[x+1][y+1] = 0;
        s+= input[x+1][y+1];
        searchh(x+1,y+1); // down-right
        s-= input[x+1][y+1];
        cx[x+1][y+1] = 1;
    }
}
int main(){
    int turn;
    cin >> turn;
    while (turn--){
        cin >> baitx >> baity;
        searchh(0,0);
        cout << minn;
    }
    return 0;
}