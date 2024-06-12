#include <iostream>
using namespace std;
void binarysearch(int arr[], int n, int key)
{
    int mid;
    int beg = 0;
    int end = n - 1;
    while (beg <= end)
    {
        mid = int((beg + end) / 2);
        if (arr[mid] == key)
        {
            cout << "element found at LOC " << mid;
            break;
        }
        if (arr[mid] < key)
            beg = mid + 1;
        else
            end = mid - 1;
    }
    if (beg > end)
        cout << "element not found";
}
int main()
{
    int arr[40];
    int n, key;
    cout << "Enter the no of elements in array" << endl;
    cin >> n;
    cout << "Enter the elements in ascending order" << endl;
    for (int j = 0; j < n; j++)
        cin >> arr[j];
    cout << "Enter the element to search" << endl;
    cin >> key;
    binarysearch(arr, n, key);
    return 0;
}