#include <iostream>
using namespace std;
int main() {
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> x;

    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            pos = i;
            break;
        }
    }

    if (pos == -1)
        cout << "Not found";
    else
        cout << "Found at position " << pos + 1;
}
