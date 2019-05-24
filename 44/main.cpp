#include <iostream>

using namespace std;

void bubbleSort(int mang[], int n)
{
    int bol = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0 ; j < n - i; j++){
            if (mang[j] > mang[j+1]) {
                swap(mang[j],mang[j+1]);
                bol = 1;
            }
        }
        if (!bol) return;
        cout << "Buoc " << i+1 << ": ";
        for (int m = 0 ; m < n ; m++){
            cout << mang[m] << " "; 
        }
        cout << endl;
        bol = 0;
	}
}

int main(){
    int n, mang[100];
    cin >> n;
    for (int i = 0 ;  i < n ; i++){
        cin >> mang[i];
    }

    bubbleSort(mang,n);
    return 0;
}