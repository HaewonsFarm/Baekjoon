#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);

    string s;

    int min = 0;

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A' || s[i] == 'B' || s[i] == 'C')
            min += 2;
        else if (s[i] == 'D' || s[i] == 'E' || s[i] == 'F')
            min += 3;
        else if (s[i] == 'G' || s[i] == 'H' || s[i] == 'I')
            min += 4;
        else if (s[i] == 'J' || s[i] == 'K' || s[i] == 'L')
            min += 5;
        else if (s[i] == 'M' || s[i] == 'N' || s[i] == 'O')
            min += 6;
        else if (s[i] == 'P' || s[i] == 'Q' || s[i] == 'R' || s[i] == 'S')
            min += 7;
        else if (s[i] == 'T' || s[i] == 'U' || s[i] == 'V')
            min += 8;
        else if (s[i] == 'W' || s[i] == 'X' || s[i] == 'Y' || s[i] == 'Z')
            min += 9;
    }

    min += s.length();

    cout << min << endl;

    return 0;
}