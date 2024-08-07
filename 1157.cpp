#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int alphabet[26] = {0};
    int count = 0;
    // 아스키 코드: 대문자 65 ~ 90, 소문자 97 ~ 122

    for (int i = 0; i < s.length(); i++) {
        if (s[i] < 97)
            alphabet[s[i] - 65]++;
        else
            alphabet[s[i] - 97]++;
    }

    int max = 0, max_index = 0;
    for (int i = 0; i < 26; i++) {
        if (max < alphabet[i]) {
            max = alphabet[i];
            max_index = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (max == alphabet[i])
            count++;
    }

    if (count > 1)
        cout << "?";
    else
        cout << (char)(max_index + 65);

    return 0;
}