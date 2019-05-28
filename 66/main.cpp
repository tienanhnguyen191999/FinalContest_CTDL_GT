// Coded by Dung Bui T1k28
#include <bits/stdc++.h>
 
using namespace std;
 
#define oo 1005
#define FOR(i,a,b) for(int i=a;i<=b;i++)  
#define res(i,j) (R[j]-L[j]+1)*H[i][j];
 
int m,n, H[oo][oo],x, maxx=0, L[oo], R[oo], D[oo], top;
 
int main() {
	// your code goes here
	cin>>m>>n;
	FOR(i,0,n) H[0][i]=0;
	FOR(i,1,m)
		FOR(j,1,n){
			cin>>x;
			H[i][j]=(x)? H[i-1][j]+1 : 0;
		}
	FOR(i,1,m){
		D[0] = 0;
		FOR(j,1,n){
    		while (top > 0 && H[i][D[top]] >= H[i][j]) R[D[top--]] = j-1;
    		L[j] = D[top] + 1;
    		D[++top] = j;
		}
		while (top > 0) R[D[top--]] = n;
		FOR(j,1,n) 
		   if (H[i][j]!=0){
		   		maxx=max(maxx,(R[j]-L[j]+1)*H[i][j]);	
		   }
	}
	cout<<maxx;
	return 0;
}