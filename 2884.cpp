#include <iostream>

using namespace std;

int main()
{
    int H, M;
    cin >> H >> M;
    if (M < 45) {
        M += 15;
        H--;
    } else {
        M -= 45;
    }
    if (H < 0) {
        H = 24 + H;
    }

    cout << H << " " << M << endl;

    return 0;
}