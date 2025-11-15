#include <iostream>
using namespace std;
int main() {
    string text = "ababcabcababc";
    string pat = "abc";
    int n = text.size();
    int m = pat.size();
    int ph = 0;
    int th = 0;
    for (int i = 0; i < m; i++) {
        ph += pat[i];
        th += text[i];}
    for (int i = 0; i <= n - m; i++) {
        if (ph == th) {
            bool same = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pat[j]) {
                    same = false;
                    break;
                }
            }
            if (same) cout << "Found at index " << i << endl;
        }
        if (i < n - m) {
            th -= text[i];
            th += text[i + m];
        }
    }
    return 0;
}
