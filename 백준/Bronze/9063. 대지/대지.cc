#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // 거리 계산
    int min[2] = {10000, 10000}, max[2] = {-10000, -10000};
    for (int i = 0; i < n; i++) {
        min[0] = min[0] < x[i] ? min[0] : x[i];
        max[0] = max[0] < x[i] ? x[i] : max[0];

        min[1] = min[1] < y[i] ? min[1] : y[i];
        max[1] = max[1] < y[i] ? y[i] : max[1];
    }

    int dist_x = abs(min[0] - max[0]);
    int dist_y = abs(min[1] - max[1]);

    cout << dist_x * dist_y << '\n';

    return 0;
}