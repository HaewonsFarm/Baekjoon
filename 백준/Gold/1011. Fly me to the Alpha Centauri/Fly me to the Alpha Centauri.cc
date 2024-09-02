#include <iostream>
#include <cmath>
using namespace std;

// 이전 작동시기에 k 광년을 이동하였을 경우, k-1, k, k + 1 광년만을 다시 이동할 수 있다.
// e.g. 장치를 처음 작동시킬 경우 -1, 0, 1 광년을 이동할 수 있으나
// 음수 혹은 0 만큼의 거리 이동은 의미가 없으므로 1 광년을 이동할 수 있으며,
// 그 다음에는 0, 1, 2 광년을 이동할 수 있다.
// 여기서 2 광년을 이동한다면 그 다음에는 1, 2, 3 광년을 이동할 수 있다.
// 단, 도착하기 바로 직전의 이동 거리는 반드시 1 광년으로 한다.

// 테스트 케이스 T
// 현재 위치 x, 목표 위치 y (x < y)
// x 로부터 y 까지 정확히 도달하는 데 필요한 최소한의 작동 횟수를 출력한다.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int x, y;
        cin >> x >> y;
        int distance = y - x;

        int max_speed = static_cast<int>(sqrt(distance));  // 최대 속도는 거리의 제곱근에 비례
        int remaining_distance = distance - max_speed * max_speed;

        int move_count = 2 * max_speed - 1;  // 기본 이동 횟수 (속도를 올리는 단계 + 속도를 줄이는 단계)
        if (remaining_distance > 0) {
            move_count += (remaining_distance + max_speed - 1) / max_speed;
        }

        cout << move_count << endl;
    }

    return 0;
}