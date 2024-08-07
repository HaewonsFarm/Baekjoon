#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int count = 0;
    bool palindrome=  false;

    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] == s[s.length() - 1 - i])
            continue;
        else
            count++;
    }

    if (count == 0)
        palindrome = true;
    else
        palindrome = false;

    cout << (int)palindrome << endl;

    return 0;
}