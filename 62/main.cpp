#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

// search all bracet (1-8),(4,7),(5,6)
int save[10][2]; // Array save all bracets
int c = 0;
int mang[100];
char x[1000];
void init(){
    stack<int> s;
    for (int i = 0 ; i < strlen(x) ; i++){
        if (x[i] == '(') s.push(i);
        else if ( x[i] == ')'){
            save[c][0] = s.top();
            save[c++][1] = i;
            s.pop();
        }
    }
    int tmp = c - 1;
    for (int i = 0 ; i < c/2; i++){
        swap(save[i],save[tmp--]);
    }
}

int check(int k){
    for (int i = 0 ; i < c; i++){
        if (mang[i] == 1){
            if ( k == save[i][0] || k == save[i][1]){
                return 0;
            }
        }
    }
    return 1;
}

void hienthi(){
    int tmp = 0;
    for (int i = 0 ; i < c ; i++){
        if ( mang[i] == 1) tmp++;
    }
    if (tmp < 1) return; 
    for (int i = 0 ; i < strlen(x); i++){
        if ( x[i] == '('  || x[i] == ')'){
            if (check(i)) cout << x[i];
        }
        else cout << x[i];
    }
    cout << endl;
}

void tryy(int m){
    for (int i = 0 ; i <= 1 ; i++){
        mang[m] = i;
        if (m == c - 1){
            hienthi();
        }
        else{
            tryy(m+1);
        }
    }
}

int main(){
    strcpy(x,"(1+(2*(3+4)))");
    init();
    tryy(0);
    return 0;
}