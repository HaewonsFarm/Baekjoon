#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);

    int n, sum = 0;
    string str;
    cin >> n;
    cin >> str;

    for (int i = 0; i < n; i++)
        sum += (int)str[i] - 48;

    cout << sum << endl;

    return 0;
}