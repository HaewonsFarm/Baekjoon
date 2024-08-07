#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);

    string word;
    cin >> word;
    int count[26];

    for (char i = 'a'; i <= 'z'; i++) {
        cout << (int)word.find(i) << " ";
    }

    return 0;
}