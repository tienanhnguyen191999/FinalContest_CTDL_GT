#include <iostream>
#include <cstring>
#include <climits>
using namespace std;


int pre[1000];
int luu[1000];
int cx[1000],V=6;
void init(){
    memset(cx,0,V);
    memset(luu,10000,V);
}

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}
void primMST(int graph[][100]) {
    int parent[V]; // Lưu đỉnh cha của đỉnh V trong cây bao trùm nhỏ nhất
    int key[V];   
    bool mstSet[V];  // Đánh dấu các đỉnh đã được thêm vào tập các đỉnh đã xét

   for (int i = 0; i < V; i++)
      key[i] = INT_MAX, mstSet[i] = false;

   key[0] = 0; 
   parent[0] = -1;

   for (int count = 0; count < V-1; count++) {
      int u = minKey(key, mstSet);
    cout << u << " ";
      mstSet[u] = true;

    for (int v = 0; v < V; v++)
        if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
           parent[v]  = u, key[v] = graph[u][v];
    }
    cout << endl;
    for (int i = 3 ; i!=-1 ; i=parent[i]){
        cout << i + 1  << " " ;
    }
 }
int main(){
//    init();
    int mang[1000][100] = {
                        {0,1,1,0,0,0},
                        {1,0,2,1,1,0},
                        {1,2,0,0,1,1},
                        {0,1,0,0,2,0},
                        {0,1,1,2,0,2},
                        {0,0,1,0,2,0}
                        };
    primMST(mang);
    return 0;
}