#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;

    bool flag;
    int result = 0;

    while (n--) {
        cin >> s;

        bool used[26] = {false, };
        used[s[0] - 'a'] =  true;
        flag = true;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1])
                continue;
            if (used[s[i] - 'a'])
                flag = false;
            used[s[i] - 'a'] = true;
        }
        if (flag)
            result++;
    }

    cout << result;

    return 0;
}