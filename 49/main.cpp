#include <iostream>

using namespace std;
// Vì số lượng lớn phần tử được khai báo  => dùng binary_search
int n = 9,a[100000] = {1,2,3,4,5,6,7,8,9},k; 
void quickSort(int left, int right) // Dùng quick sort để sắp xếp
{
    int i, j;
    int x, y;
    i = left;
    j = right;
    x = a[left];
    do
    {
        while (a[i] < x && i < right)
            i++;
        while (a[j] > x && j > left)
            j--;
        if (i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
        quickSort(left, j);
    if (i < right)
        quickSort(i, right);
}

void binary_search(){
    int l = 0;
    int r = n-1;
    int mid;
    while (l <= r){
        mid = (l+r)/2;
        if ( a[mid] == k ){
            cout << k << endl;
            return;
        }
        else if ( a[mid] > k){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << "NO";
}

int main(){
    int turn;
    cin >> turn;
    while (turn--){
        cin >> n >> k;
        for (int i = 0 ; i < n ;i++) cin >> a[i];
        quickSort(0, n - 1);
        binary_search();
    }
    return 0;
}