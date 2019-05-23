#include <iostream>
#include <cmath>
using namespace std;

void nhap(int &a,int &b){
    cin >> a >> b;
}

void maxx(int &a){
    int tmp = a,n=1;
    double s=0;
    while (a/=10) n++;
    for (int i = 0 ; i < n ;i++){
        if ( tmp%10 == 5){
            s+= 6 * pow(10,i);
        }
        else{
            s+= tmp%10 * pow(10,i);
        }
        tmp/=10;
    }
    a = s;
}

void minn(int &a){
    int tmp = a,n=1;
    double s=0;
    while (a/=10) n++;
    for (int i = 0 ; i < n ;i++){
        if ( tmp%10 == 6){
            s+= 5 * pow(10,i);
        }
        else{
            s+= tmp%10 * pow(10,i);
        }
        tmp/=10;
    }
    a = s;
}
int main(){
    int a = 1235,b = 4125;
    cin >> a >> b;
    minn(a);
    minn(b);
    cout << a+b << " ";
    maxx(a);
    maxx(b);
    cout << a + b<< endl;
    return 0;
}