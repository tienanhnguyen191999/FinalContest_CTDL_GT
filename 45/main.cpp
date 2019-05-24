#include <iostream>

using namespace std;
int a[100],n;
void quickSort(int left, int right)
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

void quick_sort()
{
    quickSort(0, n - 1);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    quick_sort();
    for (int i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }
    return 0;
}