#include <iostream>
using namespace std;
int main() {
    string text, pat;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pat;
    int n = text.size();
    int m = pat.size();
    int ph = 0, th = 0;
    for (int i = 0; i < m; i++) {
        ph += pat[i];
        th += text[i];}
    for (int i = 0; i <= n - m; i++) {
        if (ph == th) {
            bool ok = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pat[j]) {
                    ok = false;
                    break;}
            }
            if (ok) {
                cout << "Pattern found at index: " << i << endl;
                return 0;     }
        }
        if (i < n - m) {
            th -= text[i];
            th += text[i + m];}
    }
    cout << "Pattern not found" << endl;
    return 0;}


