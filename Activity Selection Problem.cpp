#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Activity {
    int start, end;
};
bool sortByEnd(Activity a, Activity b) {
    return a.end < b.end;}
int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    vector<Activity> act(n);
    cout << "Enter start and end times:\n";
    for (int i = 0; i < n; i++) {
        cin >> act[i].start >> act[i].end;
    }
    sort(act.begin(), act.end(), sortByEnd);
    cout << "\nSelected activities:\n";
    cout << "(" << act[0].start << ", " << act[0].end << ")\n";
    int lastEnd = act[0].end;
    for (int i = 1; i < n; i++) {
        if (act[i].start >= lastEnd) {
            cout << "(" << act[i].start << ", " << act[i].end << ")\n";
            lastEnd = act[i].end;
        }
    }

    return 0;}
