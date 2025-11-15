#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int start[100], finish[100];
    for (int i = 0; i < n; i++) {
        cin >> start[i] >> finish[i];
    }
    cout << "Selected activities: ";
    cout << "0 ";

    int last = 0;
    for (int i = 1; i < n; i++) {
        if (start[i] >= finish[last]) {
            cout << i << " ";
            last = i;
        }
    }
    return 0;
}
