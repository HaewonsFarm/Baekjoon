#include <iostream>
using namespace std;

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int left = x;
    int right = w - x;
    int bottom = y;
    int top = h - y;

    int minDistance = min(min(left, right), min(bottom, top));

    cout << minDistance << endl;

    return 0;
}