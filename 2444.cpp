#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);

    int n, k = 1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = n - i - 1; j > 0; j--) {
            cout << " ";
        }

        for (int j = 2*i + 1; j > 0; j--) {
            cout << "*";
        }

        cout << endl;
    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j < n - i + 1; j++) {
            cout << " ";
        }

        for (int j = 2*i - 1; j > 0; j--) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}