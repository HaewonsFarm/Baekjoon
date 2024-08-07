#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    double sum = 0.0, max = 0.0;
    double arr[1000];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = (arr[i] / max) * 100;
        sum += arr[i];
    }

    cout << (double)(sum / n) << endl;

    return 0;
}