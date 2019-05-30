#include <iostream>
#include <queue>
using namespace std;
int input[1000][2], mang[1000][1000];
int v, e, u, k, cx[10000];

void init()
{
    cin >> v >> e >> u >> k;
    for (int i = 0; i < e; i++)
        cin >> input[i][0] >> input[i][1];
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            mang[i][j] = 0;

    for (int i = 0; i < e; i++)
    {
        mang[input[i][0] - 1][input[i][1] - 1] = 1;
        mang[input[i][1] - 1][input[i][0] - 1] = 1;
    }
    for (int i = 0; i < v; i++)
        cx[i] = 1;
}

void hienthi()
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << mang[i][j] << " ";
        }
        cout << endl;
    }
}
void bfs()
{
    queue<int> s;
    int c = 0,bol=0;
    s.push(u - 1);
    cx[u - 1] = 0;
    while (!s.empty())
    {
        int tp = s.front();
        s.pop();
        for (int i = 0; i < v; i++)
        {
            if (mang[tp][i] && cx[i])
            {
                if (!bol){
                    c++;
                    bol = 1;
                }
                if ( i + 1 == k){
                    cout << c << endl; return;
                }
                s.push(i);
                cx[i] = 0;
            }
        }
        bol = 0;
    }
    cout << "-1" << endl;
}

int main()
{
    init();
    //hienthi();
    bfs();
    return 0;
}