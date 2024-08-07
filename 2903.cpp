#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int initial_state = 4;

    for (int i = 0; i < n; i++) {
        initial_state = pow(sqrt(initial_state) + pow(2, i), 2);
    }

    cout << initial_state << endl;
    return 0;
}