#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);

    int r, t;
    string s;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> r >> s;
        string p = "";
        for (int j = 0; j < s.length(); j++) {
            for (int k = 0; k < r; k++) {
                p += s[j];
            }
        }
        cout << p << endl;
    }

    return 0;
}