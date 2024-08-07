#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int row = 1; row <= n; row++) {
        for (int i = 0; i < n - row; i++) {
            cout << " ";
        }
        for (int i = 0; i < row; i++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}