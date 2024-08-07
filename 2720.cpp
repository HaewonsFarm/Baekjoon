#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    // 거스름돈은 항상 $5.00 이하
    // 손님이 받는 동전의 개수를 최소화
    // e.g. $1.24 -> 4*0.25 + 2*0.10 + 0*0.05 + 4*0.01

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int change;
        cin >> change;

        cout << change/25 << " " << (change%25)/10
        << " " << ((change%25)%10)/5 << " " << change%5 << endl;
    }

    return 0;
}