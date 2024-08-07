#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);

    string s;
    int words = 1;

    getline(cin, s);

    if (s.length() == 1 && s[0] == ' ') {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == ' ')
            words++;
    }

    cout << words;

    return 0;
}