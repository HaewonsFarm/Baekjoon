#include <iostream>

using namespace std;

int arr[100][100];  // 전역 변수: 배열을 자동 0으로 초기화
int main() {
    ios_base::sync_with_stdio(false);

    int n, x, y, count = 0;
    cin >> n;

    while(n--) {
        cin >> x >> y;

        for (int i = y; i < y + 10; i++) {
            for (int j = x; j < x + 10; j++) {
                if (!arr[i][j]) {
                    count++;
                    arr[i][j] = 1;
                }
            }
        }
    }

    cout << count;

    return 0;
}