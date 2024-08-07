#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int count[42] = {};

    int n;
    for (int i = 0; i < 10; i++) {
        cin >> n;
        count[n % 42]++;
    }

    int result = 0;

    for (int n : count) {
        if (n > 0) {
            result++;
        }
    }

    cout << result;

    return 0;
}