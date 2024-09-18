#include <iostream>
#include <cmath>
using namespace std;

// 크기가 2^N * 2^N 인 2차원 배열을 Z모양으로 탐색
// N > 1인 경우, 배열을 크기가 2^(N-1) * 2^(N-1)로 4등분 한 후에 재귀적으로
// 순서대로 방문.

int n, r, c, res;

void dnc(int x, int y, int n) {
  // Precondition: When divided to 1*1.
  if (n == 1) {
    if (x == r && y == c) {
      cout << res << endl;
    }
    res++;
    return;
  }

  int half = n / 2;

  // quadrant 1
  if (r < x + half && c < y + half) {
    dnc(x, y, half);
  }
  // quadrant 2
  else if (r < x + half && c >= y + half) {
    res += half * half;
    dnc(x, y + half, half);
  }
  // quadrant 3
  else if (r >= x + half && c < y + half) {
    res += 2 * half * half;
    dnc(x + half, y, half);
  }
  // quadrant 4
  else {
    res += 3 * half * half;
    dnc(x + half, y + half, half);
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;

    dnc(0, 0, pow(2, n));

    return 0;
}