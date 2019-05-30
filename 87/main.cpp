#include <iostream>

using namespace std;

int minn = 1000,c = 0,bol = 0;
int minn2 = 1000,c2 = 0,bol2 = 0;
void tryy(int s, int t){
    if (!bol){
        if (s  == t){
            if (minn > c) minn = c;
            bol = 1;
        }
        else if  (s <= t+1){
            s*=2;
            c++;
            cout << "(*)" << s << endl;
            tryy(s,t);
            c--;
            s/=2;

            s-=1;
            c++;
            cout << "(+)" << s <<endl;
            tryy(s,t);
            s+=1;
            c--;
        }
    }
}


void tryy2(int s, int t){
    if (!bol2){
        if (s  == t){
            if (minn2 > c2) minn2 = c2;
            bol2 = 1;
        }
        else if  (s <= t+1 && s > 0){
            s-=1;
            c2++;
            cout << "(+)" << s <<endl;
            tryy2(s,t);
            s+=1;
            c2--;

            s*=2;
            c2++;
            cout << "(*)" << s << endl;
            tryy2(s,t);
            c2--;
            s/=2;
        }
    }
}
int main(){
    tryy(3,7);
    cout << "Min1: "<< minn << endl;
    tryy2(3,7);
    cout << "Min2: "<< minn2 << endl;
    return 0;
}