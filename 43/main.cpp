#include <iostream>

using namespace std;

void InsertionSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int x = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > x)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = x;
        cout << "Buoc " << i+1 << ": ";
        for (int m = 0 ; m <= i ; m++){
            cout << a[m] << " "; 
        }
        cout << endl;
	}
}

int main(){
    int n, mang[100];
    cin >> n;
    for (int i = 0 ;  i < n ; i++){
        cin >> mang[i];
    }

    InsertionSort(mang,n);
    return 0;
}