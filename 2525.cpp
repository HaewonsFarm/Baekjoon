#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int H, M, Add;
    cin >> H >> M;
    cin >> Add;

    int m = H * 60 + M + Add;

    if (m >= 24 * 60) {
        m -= 60 * 24;
        cout << m / 60 << " " << m % 60 << endl;
    } else
        cout << m / 60 << " " << m % 60;

    return 0;
}